#include "graphics.h"
#include <iostream>
#include "window.h"
#include <string>
#include <sstream>
using namespace std;

GraphicsDisplay::GraphicsDisplay(int size): View(size) {
	//bDisplay = new char*[bSize];
	int row;
	string r;
	w = new Xwindow;
	for (int i=0; i < bSize; i++) {
		//bDisplay[i] = new char[bSize];
		row = 8 -i; 
		stringstream ss;
		ss << row;
		ss >> r;
		w->drawBigString(50, 50*i + 35, r, Xwindow::Black);
		for (int j=0; j < bSize; j++) {
			//even numbered rows are white (odd in game)
			if (i%2 == 0) {
				if (j%2 == 0) {
					//cout << "got" << endl;
					w->fillRectangle(100 + 50*j, 50*i, 50, 50, Xwindow::White);
					//w->fillRectangle(0, 0, 50, 50, Xwindow::White);

					//cout << "bru" << endl;
					//bDisplay[i][j] = ' ';
				} else {
					//cout << "you" << endl;

					w->fillRectangle(100 + 50*j, 50*i, 50, 50, Xwindow::Black);
					//bDisplay[i][j] = '_';
				}
			//odd numbered rows are black (even in game)
			} else {
				if (j%2 == 0) {
					w->fillRectangle(100 + 50*j, 50*i, 50, 50, Xwindow::Black);
					//bDisplay[i][j] = '_';
				} else {
					w->fillRectangle(100 + 50*j, 50*i, 50, 50, Xwindow::White);
					//bDisplay[i][j] = ' ';
				}
			}
		}
	}
	w->drawBigString(115, 450, "a", Xwindow::Black);
	w->drawBigString(165, 450, "b", Xwindow::Black);
	w->drawBigString(215, 450, "c", Xwindow::Black);
	w->drawBigString(265, 450, "d", Xwindow::Black);
	w->drawBigString(315, 450, "e", Xwindow::Black);
	w->drawBigString(365, 450, "f", Xwindow::Black);
	w->drawBigString(415, 450, "g", Xwindow::Black);
	w->drawBigString(465, 450, "h", Xwindow::Black);
}

GraphicsDisplay::~GraphicsDisplay() {
	delete w;
}

void GraphicsDisplay::notify(int oldRow, int oldCol, int newRow, int newCol, char c) {
	//If -1 then don't update a new location...must've been deleted
	string piece;
	stringstream ss;
	ss << c;
	ss >> piece;
	if (newRow != -1 && newCol != -1) {
		//bDisplay[newRow][newCol] = c;
		if (newRow%2 == 0) {
			if (newCol%2 == 0) {
				//cout << "got" << endl;
				w->fillRectangle(100 + 50*newCol,50*newRow, 50, 50, Xwindow::White);
				//w->fillRectangle(0, 0, 50, 50, Xwindow::White);

				//cout << "bru" << endl;
				//bDisplay[i][j] = ' ';
			} else {
				//cout << "you" << endl;

				w->fillRectangle(100 + 50*newCol, 50*newRow, 50, 50, 1);
				//bDisplay[i][j] = '_';
			}
			//odd numbered rows are black (even in game)
		} else {
			if (newCol%2 == 0) {
				w->fillRectangle(100 + 50*newCol, 50*newRow, 50, 50, 1);
				//bDisplay[i][j] = '_';
			} else {
				w->fillRectangle(100 + 50*newCol, 50*newRow, 50, 50, 0);
				//bDisplay[i][j] = ' ';
			}
		}
		w->drawBigString(100 + 50*newCol + 15, 50*newRow + 35, piece, Xwindow::Red);
	}
	
	//if it had no old position
	if (oldRow == -1 && oldCol == -1) {
		return;
	}

//even numbered rows are white (odd in game)
	if (oldRow%2 == 0) {
		if (oldCol%2 == 0) {
			//cout << "got" << endl;
			w->drawBigString(100 + 50*oldCol + 15, 50*oldRow + 35, piece, Xwindow::White);
			//w->fillRectangle(0, 0, 50, 50, Xwindow::White);

			//cout << "bru" << endl;
			//bDisplay[i][j] = ' ';
		} else {
			//cout << "you" << endl;
			w->drawBigString(100 + 50*oldCol + 15, 50*oldRow + 35, piece, Xwindow::Black);
			//bDisplay[i][j] = '_';
		}
	//odd numbered rows are black (even in game)
	} else {
		if (oldCol%2 == 0) {
			w->drawBigString(100 + 50*oldCol + 15, 50*oldRow + 35, piece, Xwindow::Black);
			//bDisplay[i][j] = '_';
		} else {
			w->drawBigString(100 + 50*oldCol + 15, 50*oldRow + 35, piece, Xwindow::White);
			//bDisplay[i][j] = ' ';
		}
	}

	//w->drawBigString(100 + 50*oldCol + 15, 50*oldRow + 35, "WTF", Xwindow::Red);
	//set old position back to white or black tile
	//if (oldRow % 2 == 0) {
	//	if (oldCol%2 == 0) {

	//		bDisplay[oldRow][oldCol] = ' ';
	//	} else {
	//		bDisplay[oldRow][oldCol] = '_';
	//	}
	//} else {
	//	if (oldCol%2 == 0) {
	//		bDisplay[oldRow][oldCol] = '_';
	//	} else {
	//		bDisplay[oldRow][oldCol] = ' ';
	//	}
}

void GraphicsDisplay::printBoard(ostream &out) const {}
void GraphicsDisplay::printScore(float p1Score, float p2Score) const {}
