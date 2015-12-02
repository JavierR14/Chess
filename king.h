#ifndef KING_H
#define KING_H
#include "piece.h"
#include "board.h"
#include <cstdlib>
#include <string>


class King : public Piece {
	public:
	King(int row, int col, int owner, Board *b);
	bool checkMove(int row1, int col1, int row2, int col2);
	bool makeMove(int row1, int col1, int row2, int col2);
	char pieceID();
};

#endif

