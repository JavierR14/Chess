#include "king.h"
#include "board.h"
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

King::King(int row, int col, int owner, Board *b): Piece(row,col,owner,b) {}

bool King::checkMove(int row1, int col1, int row2, int col2){
	if(row2>7 || row2<0 || col2>7 || col2<0){
		//cout << "You are moving off the board!" << endl;
		return false;
	}
	if(b->getPiece(row2, col2) !=NULL){
		if(b->getPiece(row2, col2)->getOwner() == this->getOwner()){
			return false;
		}
	}
	if((row1==row2) && (col1 == col2)){
		return false;
	}

	// now check for valid king movement

	if((abs(row1-row2) > 1) || (abs(col1-col2) > 1)){
		//cout << "Kings can only move one space." << endl;
		return false;
	}
	if(!(b->getPiece(row2, col2))){
		return true;
	}
	return false;
}

bool King::makeMove(int row1, int col1, int row2, int col2){
	if(checkMove(row1, col1, row2, col2)){
		this->row = row;
		this->col = col;
		return true;
	} else {
		return false;
	}
}
	
char King::pieceID(){
	if(this->getOwner() ==0){
		return 'K';
	} else {
		return 'k';
	}
}

