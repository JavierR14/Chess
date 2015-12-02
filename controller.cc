//TODO 
//AskPlayAgain function, call alll the check and checkmate stuff for each player after every move, main.cc

#include "controller.h"
#include "textdisplay.h"
#include "board.h"
#include "player.h"
#include "human.h"
#include "computer.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

Controller::Controller() {
	td = NULL;
	board = new Board();
	p1 = NULL;
	p2 = NULL;
	//Possible stuff for graphics
}

Controller::~Controller() {
	delete board;
	delete td;
	delete p1;
	delete p2;
}

void Controller::askPlayAgain() {
	string answer;
	cout << "Would you like to play again with the same players? (Yes or No) : ";
	cin >> answer;
	if (answer == "Yes") {
		betweengame = true;
		delete td;
		td = new TextDisplay(8);
		board->init("", this);
		td->printBoard(cout);
		//set number of kings for each player to 1 without calling constructor again
	} else {
		ingame = false;
		betweengame = false;
		cout << "You may now quit or issue new commands" << endl;
	}
}

int Controller::getRow(string location) {
	char letter = location.at(1);
	int row = letter - '0';
	//conver to proper row number on 2D array...e8 would be in the 1st row(index 0)
	row = abs(row-8);
	if (row >= 0 && row <= 7) {
		return row;
	}
	return -1;
}

//Convert location to column coordinate
int Controller::getCol(string location) {
	char letter = location.at(0);
	//return column number
	if (letter >=  'a' && letter <= 'h') {
		return letter - 'a';
	}
	return -1;
}

