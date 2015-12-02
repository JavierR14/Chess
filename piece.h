#ifndef PIECE_H
#define PIECE_H
#include <string>
#include <cstdlib>
//#include "board.h"

using namespace std;

class Board;

class Piece {
public:
	int row;
	int col;
	int owner;
	Board *b;
	Piece(int row, int col, int owner, Board *b);
//	virtual ~Piece();
	virtual bool checkMove(int row1, int col1, int row2, int col2);
	virtual bool makeMove(int row1, int col1, int row2, int col2);
	virtual char pieceID();
	int getRow();
	int getCol();
	int getOwner();
};


#endif
