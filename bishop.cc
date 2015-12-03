#include "bishop.h"
#include "board.h"
#include <cstdlib>
#include <iostream>

using namespace std;

Bishop::Bishop(int row, int col, int owner, Board *b): Piece(row, col, owner, b) {}

bool Bishop::checkMove(int row1, int col1, int row2, int col2){
	if(row2>7 || row2 <0 || col2>7 || col2 < 0){
		cout << "You are moving off the board!" << endl;
		return false;
	}
	if(b->getPiece(row2, col2)->getOwner() == this->getOwner()){
		cout << "You currently occupy this space." << endl;
		return false;
	} 
	if((row1 == row2) && (col1 == col2)){
		cout << "You haven't moved anywhere." << endl;
		return false;
	}
	
	// now check for a valid bishop movement

	
	if(abs(row1-row2) != abs(col1-col2)){
		cout << "Bishops must move diagonally." << endl;
		return false;
	}

	if((row1 > row2) && (col2 < col1)) { //upwards left
		int i = row1;
		int z = col1;
		
		while(true){
			if((i==row2) && (z==col2)){
				break;
			}
			if(b->isOccupied(i, z) == true){
				return false;
			}
			i--;
			z--;
			}
		}

	else if((row2 > row2) && (col2 < col1)) { //downwards left
		int i = row1;
		int z = col1;
	
		while(true){
			if((i==row2) && (z==col2)){
				break;
			}
			if(b->isOccupied(i, z)){
				return false;
			}
			i++;
			z--;
		}
	}

	else if((row2 < row1) && (col2 > col1)){
		int i = row1;
		int z = col1;

		while(true){
			if((i==row2) && (z==col2)){
				break;
			}
			if(b->isOccupied(i,z)){
				return false;
			}
			i--;
			z++;
		}
	}

	else if((row2 > row1) && (col2 > col1)){
		int i = row1;
		int z = col1;

		while(true){
			if((i==row2) && (z==col2)){
				break;
			}
			if(b->isOccupied(i, z)){
				return false;
			}
			i++;
			z++;
		}
	}
	return true;
}

bool Bishop::makeMove(int row1, int col1, int row2, int col2){
	if(checkMove(row1, col1, row2, col2)){
		this->row = row2;
		this->col = col2;
		return true;
	} else {
		return false;
	}
}

char Bishop::pieceID(){
	if(this->getOwner() == 0){
		return 'B';
	} else {
		return 'b';
	}
}
			
