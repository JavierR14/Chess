#ifndef KNIGHT_H
#define KNIGHT_H
#include <string>
#include "piece.h"
#include "board.h"

using namespace std;


class Knight : public Piece {
	public:
	Knight(int row, int col, int owner, Board *b);
	bool checkMove(int row1, int col1, int row2, int col2);
	bool makeMove(int row1, int col1, int row2, int col2);
	char pieceID();
};

#endif

