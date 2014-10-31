/*	Position.h
	Taylor Petrychyn
	200339577
	CS115 Assignment 3
	Revision: October 2, 2014
	Purpose: Encapsulates a module to store a row and column for objects in a grid-based game
*/

#ifndef POSITION_H
#define POSITION_H

#include <cmath>
#include <cstdlib>

struct Position {
	unsigned int row;
	unsigned int column;
};

//
//  toPosition
//
//  Purpose: To create an instance of position with given row and columnm
//  Argument(s):
//    <1> row: value of the row
//    <2> column: value of the column
//  Precondition(s): N/A
//  Returns: a position with the given row and column values
//  Side Effect: N/A
//
Position toPosition(const unsigned int& row, const unsigned int& column);

//
//  areEqual
//
//  Purpose: To compare two positions
//  Argument(s):
//    <1> pOne: first position
//    <2> pTwo: second position
//  Precondition(s): N/A
//  Returns: true if the positions are equal, false if not
//  Side Effect: N/A
//
bool areEqual(const Position& pOne, const Position& pTwo);

//
//  calculateDistance
//
//  Purpose: To calculate the distance between two positions
//  Argument(s):
//    <1> pOne: first position
//    <2> pTwo: second position
//  Precondition(s): N/A
//  Returns: the euclydian distance between the two positions
//  Side Effect: N/A
//
double calculateDistance(const Position& pOne, const Position& pTwo);

#endif