#include "pawn.h"
#include "board.h"
#include <cstdlib>
#include <iostream>

using namespace std;

Pawn::Pawn(int row, int col, int owner, Board *b): Piece(row,col,owner,b) {
	this->firstmove=true;
}

bool Pawn::checkMove(int row1, int col1, int row2, int col2){
	//cout << "checking the move" << endl;
	if(b->getPiece(row2, col2)!=NULL){
		if(b->getPiece(row2, col2)->getOwner() == this->getOwner()){
			return false;
		}
	}
	//cout <<"making sure you are moving" << endl;
	if((row1==row2) && (col1 ==col2)){
		return false;
	}
	//cout << "first move two spaces white" << endl;
	if((this->getOwner() == 0) && ((row1-row2) == 2) && 
		(this->firstmove == true) && (col1 == col2) &&(b->getPiece(row2,col2)==NULL)){
		this->firstmove=false;
		return true;
	}
	//cout << "first move two spaces black" << endl;
	if((this->getOwner() == 1) && ((row2-row1) == 2) &&
		(this->firstmove == true) && (col1==col2 && (b->getPiece(row2, col2) ==NULL))){
		this->firstmove=false;
		return true;
	}
	//cout <<"attacking a piece" << endl;
	if(b->getPiece(row2, col2) !=NULL){
		if((this->getOwner() == 0) && ((row1-row2 == 1) && (abs(col2-col1) == 1))){
			this->firstmove=false;
			return true;
		} else if((this->getOwner() == 1) && ((row2-row1 == 1) && (abs(col2-col1) ==1))){
			this->firstmove=false;
			return true;
		}
	}
	//cout << "white moving forward" << endl;
	if((this->getOwner() ==0) && ((row1-row2) == 1) &&
		(b->getPiece(row2, col2) == NULL) && (col1==col2)){
		this->firstmove=false;
		//cout <<"moving"<<endl;
		return true;
	}
	//cout << "black moving forward" << endl;
	if((this->getOwner() ==1) && ((row2-row1) == 1) &&
		(b->getPiece(row2, col2) == NULL) && (col1==col2)){
		this->firstmove=false;
		return true;
	}
	return false;
}

bool Pawn::makeMove(int row1, int col1, int row2, int col2){
	//cout <<"in make move" << endl;
	if(checkMove(row1, col1, row2, col2)){
		this->row = row2;
		this->col = col2;
		return true;
	} else {
		return false;
	}
}

char Pawn::pieceID(){
	if(this->getOwner() == 0){
		return 'P';
	} else {
		return 'p';
	}
}

