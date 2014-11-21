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
protected:
    int health;
    unsigned int damage;
    unsigned int points;
    Position position;
    
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
    Position calculateToPosition (const Game& game, const Position& player_position) const;
    
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
    // Monster
    //
    //  Purpose: To copy an existing Monster constructor
    //  Argument(s):
    //    <1> original: The monster to copy
    //  Precondition: N/A
    //  Returns: N/A
    //  Side Effect: The Monster monster is initialized to have
    //               default values and to be at position start.
    //
    Monster (const Monster& original);
    
    //
    // Monster
    //
    //  Purpose: virtual Monster destructor
    //  Argument(s):
    //    <1> original: The monster to copy
    //  Precondition: N/A
    //  Returns: N/A
    //  Side Effect: Deletes the monster instance
    //
    virtual ~Monster ();
    
    //
    // operator=
    //
    //  Purpose: override = operator to set one Monster to another
    //  Argument(s):
    //    <1> original: The monster to copy
    //  Precondition: N/A
    //  Returns: N/A
    //  Side Effect: Sets the object that called it to equal original
    //
    Monster& operator= (const Monster& original);
    
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
    //  setPosition
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
    //  receiveDamage
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
    //  getDisplayChar
    //
    //  Purpose: Purely virtual placeholder for child class function
    //  Argument(s): N/A
    //  Precondition: N/A
    //  Returns: N/A
    //  Side Effect: N/A
    //
    virtual char getDisplayChar () const = 0;
    
    //
    //  getClone
    //
    //  Purpose: Purely virtual placeholder for child class function
    //  Argument(s): N/A
    //  Precondition: N/A
    //  Returns: N/A
    //  Side Effect: N/A
    //
    virtual Monster* getClone () const = 0;
    
    //
    //  calculateMove
    //
    //  Purpose: Purely virtual placeholder for child class function
    //  Argument(s): N/A
    //  Precondition: N/A
    //  Returns: N/A
    //  Side Effect: N/A
    //
    virtual Position calculateMove(const Game& game,
                                   const Position& player_position) = 0;

};

#endif