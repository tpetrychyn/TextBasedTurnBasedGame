//
//  Attacker.cpp
//  cs115_assignment4
//
//  Created by Taylor Petrychyn on 2014-11-17.
//  Copyright (c) 2014 Taylor Petrychyn. All rights reserved.
//

#include "Attacker.h"

Attacker::Attacker() : Monster() {
    damage = 2;
    health = 10;
    points = 20;
}

Attacker::Attacker(const Position& start) : Monster(start) {
    damage = 2;
    health = 10;
    points = 20;
}

Attacker::~Attacker() {
}

Attacker::Attacker(const Attacker& original) {
    damage = original.damage;
    health = original.health;
    points = original.points;
    position = original.position;
}

Attacker& Attacker::operator=(const Attacker& original) {
    damage = original.damage;
    health = original.health;
    points = original.points;
    position = original.position;
    
    return *this;
}

char Attacker::getDisplayChar() const {
    return 'A';
}

Monster* Attacker::getClone() const {
    return new Attacker(*this);
}

Position Attacker::calculateMove(const Game &game, const Position &player_position) {
    return calculateToPosition(game, player_position);
}

