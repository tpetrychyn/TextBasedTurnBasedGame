//
//  Attacker.h
//  cs115_assignment4
//
//  Created by Taylor Petrychyn on 2014-11-17.
//  Copyright (c) 2014 Taylor Petrychyn. All rights reserved.
//

#ifndef ATTACKER_H
#define ATTACKER_H

#include "Monster.h"

class Attacker : public Monster {

public:
    Attacker();
    Attacker(const Position& start);
    Attacker(const Attacker& original);
    virtual ~Attacker();
    Attacker& operator= (const Attacker& original);
    virtual char getDisplayChar () const;
    //virtual Monster* getClone () const;
    virtual Position calculateMove (const Game& game,
                                              const Position& player_position);
};

#endif
