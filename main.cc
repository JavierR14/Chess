#include "controller.h"
#include <iostream>
using namespace std;

/*
 * TODO: update main function to take argument "-graphics" for part b. 
 * If -graphics argument is provided, forward this to the controller
 */
int main ( int argc, char *argv[] ) {
	string filename;
	Controller c;
	if (argc == 2) {
		filename = argv[1];
		c.playGame(filename);
	} else {
		c.playGame(filename);
	}
	

}

