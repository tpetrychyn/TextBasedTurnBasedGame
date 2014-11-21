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
    
    //
    //  Attacker
    //
    //  Purpose: Default constructor
    //  Argument(s): N/A
    //  Precondition: N/A
    //  Returns: an attacker
    //  Side Effect: N/A
    //
    Attacker();
    
    //
    //  Attacker
    //
    //  Purpose: creates an attacker at a position
    //  Argument(s):
    //      <1> start: the position to create the monster at
    //  Precondition: N/A
    //  Returns: N/A
    //  Side Effect: N/A
    //
    Attacker(const Position& start);
    
    //
    //  Attacker
    //
    //  Purpose: creates an attacker at a position
    //  Argument(s):
    //      <1> original: the attacker to create a copy of
    //  Precondition: N/A
    //  Returns: N/A
    //  Side Effect: N/A
    //
    Attacker(const Attacker& original);
    
    //
    //  Attacker
    //
    //  Purpose: creates an attacker at a position
    //  Argument(s):
    //      <1> start: the position to create the monster at
    //  Precondition: N/A
    //  Returns: N/A
    //  Side Effect: N/A
    //
    virtual ~Attacker();
    
    //
    //  Attacker operator=
    //
    //  Purpose: creates an attacker at a position
    //  Argument(s):
    //      <1> original: your original monster
    //  Precondition: N/A
    //  Returns: N/A
    //  Side Effect: N/A
    //
    Attacker& operator= (const Attacker& original);
    
    //
    //  getDisplayChar
    //
    //  Purpose: to return the symbol corresponding to the monster
    //  Argument(s): N/A
    //  Precondition: N/A
    //  Returns: character
    //  Side Effect: N/A
    //
    virtual char getDisplayChar () const;
    
    //
    //  getClone
    //
    //  Purpose: makes a new monster pointer equal to current monster
    //  Argument(s): N/A
    //  Precondition: N/A
    //  Returns: character
    //  Side Effect: N/A
    //
    virtual Monster* getClone () const;
    
    //
    //  calculateMove
    //
    //  Purpose: determines the next space the monster should move to
    //  Argument(s): N/A
    //  Precondition: N/A
    //  Returns: new position of the monster
    //  Side Effect: N/A
    //
    virtual Position calculateMove (const Game& game,
                                              const Position& player_position);
};

#endif
