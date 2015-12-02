#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H
#include "view.h"
#include <iostream>

class TextDisplay: public View {
	char **bDisplay;
public:
	TextDisplay(int size);
	~TextDisplay();
	virtual void notify(int oldRow, int oldCol, int newRow, int newCol, char c);
	virtual void printBoard(std::ostream &out) const;
	virtual void printScore(float p1Score, float p2Score) const;
};
#endif
