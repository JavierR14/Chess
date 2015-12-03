#include "computer.h"
#include "board.h"
#include <cstdlib>
#include <iostream>
#include <ctime>

using namespace std;

Computer::Computer(int playerID, int level, Board *b): Player(0, playerID, 1, b, false){
	this->level = level;
}

bool Computer::movePiece(){
	srand(time(NULL));
	int skip = (rand() % 4);
	if(level == 1){
/*
		for(int i=0; i<8; i++){
			for(int z=0; z<8; z++){
				if(b->getPiece(i,z) !=NULL){
				if(b->getPiece(i,z)->getOwner() == this->playerID()){
					if(b->getPiece(i,z)->pieceID() == 'P'){
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
							b->updateMove(i,z,i-moves+1,z);
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
*/
	for(int i=0; i<8; i++){
		for(int j=0; j<8; j++){
			if((b->getPiece(i,j) !=NULL) && 
				(b->getPiece(i,j)->getOwner() == this->playerID())){
				for(int x=0; x<8; x++){
					for(int y=0; y<8; y++){
						if((skip==0)
							&& (b->getPiece(i,j)->makeMove(i,j,x,y))){
							b->updateMove(i,j,x,y);
							return true;
						}
						if(b->getPiece(i,j)->makeMove(i,j,x,y)){
							skip--;
						}
					}
				}
			}
		}
	}  
	}
	else if(level ==2){
	int count = 0;
	while(count < 2){
		for(int i=0; i<8; i++){
			for(int j=0; j<8; j++){
				if((b->getPiece(i,j) != NULL) && 
					(b->getPiece(i,j)->getOwner() == this->playerID())){
				for(int x=0; x<8; x++){
					for(int y=0; y<8; y++){
						if((b->getPiece(x,y) !=NULL) &&
						(b->getPiece(x,y)->getOwner() != this->playerID())){
							if(b->getPiece(i,j)->makeMove(i,j,x,y)){
								b->updateMove(i,j,x,y);
								count =2;
								return true;
							}
						}
						if((b->getPiece(i,j)->checkMove(i,j,x,y)) &&
						(b->getPiece(i,j)->checkMove(x,y,this->kingRow, this->kingCol))){
							b->getPiece(i,j)->makeMove(i,j,x,y);
							b->updateMove(i,j,x,y);
							return true;
						}	
						if(count==1){
							if(b->getPiece(i,j)->makeMove(i,j,x,y)){
								b->updateMove(i,j,x,y);
								count =2;
								return true;
							}
						}
					}
				}
				}
			}
		}
	count++;
	}				
	return false;
	}
	else if(level ==3){
		return true;
	}
	
}

bool Computer::isCheck(int row, int col){
	for(int i =0; i<8; i++){
		for(int j=0; j<8; j++){
			if(b->getPiece(i,j)->getOwner() == this->playerID()){
				if(b->getPiece(i,j)->checkMove(i, j, row, col) == true){
					return true;
				}
			}
		}
	}
}
	
bool Computer::isCheckmate(int row, int col){
	if(isCheck(row, col) == true){
		int check=0;
		int availMoves =0;
		if(b->getPiece(i,j)->checkMove(row, col, row+1, col) == true){
			availMoves++;
			 if(isCheck(row+1, col) == true){
				check++;
			}
		}
		if(b->getPiece(i,j)->checkMove(row, col, row-1, col) == true){
			availMoves++;
			if(isCheck(row-1, col) == true){
				check++;
			}
		}
		if(b->getPiece(i,j)->checkMove(row, col, row, col-1) == true){
			availMoves++;
			if(isCheck(row, col-1) == true){
				check++;
			}
		}
		if(b->getPiece(i,j)->checkMove(row, col, row, col+1) == true){
			availMoves++;
			if(isCheck(row, col+1) == true){
				check++;
			}
		}
		if(b->getPiece(i,j)->checkMove(row, col, row-1, col-1) ==true){
			availMoves++;
			if(isCheck(row-1, col-1) == true){
				check++;
			}		
		}
		if(b->getPiece(i,j)->checkMove(row, col, row-1, col+1) == true){
			availMoves++;
			if(isCheck(row-1, col+1) == true){
				check++;
			}
		}
		if(b->getPiece(i,j)->checkMove(row, col, row+1, col-1) == true){
			availMoves++;
			if(isCheck(row+1, col-1) == true){
				check++;
			}
		}
		if(b->getPiece(i,j)->checkMove(row, col, row+1, col+1) == true){
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

					

