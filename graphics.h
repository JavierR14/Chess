#ifndef GRAPHICS_H
#define GRAPHICS_H
#include "view.h"
#include "window.h"
#include <iostream>

class GraphicsDisplay : public View {
	Xwindow *w;

public:
	GraphicsDisplay(int size);
	~GraphicsDisplay();
	virtual void notify(int oldRow, int oldCol, int newRow, int newCol, char c);
	virtual void printBoard(std::ostream &out) const;
	virtual void printScore(float p1Score, float p2Score) const;
};
#endif
