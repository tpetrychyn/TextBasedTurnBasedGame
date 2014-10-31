/*	main.cpp
	Taylor Petrychyn
	200339577
	CS115 Assignment 3
	Revision: September 12, 2014 - Completed majority of assignment
			  September 16, 2014 - Switched to using argv[1] for filename, added more failsafes
			  October 17, 2014 - Updated to handle classes, checks for walls when player moves
	Purpose: Given a map from a text file and a coordinate on that map, find the cost to traverse to the coordinate on the map
*/


#include "Game.h"
#include <iomanip>

int main(int argc, char* argv[])
{
	if (argc < 2) { //Check that an argument was passed for filename.txt
		cout << "Usage: main <filename.txt>" << endl;
		exit(1); //Otherwise exit
	}
    Game game(argv[1]);

	game.printCurrentState();
    
    char userInput = 'a';

	//Main loop 
	while (!game.isOver()) {
		cout << "Enter a command: ";
		cin.get(userInput);
		cin.ignore(256, '\n');
		if (userInput == 'N' || userInput == 'n')
			game.tryMoveNorth();
		else if (userInput == 'S' || userInput == 's')
			game.tryMoveSouth();
		else if (userInput == 'E' || userInput == 'e')
			game.tryMoveEast();
		else if (userInput == 'W' || userInput == 'w')
			game.tryMoveWest();
		else if (userInput == 'q' || userInput == 'Q')
			break;

		game.moveMonsters();
		game.printCurrentState();
    }
    game.printEndGameInfo();
    
	cout << "Press any key to terminate program" << endl;
    string ignoreLine;
	getline(cin, ignoreLine);
	return 0;
}
