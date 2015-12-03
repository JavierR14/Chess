#ifndef HUMAN_H
#define HUMAN_H
#include "player.h"
#include <cstdlib>
#include <iostream>
#include <string>
#include "board.h"

using namespace std;

class Human : public Player {
	public:
	Human(int playerID, Board *b);
	bool isCheck(int row, int col);
	bool isCheckmate(int row, int col);
//	bool castle();	
	bool movePiece(int row1, int col1, int row2, int col2);	
};

#endif
