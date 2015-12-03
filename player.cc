#include "player.h"
#include <cstdlib>
#include <string>
#include <iostream>


Player::Player(int gamesWon, int id, int numKings, Board *b, bool human):
	gamesWon(gamesWon), id(id), numKings(numKings), b(b), human(human){}

bool Player::isHuman(){
	return this->human;
}

void Player::draw(){
	this->gamesWon += 0.5;
}

void Player::won(){
	this->gamesWon += 1;
}

float Player::getGamesWon(){
	return this->gamesWon;
}

int Player::getKings(){
	return this->numKings;
}

int Player::playerID(){
	return this->id;
}

void Player::decKings(){
	this->numKings--;
}

void Player::incKings(){
	this->numKings++;
}

void Player::setKing(){
	for(int i =0; i<8;i++){
		for(int j=0; j<8; j++){
			if(b->getPiece(i,j) != NULL){
			//	cout << "row: " << i << endl;
			//	cout << "step1" << endl;
			//	cout << "piece id: " << b->getPiece(i,j)->pieceID() << endl;
				if((b->getPiece(i,j)->pieceID() == 'K') ||
					(b->getPiece(i,j)->pieceID() =='k')){
			//		cout <<"step2"<<endl;
					if(b->getPiece(i,j)->getOwner() != this->playerID()){
			//			cout<<"step3"<<endl;
						this->kingRow=i;
						this->kingCol=j;
					}	
				}
			}
		}
	}
}
				
