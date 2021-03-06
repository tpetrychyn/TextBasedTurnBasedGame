/*	level.cpp
	Taylor Petrychyn
	200339577
	CS115 Assignment 4
	Revision: September 12, 2014 - Completed majority of assignment
			  September 16, 2014 - Added more comments
			  October 17, 2014 - Changed to class, added walls
              November 4, 2014 - Support for multiple monsters, fixed filename entering
	Purpose: Handles level generation and functions
*/

#include "level.h"

char levelSymbols[] = {'.','^',':','S','P', '#', '*', 'A', 'D'};
char outLevelSymbols[] = {' ','^',':',' ',' ', '#', '*', ' ', ' '};
int traverseCost[] = {1,2,4,1,1,1000,0,1,1};

Level::Level(const string& filename) {
    monsterCount = 0; //initialize count to 0 when a new level is called
	ifstream inData;
	inData.open(filename.c_str());
    string file = filename;
    while (!inData)
    {
        cout << "Can't find \"" << file << "\"" << endl;
        cout << "Please enter a filename:";
		cin >> file;
		cin.ignore(256, '\n');
		inData.open(file.c_str());
    }
    char x;
    for (int i=0;i<ROWS;i++) {
        for (int j=0;j<COLUMNS;j++) {
            inData >> x;
            for (int n=0;n<sizeof(levelSymbols)/sizeof(levelSymbols[0]);n++) {
                if (x==levelSymbols[n]) { //Search the levelSymbols array for a match from the map
                    level[i][j] = n; //Replace the symbol with the index of the array
                    if (level[i][j] == ATTACKER_START || level[i][j] == SENTRY_START || level[i][j] == DRONE_START)
                        monsterCount++;
					break;
				} else
					level[i][j] = 0; //Failsafe incase a non-supported symbol is entered we replace it with a blank
            }
        }
    }
}

Level::Level() {
    monsterCount = 0;
    for (int i=0;i<ROWS;i++) {
        for (int j=0;j<COLUMNS;j++) {
            level[i][j] = 0;
        }
    }
}

Level::Level (const Level& original) {
    for (int i=0;i<ROWS;i++) {
        for (int j=0;j<COLUMNS;j++) {
            level[i][j] = original.level[i][j];
        }
    }
    monsterCount = original.monsterCount;
}

Level::~Level() {}

Level& Level::operator= (const Level& original) {
    for (int i=0;i<ROWS;i++) {
        for (int j=0;j<COLUMNS;j++) {
            level[i][j] = original.level[i][j];
        }
    }
    monsterCount = original.monsterCount;
    return *this;
}

void Level::init (const string& filename) {
    Level(filename.c_str());
}

Position Level::getPlayerStart() const {
    Position p;
	for (int i=0;i<ROWS;i++) {
        for (int j=0;j<COLUMNS;j++) {
			if (level[i][j] == PLAYER_START) { //Check each position for a 3
				p = toPosition(i, j);
				return p;
			}
        }
    }
    return p;
}

unsigned int Level::getCost(const Position& p) const {
	return traverseCost[level[p.row][p.column]];
}

bool Level::isWall(const Position& p) const {
    if (p.row > 0 && p.row < ROWS && p.column > 0 && p.column < COLUMNS) //this is to check if a monster is in the game bounds
        return (level[p.row][p.column] == WALL);
    return true; //if a monster is not in the game bounds we say it is on a wall and don't let it move, used for dead monsters
}

bool Level::isGoalPosition(const Position& p) const {
    return (level[p.row][p.column] == GOAL);
}

unsigned int Level::getMonsterCount() const {
    return monsterCount;
}

unsigned int Level::getValue(const Position& p) const {
    return level[p.row][p.column];
}

char Level::getDisplayChar(const Position& p) const {
    return outLevelSymbols[getValue(p)];
}