//
//  Drone.cpp
//  cs115_assignment4
//
//  Created by Taylor Petrychyn on 2014-11-17.
//  Copyright (c) 2014 Taylor Petrychyn. All rights reserved.
//

#include "Drone.h"
#include "Game.h"

Drone::Drone() : Monster() {
    damage = 5;
    health = 50;
    points = 10;
}

Drone::Drone(const Position& start) : Monster(start) {
    damage = 5;
    health = 50;
    points = 10;
}

Drone::~Drone() {}

Drone::Drone(const Drone& original) {
    damage = original.damage;
    health = original.health;
    points = original.points;
    position = original.position;
}

Drone& Drone::operator=(const Drone& original) {
    damage = original.damage;
    health = original.health;
    points = original.points;
    position = original.position;
    
    return *this;
}

char Drone::getDisplayChar() const {
    return 'D';
}

Monster* Drone::getClone() const {
    return new Drone(*this);
}

Position Drone::calculateMove(const Game &game, const Position &player_position) {
    if (direction == NORTH) {
        if (!game.isBlockedForMonster(toPosition(position.row-1, position.column)))
            return calculateToPosition(game, toPosition(position.row-1, position.column));
        else
            direction = EAST;
    } else if (direction == EAST) {
        if (!game.isBlockedForMonster(toPosition(position.row, position.column+1)))
            return calculateToPosition(game, toPosition(position.row, position.column+1));
        else
            direction = SOUTH;
    } else if (direction == SOUTH) {
        if (!game.isBlockedForMonster(toPosition(position.row+1, position.column)))
            return calculateToPosition(game, toPosition(position.row+1, position.column));
        else
            direction = WEST;
    } else if (direction == WEST) {
        if (!game.isBlockedForMonster(toPosition(position.row, position.column-1)))
            return calculateToPosition(game, toPosition(position.row, position.column-1));
        else
            direction = NORTH;
    }
    return position;
}
