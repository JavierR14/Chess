#include "human.h"
#include "board.h"
#include <cstdlib>
#include <string>
#include <iostream>

using namespace std;

Human::Human(int playerID, Board *b): 
		Player(0, playerID, 0, b, true) {}

bool Human::movePiece(int row1, int col1, int row2, int col2){
	if(b->getPiece(row1, col1)->getOwner() != this->playerID()){
		cout << "You do not own this piece." << endl;
		return false;
	}
	
	if(b->getPiece(row1, col1)->makeMove(row1, col1, row2, col2) == true){
		if((b->getPiece(row1, col1)->pieceID() == 'k') ||
			(b->getPiece(row1, col1)->pieceID() == 'K')){
				this->kingCol = col2;
				this->kingRow = row2;
		}				
		b->updateMove(row1, col1, row2, col2);
		return true;
	}
	return false;
}

bool Human::isCheck(int row, int col){
	for(int i =0; i<8; i++){
		for(int j=0; j<8; j++){
			if(b->theBoard[i][j].getOwner() == this->playerID()){
				if(b->theBoard[i][j].checkMove(i, j, row, col) == true){
					return true;
			}
		}
	}
}
	
bool Human::isCheckmate(int row, int col){
	if(isCheck(row, col) == true){
		int check=0;
		int availMoves =0;
		if(b->theBoard[row][col]->checkMove(row, col, row+1, col) == true){
			availMoves++;
			 if(isCheck(row+1, col) == true){
				check++;
			}
		}
		if(b->theBoard[row][col]->checkMove(row, col, row-1, col) == true){
			availMoves++;
			if(isCheck(row-1, col) == true){
				check++;
			}
		}
		if(b->theBoard[row][col]->checkMove(row, col, row, col-1) == true){
			availMoves++;
			if(isCheck(row, col-1) == true){
				check++;
			}
		}
		if(b->theBoard[row][col]->checkMove(row, col, row, col+1) == true){
			availMoves++;
			if(isCheck(row, col+1) == true){
				check++;
			}
		}
		if(b->theBoard[row][col]->checkMove(row, col, row-1, col-1) ==true){
			availMoves++;
			if(isCheck(row-1, col-1) == true){
				check++;
			}		
		}
		if(b->theBoard[row][col]->checkMove(row, col, row-1, col+1) == true){
			availMoves++;
			if(isCheck(row-1, col+1) == true){
				check++;
			}
		}
		if(b->theBoard[row][col]->checkMove(row, col, row+1, col-1) == true){
			availMoves++;
			if(isCheck(row+1, col-1) == true){
				check++;
			}
		}
		if(b->theBoard[row][col]->checkMove(row, col, row+1, col+1) == true){
			availMoves++;
			if(isCheck(row+1, col+1) == true){
				check++;
			}	
		}
		if(availMoves == check){
			return true;
		} else {
			return false;
		}
	}
	return false;
}

					

