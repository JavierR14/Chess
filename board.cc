//TODO once compiles, change the initialization to addPiece so  no repeated code

#include "board.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
using namespace std;

Board::Board(): theBoard(NULL), Ctrl(NULL), gridsize(8), turn(0) {}

Board::~Board() {
	clearBoard();
}

void Board::init(string filename, Controller *gameCtrl) {
	int player = 1;
	this->Ctrl = gameCtrl;
	//clear the board if it's already initialized, (reset or something)
	if (theBoard!=NULL) {
		this->clearBoard();
	}
	setCurrentPlayer('w');
	//Initialize normal board
	if (filename.length() == 0) {
		theBoard = new Piece**[gridsize];
		for (int i=0; i < gridsize; ++i) {
			//Initialize columns
			theBoard[i] = new Piece*[gridsize];  //2d array of pointers to pieces
			if (i == 0 || i == 1) {
				player = 1;
			}
			if (i == 6 || i == 7) {
				player = 0;
			}
			for (int j=0; j < gridsize; ++j) {
				if (i == 0 || i == 7) {
					//Rooks
					if (j == 0 || j == 7) {
						theBoard[i][j] = new Rook(i, j, player, this);
						cnotify(-1, -1, i, j, theBoard[i][j].pieceID());
					}
					//Knights
					else if (j == 1 || j == 6) {
						theBoard[i][j] = new Knight(i, j, player, this);
						cnotify(-1, -1, i, j, theBoard[i][j].pieceID());
					}
					//bishops
					else if (j == 2 || j == 5) {
						theBoard[i][j] = new Bishop(i, j, player, this);
						cnotify(-1, -1, i, j, theBoard[i][j].pieceID());
					}
					//Queen
					else if (j == 3) {
						theBoard[i][j] = new Queen(i, j, player, this);
						cnotify(-1, -1, i, j, theBoard[i][j].pieceID());
					} else {
						//King
						theBoard[i][j] = new King(i, j, player, this);
						cnotify(-1, -1, i, j, theBoard[i][j].pieceID());
					}
				}
				//PAWNS for PLAYERS
				else if (i == 1 || i == 6)	{
					theBoard[i][j] = new Pawn(i, j, player, this);
					cnotify(-1, -1, i, j, theBoard[i][j].pieceID());
				} else {
					//Empty Space
					theBoard[i][j] = NULL;
				}
			}
		}
	} 
	//Load Pre-saved board
	else {
		char c;
		ifstream input(filename.c_str());
		theBoard = new Piece**[gridsize];
		for (int i=0; i< gridsize; ++i) {
			theBoard[i] = new Piece*[gridsize];  //2d array of pointers to pieces
			for (int j = 0; j < gridsize; ++j) {
				input.get(c);
				//check for end of line
				if (c == '\0') {
					input.get(c);
				}
				//White Rook
				if (c == 'R') {
					theBoard[i][j] = new Rook(i, j, 0, this);
					cnotify(-1, -1, i, j, theBoard[i][j].pieceID());
				}
				//Black Rook
				else if (c == 'r') {
					theBoard[i][j] = new Rook(i, j, 1, this);
					cnotify(-1, -1, i, j, theBoard[i][j].pieceID());
				}
				//Whtie Knight
				else if (c == 'N') {
					theBoard[i][j] = new Knight(i, j, 0, this);
					cnotify(-1, -1, i, j, theBoard[i][j].pieceID());
				}
				else if (c == 'n') {
					theBoard[i][j] = new Knight(i, j, 1, this);
					cnotify(-1, -1, i, j, theBoard[i][j].pieceID());
				}
				//White Bishop
				else if (c == 'B') {
					theBoard[i][j] = new Bishop(i, j, 0, this);
					cnotify(-1, -1, i, j, theBoard[i][j].pieceID());
				}
				//Black Bishop
				else if (c == 'b') {
					theBoard[i][j] = new Bishop(i, j, 1, this);
					cnotify(-1, -1, i, j, theBoard[i][j].pieceID());
				}
				//White Queen
				else if (c == 'Q') {
					theBoard[i][j] = new Queen(i, j, 0, this);
					cnotify(-1, -1, i, j, theBoard[i][j].pieceID());
				}
				else if (c == 'q') {
					theBoard[i][j] = new Queen(i, j, 1, this);
					cnotify(-1, -1, i, j, theBoard[i][j].pieceID());
				}
				//White KIng
				else if (c == 'K') {
					theBoard[i][j] = new King(i, j, 0, this);
					cnotify(-1, -1, i, j, theBoard[i][j].pieceID());
				}
				else if (c == 'k') {
					theBoard[i][j] = new King(i, j, 1, this);
					cnotify(-1, -1, i, j, theBoard[i][j].pieceID());
				}
				else if (c == 'P') {
					theBoard[i][j] = new Pawn(i, j, 0, this);
					cnotify(-1, -1, i, j, theBoard[i][j].pieceID());
				}
				else if (c == 'p') {
					theBoard[i][j] = new Pawn(i, j, 1, this);
					cnotify(-1, -1, i, j, theBoard[i][j].pieceID());
				} else {
					theBoard[i][j] = NULL;
				}
			}
		}
		input.get(c);
		setCurrentPlayer(c); 
	}
}

