//
//  Sentry.cpp
//  cs115_assignment4
//
//  Created by Taylor Petrychyn on 2014-11-17.
//  Copyright (c) 2014 Taylor Petrychyn. All rights reserved.
//

#include "Sentry.h"

Sentry::Sentry() : Monster() {
    damage = 3;
    health = 20;
    points = 50;
    sentryStart = toPosition(0,0);
}

Sentry::Sentry(const Position& start) : Monster(start) {
    damage = 3;
    health = 20;
    points = 50;
    sentryStart = start;
}

Sentry::~Sentry() {
    damage = 0;
    health = 0;
    points = 0;
    position = toPosition(-1,-1);
}

Sentry::Sentry(const Sentry& original) {
    damage = original.damage;
    health = original.health;
    points = original.points;
    position = original.position;
}

Sentry& Sentry::operator=(const Sentry& original) {
    damage = original.damage;
    health = original.health;
    points = original.points;
    position = original.position;
    
    return *this;
}

char Sentry::getDisplayChar() const {
    return 'S';
}

/*Monster* Monster::getClone() const {
 Sentry* newMon;
 *newMon = new &Sentry(*this);
 return newMon;
 }*/

Position Sentry::calculateMove(const Game &game, const Position &player_position) {
    if (calculateDistance(sentryStart, player_position) > 6)
        return calculateToPosition(game, sentryStart);
    return calculateToPosition(game, player_position);
}
