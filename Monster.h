//
//  Monster.h
//
//  Encapsulates a module to represent an (enemy) monster in a
//    grid-based game.
//

#ifndef MONSTER_H
#define MONSTER_H

#include "Position.h"

class Game;
class Monster
{
private:
    int health;
    unsigned int damage;
    Position position;
    unsigned int points;
public:

//Default constructor
Monster();

//
// Monster
//
//  Purpose: To initialize a monster at a specific position.
//  Argument(s):
//    <1> start: The starting position for the monster
//  Precondition: N/A
//  Returns: N/A
//  Side Effect: The Monster monster is initialized to have
//               default values and to be at position start.
//

Monster(const Position& start);

//
// isDead
//
//  Purpose: To determine if a monster is dead.
//  Precondition: N/A
//  Returns: Whether the Monster is dead.
//  Side Effect: N/A
//

bool isDead () const;

//
//  getDamage
//
//  Purpose: To determine how much damage a Monster deals when
//           attacking.
//  Precondition: N/A
//  Returns: How much damage Monster monster deals when
//           attacking.
//  Side Effect: N/A
//

unsigned int getDamage () const;

//
//  getPoints
//
//  Purpose: To determine how many points are awarded for
//           killing a monster.
//  Precondition: N/A
//  Returns: How many points are awarded for killing Monster
//           monster.
//  Side Effect: N/A
//

unsigned int getPoints () const;

//
//  getPosition
//
//  Purpose: To determine a Monster's current position.
//  Precondition: N/A
//  Returns: Monster monster's current position.
//  Side Effect: N/A
//

const Position& getPosition () const;

//
//  monsterSetPosition
//
//  Purpose: To change a Monster's current position.
//  Argument(s):
//    <1> p: The new position
//  Precondition: N/A
//  Returns: N/A
//  Side Effect: The current position of Monster monster is set
//               to p.
//

void setPosition (const Position& p);

//
//  monsterReceiveDamage
//
//  Purpose: To reduce an Monster's health.
//  Argument(s):
//    <1> amount: The amount to reduce the Monster's health by
//  Precondition: N/A
//  Returns: N/A
//  Side Effect: Monster monster's health is reduced by amount.
//

void receiveDamage (unsigned int amount);

//
//  monsterCalculateMove
//
//  Purpose: To calculate a monster's next move in the game.
//  Argument(s):
//    <1> Level: the current level the monster is on
//    <2> player_position: The player's current position
//  Precondition: N/A
//  Returns: The new position for Monster monster.  If this is
//           the same as the player's position, monster is
//           attacking the player instead of moving.
//  Side Effect: N/A
//

Position calculateMove (const Game& game, const Position& player_position) const;

};

#endif