bool Board::removePiece(int row, int col) {
	if (theBoard[row][col] != NULL) {
		delete theBoard[row][col];
		theBoard[row][col] = NULL;
		cnotify(row, col, -1, -1, '');
		return true;
	}
	return false;
}

void Board::addPiece(int row, int col, char p) {
	delete theBoard[row][col];
	theBoard[row][col] = NULL;
	//White Rook
	if (p == 'R') {
		theBoard[row][col] = new Rook(row, col, 0, this);
		cnotify(-1, -1, row, col, theBoard[row][col].pieceID());
	}
	//Black Rook
	else if (p == 'r') {
		theBoard[row][col] = new Rook(row, col, 1, this);
		cnotify(-1, -1, row, col, theBoard[row][col].pieceID());
	}
	//Whtie Knight
	else if (p == 'N') {
		theBoard[row][col] = new Knight(row, col, 0, this);
		cnotify(-1, -1, row, col, theBoard[row][col].pieceID());
	}
	else if (p == 'n') {
		theBoard[row][col] = new Knight(row, col, 1, this);
		cnotify(-1, -1, row, col, theBoard[row][col].pieceID());
	}
	//White Bishop
	else if (p == 'B') {
		theBoard[row][col] = new Bishop(row, col, 0, this);
		cnotify(-1, -1, row, col, theBoard[row][col].pieceID());
	}
	//Black Bishop
	else if (p == 'b') {
		theBoard[row][col] = new Bishop(row, col, 1, this);
		cnotify(-1, -1, row, col, theBoard[row][col].pieceID());
	}
	//White Queen
	else if (p == 'Q') {
		theBoard[row][col] = new Queen(row, col, 0, this);
		cnotify(-1, -1, row, col, theBoard[row][col].pieceID());
	}
	else if (p == 'q') {
		theBoard[row][col] = new Queen(row, col, 1, this);
		cnotify(-1, -1, row, col, theBoard[row][col].pieceID());
	}
	//White KIng
	else if (p == 'K') {
		theBoard[row][col] = new King(row, col, 0, this);
		cnotify(-1, -1, row, col, theBoard[row][col].pieceID());
	}
	else if (p == 'k') {
		theBoard[row][col] = new King(row, col, 1, this);
		cnotify(-1, -1, row, col, theBoard[row][col].pieceID());
	}
	else if (p == 'P') {
		theBoard[row][col] = new Pawn(row, col, 0, this);
		cnotify(-1, -1, row, col, theBoard[row][col].pieceID());
	}
	else if (p == 'p') {
		theBoard[row][col] = new Pawn(row, col, 1, this);
		cnotify(-1, -1, row, col, theBoard[row][col].pieceID());
	}
	else {
		theBoard[row][col] = NULL;
	}
}

//might need to fix....not sure if right
void Board::clearBoard() {
	//delete the columns
	for (int i=0; i < gridsize; ++i) {
		for (int j=0; j < gridsize; ++j) {
			//delete the pieces
			delete theBoard[i][j];
		}
		delete[] theBoard[i];
	}
	//delete the rows
	delete[] theBoard;
}

void Board::cnotify(int oldRow, int oldCol, int newRow, int newCol, char p) {
	Ctrl->notify(oldRow, oldCol, newRow, newCol, p);
}

void Board::updateMove(int oldRow, int oldCol, int newRow, int newCol) {
	delete theBoard[newRow][newCol];
	theBoard[newRow][newCol] = theBoard[oldRow][oldCol];
	//delete theBoard[oldRow][oldCol];
	theBoard[oldRow][oldCol] = NULL;
	cnotify(oldRow, oldCol, newRow, newCol, theBoard[newRow][newCol].pieceID());
}

bool Board::validPawns() {
	for (int col = 0; col < gridsize; ++col) {
		if (theBoard[0][col].pieceID() == 'p' ||  theBoard[0][col].pieceID() == 'P' || theBoard[7][col].pieceID() == 'p' || theBoard[7][col].pieceID() == 'P') {
			return false;
		}
	}
	return true;
}

string Board::getCurrentPlayer() {
	if (turn == 0) {
		return "P1";
	} else {
		return "P2";
	}
}

void Board::setCurrentPlayer(char colour) {
	if (colour == 'w' || colour == 'W') {
		turn = 0;
	}
	else if (colour == 'b' || colour == 'B') {
		turn = 1;
	} else {
		return;
	}
}

Piece* Board::getPiece(int row, int col) {
	return &theBoard[row][col];
}

char Board::getPieceID(int row, int col) {
	return theBoard[row][col].pieceID();
}

bool Board::isOccupied(int row, int col) {
	if (theBoard[row][col] != NULL) {
		return false;
	}
	return true;
}
