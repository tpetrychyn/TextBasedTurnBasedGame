/*	Position.cpp
	Taylor Petrychyn
	200339577
	CS115 Assignment 3
	Revision: October 2, 2014 - Created function bodies
*/


#include "Position.h"

double calculateDistance(const Position& pOne, const Position& pTwo) {
	return sqrt(pow((double)pOne.row-(double)pTwo.row, 2) + pow((double)pOne.column-(double)pTwo.column, 2));
}

bool areEqual(const Position& pOne, const Position& pTwo) {
	return pOne.column == pTwo.column && pOne.row == pTwo.row;
}

Position toPosition(const unsigned int& row, const unsigned int& column) {
	Position p;
	p.row = row;
	p.column = column;
	return p;
}