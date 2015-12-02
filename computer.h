#ifndef COMPUTER_H
#define COMPUTER_H
#include "player.h"

class Computer : public Player {
	int level;
	public:
	Computer(int playerID, int level, Board *b);
	bool movePiece();
	bool isCheck();
	bool isCheckmate();
};

#endif		
