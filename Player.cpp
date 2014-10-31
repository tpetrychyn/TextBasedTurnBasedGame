/*	Player.cpp
	Taylor Petrychyn
	200339577
	CS115 Assignment 3
	Revision: September 29, 2014
			October 17, 2014
	Purpose: To handle player objects in the game
*/

#include "Position.h"
#include "Level.h"
#include "Player.h"

const unsigned int STARTING_HEALTH = 40;
const unsigned int DAMAGE = 2;

Player::Player(const Position& start) {
	health = STARTING_HEALTH;
	damage = DAMAGE;
	score = 0;
	total_cost = 0;
	position = start;
}

bool Player::isDead () const {
	return health <= 0;
}

int Player::getHealth () const {
	return health;
}

unsigned int Player::getDamage () const {
	return damage;
}

unsigned int Player::getScore () const {
	return score;
}

unsigned int Player::getTotalMoveCost () const {
	return total_cost;
}

const Position& Player::getPosition () const {
	return position;
}

void Player::setPosition (const Position& p) {
	position = p;
}

void Player::tryMoveNorth () {
	if (position.row > 0) {
		position.row--;
	}
}

void Player::tryMoveSouth () {
	if (position.row<ROWS-1) { //Check we aren't on the edge, if we were we would go out of bounds
		position.row++;
	}
}
void Player::tryMoveEast  () {
	if (position.column<COLUMNS-1) {
		position.column++;
	}
}
void Player::tryMoveWest  () {
	if (position.column>0) {
		position.column--;
	}
}

void Player::receiveDamage (unsigned int amount) {
	health -= amount;
}

void Player::increaseScore (unsigned int amount) {
	score += amount;
}

void Player::increaseTotalMoveCost (unsigned int amount) {
	total_cost += amount;
}