//Main function for Playing the Game and handling input
void Controller::playGame(string filename) {
	string cmd;
	ingame = false;  //true once first move occurs
	betweengame = false;
	while (cin>>cmd) {
		if (cmd == "game" && ingame == false) {
			string tempcmd;
			string tempcmd2;
			delete p1;
			delete p2;
			//valid input for first word
			while (tempcmd!="human" && tempcmd!="computer[1]" && tempcmd!="computer[2]" && tempcmd!="computer[3]" && tempcmd!="computer[4]") {
				cin >>tempcmd;
			}
			//valid input for second word
			while (tempcmd2!="human" && tempcmd2!="computer[1]" && tempcmd2!="computer[2]" && tempcmd2!="computer[3]" && tempcmd2!="computer[4]") {
				cin >>tempcmd2;
			}
			//determine human or computer for player 1
			if (tempcmd == "human") {
				p1 = new Human(0, board);
			} else if (tempcmd == "computer[1]") {
				p1 = new Computer(0, 1, board);
			} else if (tempcmd=="computer[2]") {
				p1 = new Computer(0, 2, board);
			} else if (tempcmd == "computer[3]") {
				p1 = new Computer(0, 3, board);
			} else {
				p1 = new Computer(0, 4, board);
			}
			//determine human or computer for player 2
			if (tempcmd2 == "human") {
				p2 = new Human(1, board);
			} else if (tempcmd2 == "computer[1]") {
				p2 = new Computer(1, 1, board);
			} else if (tempcmd2 =="computer[2]") {
				p2 = new Computer(1, 2, board);
			} else if (tempcmd2 == "computer[3]") {
				p2 = new Computer(1, 3, board);
			} else {
				p2 = new Computer(1, 4, board);
			}
			//set up initial board  -- IMPORTANT
			delete td;
			td = new TextDisplay(8);
			board->init(filename, this);
			p1->setKing();
			p2->setKing();
			td->printBoard(cout);
		}
		//Resign -------------------------------------------------------
		else if (cmd == "resign") {
			//get the current player
			string curr = board->getCurrentPlayer();
			//call a player's resign fucnction
			if (curr == "P1") {
				cout << "Player 1 has resigned. Player 2 Wins." << endl;
				p2->won();
			} else {
				cout << "Player 2 has resigned. Player 1 Wins." << endl;
				p1->won();
			}
			//Might have to call ingame=false, in order to be able to start a new game,
			// but then how do i keep track of scores if players keep their scores?
			//ask play again will reset board, set betweengame to true(enables setup before move is called)
			askPlayAgain();	
		}
		//SETUP MODE---------------------------------------------------------------------------------------
		//betweengame will be handled in the askPlayAgain()
		else if (cmd == "setup" && ingame == false || cmd == "setup" && betweengame == true) {
			string setupcmd;
			char piece;
			string tile; 
			while (true) {
				cin>>setupcmd;
				if (setupcmd == "+") {
					cin >> piece;
					cin >> tile;
					//add the piece to a place on the board. This will then notify the view throught notify functions
					int row = getRow(tile);
					int col = getCol(tile);
					//Check for invalid input
					while (col == -1 || row == -1) {
						cout << "Invalid location. Please input location again" << endl;
						cin >> tile;
						int row = getRow(tile);
						int col = getCol(tile);
					}
					if (board->getPieceID(row, col) == 'K') {
						p1->incKings();
					}
					if (board->getPieceID(row,col) == 'k') {
						p2->incKings();
					}
					board->addPiece(row, col, piece);
					cout << "Piece " << piece << " was added." << endl;
					//re-display the board
					td->printBoard(cout);
				}
				else if (setupcmd == "-") {
					cin>>tile;
					int row = getRow(tile);
					int col = getCol(tile);
					while (col == -1 || row == -1) {
						cout << "Invalid location. Please input location again" << endl;
						cin >> tile;
						int row = getRow(tile);
						int col = getCol(tile);
					}
					if (board->getPieceID(row, col) == 'K') {
						p1->decKings();
					}
					if (board->getPieceID(row,col) == 'k') {
						p2->decKings();
					}
					//remove the piece from a place on the board. This will notify the view 
					if (board->removePiece(row, col)) {
						cout << "Piece at " << tile << " was removed." << endl;
					} else {
						cout << "A piece did not exist at that location." << endl;
					}
					//re-display board if we really want to....we don't have to
				}
				else if (setupcmd == "=") {
					string colour;
					cin>>colour;
					//make sure it's white or black
					while (colour != "white" && colour != "black") {
						cout << "Enter white or black" << endl;
						cin >>colour;
					}
					//Set the current player
					char c;
					if (colour == "white") {
						c = 'W';
					} else {
						c = 'B';
					}
					board->setCurrentPlayer(c);
					//Confirm that player has been changed
					cout << "It is now " << board->getCurrentPlayer() << "'s turn" << endl;
				}
				else if (setupcmd == "done") {
					if (p1->getKings() == 1 && p1->isCheck(p2->kingRow, p2->kingCol) == false && p2->getKings() == 1 && p2->isCheck(p2->kingRow, p2->kingCol) == false && board->validPawns() == true) {
						break;
					} else {
						cout << "This is not a valid board. Please fix before exiting setup." << endl;
					}
				}
			}
		}
		//MOVE--------------------------------------------------------
		else if (cmd == "move") {
			ingame = true;
			betweengame = false;
			if (board->getCurrentPlayer() == "P1" && p1->isHuman()== false) {
				Computer* pc = dynamic_cast<Computer*>(p1);
				pc->movePiece();
				cout << "Computer has moved." << endl;
			}
			else if (board->getCurrentPlayer() == "P2" && p2->isHuman() == false) {
				Computer* pc = dynamic_cast<Computer*>(p2);
				pc->movePiece();
				cout << "Computer has moved." << endl;
			}
			else {
				string pos1;
				string pos2;
				//read in location and new location
				cin >> pos1;
				cin >> pos2;
				int oldRow = getRow(pos1);
				int oldCol = getCol(pos1);
				//check valid input for pos1
				while (oldCol == -1 || oldRow == -1) {
						cout << "Invalid location for first location. Please input first location again" << endl;
						cin >> pos1;
						int oldRow = getRow(pos1);
						int oldCol = getCol(pos1);
				}
				int newRow = getRow(pos2);
				int newCol = getCol(pos2);
				//check valid input for pos2
				while (newCol == -1 || newRow == -1) {
						cout << "Invalid location for second location. Please input second location again" << endl;
						cin >> pos2;
						int newRow = getRow(pos2);
						int newCol = getCol(pos2);
				}
				if (board->getCurrentPlayer() == "P1") {
					Human* hm = dynamic_cast<Human*>(p1);
					//pc->movePiece();
					while (hm->movePiece(oldRow,oldCol,newRow,newCol) != true) {
						cout << "Retry with your piece." << endl;
						cin >> pos1;
						cin >> pos2;
						int oldRow = getRow(pos1);
						int oldCol = getCol(pos1);
						int newRow = getRow(pos2);
						int newCol = getCol(pos2);
					}
					cout << "Player 1 has moved." << endl;
				} else {
					Human* hm = dynamic_cast<Human*>(p1);
					//hm->movePiece();
					while (hm->movePiece(oldRow,oldCol,newRow,newCol) != true) {
						cout << "Retry with your piece." << endl;
						cin >> pos1;
						cin >> pos2;
						int oldRow = getRow(pos1);
						int oldCol = getCol(pos1);
						int newRow = getRow(pos2);
						int newCol = getCol(pos2);
					}
					cout << "Player 2 has moved." << endl;
				}
			}

			td->printBoard(cout);
			//graphics display
			//IsCheckmate and shit like that....call it
			if (p1->isCheckmate(p2->kingRow, p2->kingCol) == true) {
				cout << "Checkmate. Player 1 Wins" << endl;
				askPlayAgain();
				continue;
			}
			if (p2->isCheckmate(p1->kingRow, p1->kingCol) == true) {
				cout << "Checkmate. Player 2 Wins" << endl;
				askPlayAgain();
				continue;
			}
			if (p1->isCheck(p2->kingRow, p2->kingCol) == true) {
				cout << "Player 2 is in Check." << endl;
			}
			if (p2->isCheck(p1->kingRow, p2->kingCol) == true) {
				cout << "Player 1 is in Check." << endl;
			}
		}
	}
	//print score once CTRL-D has been pressed, not inputting anymore
	ingame=false;
	td->printScore(p1->getGamesWon(), p2->getGamesWon());
}

void Controller::notify(int oldRow, int oldCol, int newRow, int newCol, char c) {
	td->notify(oldRow, oldCol, newRow, newCol, c);
}
