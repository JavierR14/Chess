#include "knight.h"
#include "board.h"
#include <string>
#include <cstdlib>
#include <iostream>

using namespace std;

Knight::Knight(int row, int col, int owner, Board *b): Piece(row, col,owner,b) {}

bool Knight::checkMove(int row1, int col1, int row2, int col2){
	if(b->getPiece(row2, col2)->getOwner() == this->getOwner()){
		cout << "You currently occupy this space." << endl;
		return false;
	} //attacking your own piece
	if((row1 == row2) && (col1 == col2)){
		cout << "You haven't moved anywhere." << endl;
		return false;
	} //you can't move to the same spot
	
	// now check if it is a valid Knight movement

	if((row2 == row1+2) && ((col2 == col1-1) || (col2 == col1+1))){
		return true;
	} else if((row2 == row1+1) && ((col2 == col1-2) || (col2 == col1+2))){
		return true;
	} else if((row2 == row1-1) && ((col2 == col1-2) || (col2 == col1+2))){
		return true;
	} else if((row2 == row1-2) && ((col2 == col1-1) || (col2 == col1+1))){
		return true;
	}
	return false;
}

bool Knight::makeMove(int row1, int col1, int row2, int col2){
	if(checkMove(row1, col1, row2, col2)){
		this->row = row2;
		this->col = col2;
		return true;
	} else {
		return false;
	}
}

char Knight::pieceID(){
	if(this->getOwner() == 0){
		return 'N';
	} else {
		return 'n';
	}
}


