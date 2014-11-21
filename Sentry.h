//
//  Sentry.h
//  cs115_assignment4
//
//  Created by Taylor Petrychyn on 2014-11-17.
//  Copyright (c) 2014 Taylor Petrychyn. All rights reserved.
//

#ifndef SENTRY_H
#define SENTRY_H

#include "Monster.h"

class Sentry : public Monster {
    
private:
    Position sentryStart;
    
public:
    //
    // Refer to Attacker.h for relevant comments
    //
    
    Sentry();
    Sentry(const Position& start);
    Sentry(const Sentry& original);
    virtual ~Sentry();
    Sentry& operator= (const Sentry& original);
    virtual char getDisplayChar () const;
    virtual Monster* getClone () const;
    virtual Position calculateMove (const Game& game,
                                    const Position& player_position);
};

#endif
