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

Sentry::~Sentry() {}

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

Monster* Sentry::getClone() const {
    return new Sentry(*this);
}

Position Sentry::calculateMove(const Game &game, const Position &player_position) {
    if (calculateDistance(sentryStart, player_position) > 6)
        return calculateToPosition(game, sentryStart);
    return calculateToPosition(game, player_position);
}
