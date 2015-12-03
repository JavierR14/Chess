#include "queen.h"
#include "board.h"
#include <cstdlib>
#include <iostream>

using namespace std;

Queen::Queen(int row, int col, int owner, Board *b): Piece(row, col, owner, b) {}

bool Queen::checkMove(int row1, int col1, int row2, int col2){
	if(b->getPiece(row2, col2) !=NULL){
		if(b->getPiece(row2, col2)->getOwner() == this->getOwner()){
			//cout << "You currently occupy this space." << endl;
			return false;
		}
	} 
	if((row1 == row2) && (col1 == col2)){
		//cout << "You haven't moved anywhere." << endl;
		return false;
	}
	
	// now check for a valid bishop movement

	if(row1 == row2){
		if(col1 > col2){
			for(int i=col1-1; i > col2; i--){
				if(b->getPiece(row2, i) !=NULL){
					//cout << "Queen cannot jump over pieces." << endl;
					return false;
				}
			}
		}
		else if(col1 < col2){
			for(int i=col1+1; i<col2; i++){
				if(b->getPiece(row2, i) !=NULL){
					//cout << "Queen cannot jump over pieces." << endl;
					return false;
				}
			}
		}
	} else if(col1 == col2){
		if(row1 > row2){
			for(int i=row1-1; i>row2; i--){
				if(b->getPiece(i, col2) !=NULL){
					//cout << "Queen cannot jump over pieces." << endl;
					return false;
				}
			}
		}
		else if(row1 < row2){
			for(int i=row1+1; i<row2; i++){
				if(b->getPiece(i, col2) !=NULL){
				//	cout << "Queen cannot jump over pieces." << endl;
					return false;
				}
			}
		}
	}
	if((row1 > row2) && (col2 < col1)) { //upwards left
		int i = row1;
		int z = col1;
		
		while(true){
			if((i==row2) && (z==col2)){
				break;
			}
			if(b->getPiece(i, z) !=NULL){
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
			if(b->getPiece(i, z)!=NULL){
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
			if(b->getPiece(i, z)!=NULL){
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
			if(b->getPiece(i, z)!=NULL){
				return false;
			}
			i++;
			z++;
		}
	}
	return true;
}

bool Queen::makeMove(int row1, int col1, int row2, int col2){
	if(checkMove(row1, col1, row2, col2)){
		this->row = row2;
		this->col = col2;
		return true;
	} else {
		return false;
	}
}

char Queen::pieceID(){
	if(this->getOwner() == 0){
		return 'Q';
	} else {
		return 'q';
	}
}			
