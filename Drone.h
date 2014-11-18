//
//  Drone.h
//  cs115_assignment4
//
//  Created by Taylor Petrychyn on 2014-11-17.
//  Copyright (c) 2014 Taylor Petrychyn. All rights reserved.
//

#ifndef DRONE_H
#define DRONE_H

#include "Monster.h"

class Drone : public Monster {
    
    const int NORTH = 0;
    const int EAST = 1;
    const int SOUTH = 2;
    const int WEST = 3;

private:
    int direction = NORTH;
    
public:
    Drone();
    Drone(const Position& start);
    Drone(const Drone& original);
    virtual ~Drone();
    Drone& operator= (const Drone& original);
    virtual char getDisplayChar () const;
    //virtual Monster* getClone () const;
    virtual Position calculateMove (const Game& game,
                                    const Position& player_position);
};

#endif
