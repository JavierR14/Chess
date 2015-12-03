#ifndef BOARD_H
#define BOARD_H
#include "piece.h"
#include "pawn.h"
#include "rook.h"
#include "knight.h"
#include "bishop.h"
#include "queen.h"
#include "king.h"
#include "controller.h"
#include <iostream>
#include <string>

class Controller;

class Board {
	const int gridsize;
	Controller *Ctrl;  //object registered to notiffy controller of changes
	int turn;
public:
	Piece*** theBoard;  //2-d array
	Board();
	~Board();
	void init(std::string filename, Controller *gameCtrl); //tkaes in filename as string then is opened if its a valid filename
	bool removePiece(int row, int col);
	void addPiece(int row, int col, char p);
	void clearBoard();  //will clearboard regardless of playing again or done the whole thing
	void cnotify(int oldRow, int oldCol, int newRow, int newCol, char p);
	void updateMove(int oldRow, int oldCol, int newRow, int newCol);
	bool validPawns();
	std::string getCurrentPlayer();
	void setCurrentPlayer(char colour);
	Piece* getPiece(int row, int col);
	char getPieceID(int row, int col);
	bool isOccupied (int row, int col);
};

#endif
