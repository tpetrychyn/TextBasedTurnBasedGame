/*	Monster..cpp
	Taylor Petrychyn
	200339577
	CS115 Assignment 3
	Revision: September 29, 2014 - Created function bodies
			October 17, 2014 - Converted to class, added finding walls
	Purpose: Handles level generation and functions
*/


#include "Level.h"
#include "Position.h"
#include "Monster.h"
#include "Game.h"

 
const unsigned int STARTING_HEALTH = 20;
const unsigned int DAMAGE = 3;
const unsigned int POINTS = 50;

Monster::Monster() {
	health = 0;
	damage = 0;
	points = 0;
	position = toPosition(-1, -1);
}

Monster::Monster(const Position& start) {
	health = STARTING_HEALTH;
	damage = DAMAGE;
	points = POINTS;
	position = start;
}

Monster::Monster (const Monster& original){
    health = original.health;
    damage = original.damage;
    points = original.points;
    position = original.position;
}

Monster& Monster::operator= (const Monster& original){
    health = original.health;
    damage = original.damage;
    points = original.points;
    position = original.position;
    return *this;
}

Monster::~Monster() {
    health = 0;
    damage = 0;
    points = 0;
    position = toPosition(-1,-1);
}

bool Monster::isDead () const {
	return health <= 0;
}

unsigned int Monster::getDamage () const {
	return damage;
}

unsigned int Monster::getPoints () const {
	return points;
}

const Position& Monster::getPosition () const {
	return position;
}

void Monster::setPosition (const Position& p) {
	position = p;
}

void Monster::receiveDamage (unsigned int amount) {
	health -= amount;
}

Position Monster::calculateToPosition (const Game& game, const Position& player_position) const {
	// Examine the four possible locations for the monster to move,
	// one to each of north, south, east, and west, to see which
	// is closest to the target
	Position new_position = position;
	double new_distance = calculateDistance(position, player_position);

	Position temp_position;
	double temp_distance;

	if (position.row > 0)
	{
		temp_position = 
			toPosition(position.row - 1, position.column);
		temp_distance = calculateDistance(temp_position, player_position);
		if (!game.isBlockedForMonster(temp_position)) { //Check for wall
			if (temp_distance < new_distance)
			{
				new_position = temp_position;
				new_distance = temp_distance;
			}
		}
	}
	if (position.row  < (ROWS - 1))
	{
		temp_position = 
			toPosition(position.row + 1, position.column);
		temp_distance = calculateDistance(temp_position, player_position);
		if (!game.isBlockedForMonster(temp_position)) {
			if (temp_distance < new_distance)
			{
				new_position = temp_position;
				new_distance = temp_distance;
			}
		}
	}
	if (position.column > 0)
	{
		temp_position = 
			toPosition(position.row, position.column - 1);
		temp_distance = calculateDistance(temp_position, player_position);
		if (!game.isBlockedForMonster(temp_position)) {
			if (temp_distance < new_distance)
			{
				new_position = temp_position;
				new_distance = temp_distance;
			}
		}
	}
	if (position.column < (COLUMNS - 1))
	{
		temp_position = 
			toPosition(position.row, position.column + 1);
		temp_distance = calculateDistance(temp_position, player_position);
		if (!game.isBlockedForMonster(temp_position)) {
			if (temp_distance < new_distance)
			{
				new_position = temp_position;
				new_distance = temp_distance;
			}
		}
	}
	return new_position;
}
