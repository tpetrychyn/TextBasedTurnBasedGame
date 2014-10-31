//
//  Game.h
//  cs115_assignment4
//
//  Created by Taylor Petrychyn on 2014-10-22.
//  Copyright (c) 2014 Taylor Petrychyn. All rights reserved.
//

#ifndef Game_h
#define Game_h

#include "Position.h"
#include "Level.h"
#include "Monster.h"
#include "Player.h"

const int MONSTER_COUNT = 100;

class Game {
private:
    
    Level level;
    Player player;
    Monster monsters[MONSTER_COUNT];
    
public:
    Game (const string& filename);
    bool isOver () const;
    void printCurrentState () const;
    void printEndGameInfo () const;
    void tryMoveNorth ();
    void tryMoveSouth ();
    void tryMoveEast ();
    void tryMoveWest ();
    void moveMonsters ();
    void playerCheck(const Position& lastPlayerPos);
    bool isBlockedForMonster(const Position& p) const;
};

#endif
