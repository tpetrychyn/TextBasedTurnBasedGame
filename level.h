/*	level.h
	Taylor Petrychyn
	200339577
	CS115 Assignment 2
	Revision: September 12, 2014 - Completed majority of assignment
			  October 2, 2014 - Modified for assignment 2
	Purpose: Holds Prototypes and declarations for the level
*/

#ifndef LEVEL_H
#define LEVEL_H

#include "Position.h"

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

const int ROWS = 20;
const int COLUMNS = 60;
const int EMPTY = 0;
const int ROCKY = 1;
const int ROUGH = 2;
const int MONSTER_START = 3;
const int PLAYER_START = 4;
const int WALL = 5;
const int GOAL = 6;

//
//  calculateMove
//
//  Purpose: To calculate a monster's next move in the game.
//  Precondition: N/A
//  Returns: The new position for Monster monster.  If this is
//           the same as the player's position, monster is
//           attacking the player instead of moving.
//  Side Effect: N/A
//

class Level {

private:
	unsigned int level[ROWS][COLUMNS];
    unsigned int monsterCount;

public:
	//
	//	Level constructor
	//
	//  Purpose: to initalize a new Level object
	//	Arguments:
	//		<1> filename: name of the file containing the level data
	//	Precondition: N/A
	//	Side Effect: Modifies the level objects level[][] array
	//
	Level (const string& filename);

	//
	//	getPlayerStart
	//
	//  Purpose: to find the player symbols position in the level file
	//	Precondition: N/A
	//	Returns: A position object with the players row and column
	//	Side Effect: N/A
	//
	Position getPlayerStart () const;

	//
	//	getCost
	//
	//  Purpose: to get the cost of the position on the level
	//	Arguments:
	//		<1> p: the position to check the cost of 
	//	Precondition: N/A
	//	Returns: An unsigned int containing the cost of the position
	//	Side Effect: N/A
	//
	unsigned int getCost (const Position& p) const;

	//
	//	isWall
	//
	//  Purpose: to check if the given position contains a wall
	//	Arguments:
	//		<1> p: the position to to check for a wall
	//	Precondition: N/A
	//	Returns: true of false if there is a wall in the given position
	//	Side Effect: N/A
	//
	bool isWall (const Position& p) const;
    
    //
    //  isGoalPosition
    //
    //  Purpose: to determine if the player is on the goal position
    //  Arguments
    //      <1> p: players position
    //  Precondition N/A
    //  Returns: whether the player is on the position or not
    //  Side effect: N/A
    //
    bool isGoalPosition(const Position& p) const;
    
    //
    //  getMonsterCount
    //
    //  Purpose: to return the number of monsters in the level
    //  Arguments: N/A
    //  Returns: number of monsters in the level
    //  Side effect: N/A
    unsigned int getMonsterCount() const;
    
    //
    //  getValue
    //
    unsigned int getValue(const Position& p) const;
    
    char getDisplayChar(const Position& p) const;

};

#endif