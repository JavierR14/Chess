#include "rook.h"
#include "board.h"
#include <string>
#include <iostream>
#include <cstdlib>

using namespace std;

Rook::Rook(int row, int col,int owner, Board *b): Piece(row,col,owner,b) {}

bool Rook::checkMove(int row1, int col1, int row2, int col2){
	if(row2 < 0 || row2>7 || col2 <0 || col2 > 7){
	//	cout << "You are moving off the board!" << endl;
		return false;
	}
	//cout << "valid" << endl;
	if(b->getPiece(row2, col2) !=NULL){
		if(b->getPiece(row2, col2)->getOwner() == this->getOwner()){	
			return false;
		} // attacking your own piece
	}
	//cout << "not attacking own piece" << endl;
	//cout << row1 << row2 << col1 << col2 << endl;
	if((row1 == row2) && (col1 == col2)){
		cout << "YO" << endl;
		return false;
	} // you can't move to the same spot
	
	// now that those cases are checked, check the path of the move
	//cout << "moving somewhere" << endl;
	if((row1 != row2) && (col1 != col2)){
		//cout << "Rook can only move forwards and sideways." << endl;
		return false;
	}
	//cout << "making rook move" << endl;
	if(row1 == row2){
	//	cout << "moving horizontally" << endl;
		if(col1 > col2){
	//		cout << "left" << endl;
			for(int i = col1-1; i > col2; i--){
				if(b->getPiece(row2, i) != NULL){
				//	cout << "Rook cannot jump over pieces." << endl;
					return false;
				}
			}
		}
		else if (col1 < col2){
	//			cout << "right" << endl;
			for(int i = col1+1; i < col2; i++){
				if(b->getPiece(row2, i) !=NULL){
				//	cout << "Rook cannot jump over pieces." << endl;
					return false;
				}
			}
		}
	}
	else if(col1 == col2){
	//	cout << "columns are the same" << endl;
		if(row1 > row2){
	//		cout << "moving upwards" << endl;
			for(int i = row1-1; i > row2; i--){
				cout << i << endl;
				if(b->getPiece(i, col2)!= NULL){
				//	cout << "Rook cannot jump over pieces." << endl;
					return false;
				}
			}
		}
		else if(row1 < row2){
			for(int i= row1+1; i < row2; i++){
				if(b->getPiece(i, col2) !=NULL){
				//	cout << "Rook cannot jump over pieces." << endl;
					return false;
				}
			}
		}
	}
	return true;
}

bool Rook::makeMove(int row1, int col1, int row2, int col2){
	if(checkMove(row1, col1, row2, col2)){
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
