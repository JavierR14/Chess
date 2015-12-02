#ifndef PAWN_H
#define PAWN_H

using namespace std;


class Pawn : public Piece {
	bool firstmove;
	public:
	Pawn(int row, int col, int owner, Board *b);
	bool checkMove(int row1, int col1, int row2, int col2);
	bool makeMove(int row1, int col1, int row2, int col2);
	char pieceID();
};

#endif
