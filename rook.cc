#include "rook.h"
#include "board.h"
#include <string>
#include <iostream>
#include <cstdlib>

using namespace std;

Rook::Rook(int row, int col,int owner, Board *b): Piece(row,col,owner,b) {}

bool Rook::checkMove(int row1, int col1, int row2, int col2){
	if(row2 < 0 || row2>7 || col2 <0 || col2 > 7){
		cout << "You are moving off the board!" << endl;
		return false;
	}
	if(b->getPiece(row2, col2) !=NULL){
		if(b->getPiece(row2, col2)->getOwner() == this->getOwner()){	
			return false;
		} // attacking your own piece
	}
	if((row1 == row2) && (col1 == col2)){
		return false;
	} // you can't move to the same spot
	
	// now that those cases are checked, check the path of the move

	if((this->getRow() != row2) && (this->getCol() != col2)){
		cout << "Rook can only move forwards and sideways." << endl;
		return false;
	}
	if(this->getRow() == row2){
		if(this->getCol() > col2){
			for(int i = this->getCol(); i > col2; i--){
				if(b->getPiece(row2, i) != NULL){
					cout << "Rook cannot jump over pieces." << endl;
					return false;
				}
			}
		}
		else if (this->getCol() < col2){
			for(int i = this->getCol(); i < col2; i++){
				if(b->getPiece(row2, i) !=NULL){
					cout << "Rook cannot jump over pieces." << endl;
					return false;
				}
			}
		}
	}
	else if(this->getCol() == col2){
		if(this->getRow() > row2){
			for(int i = this->getRow(); i > row2; i--){
				if(b->getPiece(i, col2)!= NULL){
					cout << "Rook cannot jump over pieces." << endl;
					return false;
				}
			}
		}
		else if(this->getRow() < row2){
			for(int i= this->getRow(); i < row2; i++){
				if(b->getPiece(i, col2) !=NULL){
					cout << "Rook cannot jump over pieces." << endl;
					return false;
				}
			}
		}
	}
	return true;
}

bool Rook::makeMove(int row1, int col1, int row2, int col2){
	if(checkMove(row2, col1, row2, col2)){
		this->row = row2;
		this->col = col2;
		return true;
	}
	else {
		return false;
	}
}

char Rook::pieceID(){
	if(this->getOwner() == 0){
		return 'R';
	} else {
		return 'r';
	}
}
