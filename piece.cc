#include "piece.h"
#include <string>
#include <iostream>
#include <sstream>
#include <cstdlib>
using namespace std;

Piece::Piece(int row, int col, int owner, Board *b): row(row), col(col), owner(owner), b(b) {}

int Piece::getRow(){
	return this->row;
}

int Piece::getCol(){
	return this->col;
}

int Piece::getOwner(){
	return this->owner;
}



