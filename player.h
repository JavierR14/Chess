#ifndef PLAYER_H
#define PLAYER_H

class Board;


class Player {
	float gamesWon;
	int ID;
	int numKings;
	bool Human;
	Board *b;
	public:
	Player(int gamesWon, int playerID, int numKings, Board *b, bool Human);
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

