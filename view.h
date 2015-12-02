#ifndef VIEW_H
#define VIEW_H
#include "controller.h"
#include <iostream>

//const int GRIDSIZE = 8;

 class View {
 protected:
 	int bSize;
 public:
 	View(int n);
 	virtual ~View() = 0;
 	virtual void printBoard(std::ostream &out) const = 0;
 	virtual void notify(int oldRow, int oldCol, int newRow, int newCol, char c) = 0;
 	virtual void printScore(float p1Score, float p2Score) const = 0;
 };
 #endif
 