#include "pawn.h"
#include "board.h"
#include <cstdlib>
#include <iostream>

using namespace std;

Pawn::Pawn(int row, int col, int owner, Board *b): row(row), col(col), owner(owner), b(b) {
	this->firstmove=true;
}

bool Pawn::checkMove(int row1, int col1, int row2, int col2){
	if(b->getPiece(row2, col2)->getOwner == this->getOwner()){
		return false;
	}
	if((row1==row2) && (col1 ==col2)){
		return false;
	}

	if((this->getOwner() == 0) && ((row1-row2) == 2) && 
		(this->firstmove == true) && (col1 == col2) &&(b->getPiece(row2,col2))){
		this->firstmove=false;
		return true;
	}
	if((this->getOwner() == 1) && ((row2-row1) == 2) &&
		(this->firstmove == true) && (col1==col2 && (b->getPiece(row2, col2) ==NULL))){
		this->firstmove=false;
		return true;
	}
	if(b->getPiece(row2, col2)){
		if((this->getOwner() == 0) && ((row1-row2 == 1) && (abs(col2-col1) == 1))){
			return true;
		} else if((this->getOwner() == 1) && ((row2-row1 == 1) && (abs(col2-col1) ==1))){
			return true;
		}
	}
	if((this->getOwner() ==0) && ((row1-row2) == 1) &&
		(b->getPiece(row2, col2) == NULL) && (col1==col2)){
		return true;
	}
	if((this->getOwner() ==1) && ((row2-row2) == 1) &&
		(b->getPiece(row2, col2) == NULL) && (col1==col2)){
		return true;
	}
	return false;
}

bool Pawn::makeMove(int row1, int col1, int row2, int col2){
	if(checkMove(row1, col1, row2, col2)){
		this->row = row2;
		this->col = col2;
		return false;
	} else {
		return true;
	}
}

char Pawn::pieceID(){
	if(this->getOwner() == 0){
		return 'P';
	} else {
		return 'p';
	}
}

