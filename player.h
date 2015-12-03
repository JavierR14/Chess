#ifndef PLAYER_H
#define PLAYER_H
#include "board.h"

using namespace std;

//class Board;

class Player {
	float gamesWon;
	int id;
	int numKings;
	bool human;
	public:
	Board *b;
	Player(int gamesWon, int id, int numKings, Board *b, bool human);
	bool isHuman();
	int getKings();
	int playerID();
	int kingCol;
	int kingRow;
	void draw();
	void won();
	float getGamesWon();
//	virtual bool castle();
	virtual bool isCheck(int row, int col);
	virtual bool isCheckmate(int row, int col);
	void decKings();
	void incKings();
	void setKing();
};

#endif

