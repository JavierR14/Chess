#ifndef QUEEN_H
#define QUEEN_H
#include "piece.h"
#include "board.h"

using namespace std;


class Queen : public Piece {
	public:
	Queen(int row, int col, int owner, Board *b);
	bool checkMove(int row1, int col1, int row2, int col2);
	bool makeMove(int row1, int col1, int row2, int col2);
	char pieceID();
};

#endif
