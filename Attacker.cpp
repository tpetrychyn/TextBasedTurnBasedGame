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
    damage = 0;
    health = 0;
    points = 0;
    position = toPosition(-1,-1);
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

/*Monster* Monster::getClone() const {
    Attacker* newMon;
    *newMon = new &Attacker(*this);
    return newMon;
}*/

Position Attacker::calculateMove(const Game &game, const Position &player_position) {
    return calculateToPosition(game, player_position);
}


/*
 Attacker();
 Attacker(const Position& start);
 Attacker(const Attacker& original);
 virtual ~Attacker();
 Attacker& operator= (const Attacker& original);
 virtual char getDisplayChar () const;
 virtual Monster* getClone () const;
 virtual Position calculateMove (const Game& game,
 const Position& player_position);
 */

