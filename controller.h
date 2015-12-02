#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <iostream>
#include <string>
#include "board.h"
#include "view.h"
#include "player.h"
#include "human.h"
#include "computer.h"

class Player;
class Human;
class Computer;
class Board;

class Controller {
	View *td;
	Board *board;
	Player *p1;
	Player *p2;
	bool ingame;
	bool betweengame;
	int getRow(std::string location);
	int getCol(std::string location);
	void askPlayAgain();
public:
	Controller();
	~Controller();
	void playGame(std::string filename);
	void notify(int oldRow, int oldCol, int newRow, int newCol, char c);
};

#endif
