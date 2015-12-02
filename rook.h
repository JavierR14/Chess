#ifndef ROOK_H
#define ROOK_H
#include "piece.h"
#include "board.h"

using namespace std;


class Rook : public Piece {
	public:
	Rook(int row, int col, int owner, Board *b);
	bool checkMove(int row1, int col1, int row2, int col2);
	bool makeMove(int row1, int col1, int row2, int col2);
	char pieceID();
};

#endif
