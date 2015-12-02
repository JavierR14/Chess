#ifndef BISHOP_H
#define BISHOP_H
#include "piece.h"
#include "board.h"


class Bishop : public Piece {
	public:
	Bishop(int row, int col, int owner, Board *b);
	bool checkMove(int row1, int col1, int row2, int col2);
	bool makeMove(int row1, int col1, int row2, int col2);
	char pieceID();
}; 

#endif
