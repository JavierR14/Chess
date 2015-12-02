#ifndef HUMAN_H
#define HUMAN_H
#include "player.h"
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

class Human : public Player {
	public:
	Human(int playerID, Board *b);
	bool isCheck();
	bool isCheckmate();
//	bool castle();	
	bool movePiece(int row1, int col1, int row2, int col2);	
}

#endif
