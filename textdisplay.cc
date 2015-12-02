#include "textdisplay.h"
#include <iostream>
#include <string>
using namespace std;

TextDisplay::TextDisplay(int size): View(size) {
	bDisplay = new char*[size];
	for (int i=0; i < size; i++) {
		bDisplay[i] = new char[size];
		for (int j=0; j < size; j++) {
			//even numbered rows are white (odd in game)
			if (i%2 == 0) {
				if (j%2 == 0) {
					bDisplay[i][j] = ' ';
				} else {
					bDisplay[i][j] = '_';
				}
			//odd numbered rows are black (even in game)
			} else {
				if (j%2 == 0) {
					bDisplay[i][j] = '_';
				} else {
					bDisplay[i][j] = ' ';
				}
			}
		}
	}
}

TextDisplay::~TextDisplay() {
	for (int i=0; i<bSize; i++) {
		delete[] bDisplay[i];
	}
	delete[] bDisplay;
}

void TextDisplay::notify(int oldRow, int oldCol, int newRow, int newCol, char c) {
	//If -1 then don't update a new location...must've been deleted
	if (newRow != -1 && newCol != -1) {
		bDisplay[newRow][newCol] = c;
	}
	
	//if it had no old position
	if (oldRow == -1 && oldCol == -1) {
		return;
	}
	//set old position back to white or black tile
	if (oldRow % 2 == 0) {
		if (oldCol%2 == 0) }{
			bDisplay[oldRow][oldCol] = ' '
		} else {
			bDisplay[oldRow][oldCol] = '_'
		}
	} else {
		if (oldCol%2 == 0) {
			bDisplay[oldRow][oldCol] = '_'
		} else {
			bDisplay[oldRow][oldCol] = ' '
		}
	}
}

void TextDisplay::printBoard(ostream &out) {
	for (int i=0; i < this->bSize; ++i) {
		for (int j=0; j < this->bSize; ++j) {
			out << bDisplay[i][j];
		}
		out << endl;
	}
}

void TextDisplay::printScore(float p1Score; float p2Score) {
	cout << "Final Score:" << endl;
	cout << "White: " << p1Score << endl;
	cout << "Black: " << p2Score << endl;
}
