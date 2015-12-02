#include "player.h"
#include <cstdlib>
#include <string>
#include <iostream>


Player::Player(int gamesWon, int ID, int numKings, bool Human):
	gamesWon(gamesWon), ID(ID), numKings(numKings), b(b), isHuman(isHuman){}

bool Player::isHuman(){
	return this->Human;
}

void draw(){
	this->gamesWon += 0.5;
}

void won(){
	this->gamesWon += 1;
}

float getGamesWon(){
	return this->gamesWon;
}

int Player::getKings(){
	return this->numKings;
}

int Player::playerID(){
	return this->ID;
}

void Player::decKings(){
	this->numKings--;
}

void Player::incKings(){
	this->numKings++;
}

void Player::setKing(){
	for(int i =0; i<8;i++){
		for(int j=0; i<8; j++){
			if((b->getPiece(i,j)->pieceID() == 'K') ||
				(b->getPiece(i,j)->pieceID() =='k')){
				if(b->getPiece(i,j)->getOwner() == playerID()){
					this->kingRow=i;
					this->kingCol=j;
					return;
				}
			}
		}
	}
}
				
