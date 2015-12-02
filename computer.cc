#include "computer.h"
#include "board.h"
#include <cstdlib>
#include <iostream>

using namespace std;

Computer::Computer(int playerID, int level, Board *b): Player(0, playerID, 0, b, false){
	this->level = level;
}

bool Computer::movePiece(){
	if(level == 1){
		for(int i=0; i<8; i++){
			for(int z=0; z<8; z++){
				if(b->theBoard[i][z]->getOwner() == this->playerID()){
					if(b->theBoard[i][z]->pieceID() == 'P'){
						if(b->getPiece(i,z)->makeMove(i,z,i-1,z-1)){
							b->updateMove(i,z,i-1,z-1);
							return true;
						}
						else if(b->getPiece(i,z)->makeMove(i,z,i-1,z)){
							b->updateMove(i,z,i-1,z);
							return true;
						}
						else if(b->getPiece(i,z)->makeMove(i,z,i-1,z+1)){
							b->updateMove(i,z,i-1,z+1);
							return true;
						}
					}
					else if(b->getPiece(i,z)->pieceID() == 'p'){
						if(b->getPiece(i,z)->makeMove(i,z,i+1,z-1)){
							b->updateMove(i,z,i+1,z-1);
							return true;
						}
						else if(b->getPiece(i,z)->makeMove(i,z,i+1,z)){
							b->updateMove(i,z,i+1,z);
							return true;
						}
						else if(b->getPiece(i,z)->makeMove(i,z,i+1,z+1)){
							b->updateMove(i,z,i+1,z+1);
							return true;
						}
					}
					if((b->getPiece(i,z)->pieceID() == 'B')
						|| (b->getPiece(i,z)->pieceID() == 'b')){
						if(b->getPiece(i,z)->checkMove(i,z,i+1,z+1)){
							int moves=2;
							while(b->getPiece(i,z)->checkMove(i,z,i+moves,z+moves)){
								if(moves==4){
									break;
								}
								moves++;
							}
							b->getPiece(i,z)->makeMove(i,z,i+moves-1,z+moves-1);
							b->updateMove(i,z,i+moves-1,z+moves-1);
							return true;
						}
						else if(b->getPiece(i,z)->checkMove(i,z,i-1,z-1)){
							int moves=2;
							while(b->getPiece(i,z)->checkMove(i,z,i-moves,z-moves)){
								if(moves==4){
									break;
								}
								moves++;
							}
							b->getPiece(i,z)->makeMove(i,z,i-moves+1,z-moves+1);
							b->updateMove(i,z,i-moves+1,z-moves+1);
							return true;
						}
						else if(b->getPiece(i,z)->checkMove(i,z,i+1,z-1)){
							int moves=2;
							while(b->getPiece(i,z)->checkMove(i,z,i+moves,z-moves)){
								if(moves==4){
									break;
								}
								moves++;
							}
							b->getPiece(i,z)->makeMove(i,z,i+moves-1,z-moves+1);
							b->updateMove(i,z,i+moves-1,z-moves+1);
							return true;
						}
						else if(b->getPiece(i,z)->checkMove(i,z,i-1,z+1)){
							int moves=2;
							while(b->getPiece(i,z)->checkMove(i,z,i-moves,z+moves)){
								if(moves==4){
									break;
								}
								moves++;
							}
							b->getPiece(i,z)->makeMove(i,z,i-moves+1,z+moves-1);
							b->updateMove(i,z,i-moves+1,z+moves-1);
							return true;
						}
					}
					if((b->getPiece(i,z)->pieceID() == 'R') ||
						(b->getPiece(i,z)->pieceID() == 'r')){
						if(b->getPiece(i,z)->checkMove(i,z,i+1,z)){
							int moves=2;
							while(b->getPiece(i,z)->checkMove(i,z,i+moves,z)){
								if(moves==4){
									break;
								}
								moves++;
							}
							b->getPiece(i,z)->makeMove(i,z,i+moves-1,z);
							b->updateMove(i,z,i+moves-1,z);
							return true;
						}
						if(b->getPiece(i,z)->checkMove(i,z,i,z-1)){
							int moves=2;
							while(b->getPiece(i,z)->checkMove(i,z,i,z-moves)){
								if(moves==4){
									break;
								}
								moves++;
							}
							b->getPiece(i,z)->makeMove(i,z,i,z-moves+1);
							b->updateMove(i,z,i,z-moves+1);
							return true;
						}
						if(b->getPiece(i,z)->checkMove(i,z,i,z+1)){
							int moves=2;
							while(b->getPiece(i,z)->checkMove(i,z,i,z+moves)){
								if(moves==4){
									break;
								}
								moves++;
							}
							b->getPiece(i,z)->makeMove(i,z,i,z+moves-1);
							b->updateMove(i,z,i,z+moves-1);
							return true;
						}
						if(b->getPiece(i,z)->checkMove(i,z,i-1,z)){
							int moves=2;
							while(b->getPiece(i,z)->checkMove(i,z,i-moves,z)){
								if(moves==4){
									break;
								}
								moves++;
							}
							b->getPiece(i,z)->makeMove(i,z,i-moves+1,z);
							b->updatemove(i,z,i-moves+1,z);
							return true;
						}
					}
					if((b->getPiece(i,z)->pieceID() == 'N')
						|| (b->getPiece(i,z)->pieceID() == 'n')){
						if(b->getPiece(i,z)->makeMove(i,z,i+2,z-1)){
							b->updateMove(i,z,i+2,z-1);
							return true;
						}
						else if(b->getPiece(i,z)->makeMove(i,z,i+2,z+1)){
							b->updateMove(i,z,i+2,z+1);
							return true;
						}
						if(b->getPiece(i,z)->makeMove(i,z,i-1,z+2)){
							b->updateMove(i,z,i-1,z+2);
							return true;
						}
						if(b->getPiece(i,z)->makeMove(i,z,i-1,z-2)){
							b->updateMove(i,z,i-1,z-2);
							return true;
						}
						if(b->getPiece(i,z)->makeMove(i,z,i-2,z+1)){
							b->updateMove(i,z,i-2,z+1);
							return true;
						}
						if(b->getPiece(i,z)->makeMove(i,z,i-2,z-1)){
							b->updateMove(i,z,i-2,z-1);
							return true;
						}
						if(b->getPiece(i,z)->makeMove(i,z,i+1,z-2)){
							b->updateMove(i,z,i+1,z-2);
							return true;
						}
						if(b->getPiece(i,z)->makeMove(i,z,i+1,z+2)){
							b->updateMove(i,z,i+1,z+2);
							return true;
						}
					}
					if((b->getPiece(i,z)->pieceID() == 'K') ||
						(b->getPiece(i,z)->pieceID() == 'k') ||
						(b->getPiece(i,z)->pieceID() == 'Q') ||
						(b->getPiece(i,z)->pieceID() == 'q')){
						if(b->getPiece(i,z)->makeMove(i,z,i,z+1)){
							b->updateMove(i,z,i,z+1);
							return true;
						}
						if(b->getPiece(i,z)->makeMove(i,z,i,z-1)){
							b->updateMove(i,z,i,z-1);
							return true;
						}
						if(b->getPiece(i,z)->makeMove(i,z,i+1,z)){
							b->updateMove(i,z,i+1,z);
							return true;
						}
						if(b->getPiece(i,z)->makeMove(i,z,i-1,z)){
							b->updateMove(i,z,i-1,z);
							return true;
						}
						if(b->getPiece(i,z)->makeMove(i,z,i+1,z+1)){
							b->updateMove(i,z,i+1,z+1);
							return true;
						}
						if(b->getPiece(i,z)->makeMove(i,z,i+1,z-1)){
							b->updateMove(i,z,i+1,z-1);
							return true;
						}
						if(b->getPiece(i,z)->makeMove(i,z,i-1,z+1)){
							b->updateMove(i,z,i-1,z+1);
							return true;
						}
						if(b->getPiece(i,z)->makeMove(i,z,i-1,z-1)){
							b->updateMove(i,z,i-1,z-1);
							return true;
						}
					}
				}
			}
		}
	}
	return false;
}

bool Computer::isCheck(int row, int col){
	for(int i =0; i<8; i++){
		for(int j=0; j<8; j++){
			if(b->theBoard[i][j].getOwner() == this->playerID()){
				if(b->theBoard[i][j].checkMove(i, j, row, col) == true){
					return true;
			}
		}
	}
}
	
bool Computer::isCheckmate(int row, int col){
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

					

