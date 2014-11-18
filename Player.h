//
//  Player.h
//
//  Encapsulates a module to represent the player in a
//    grid-based game.
//

#ifndef PLAYER_H
#define PLAYER_H

#include "Position.h"

class Player
{
	private:
		int health;
		unsigned int damage;
		Position position;
		unsigned int score;
		unsigned int total_cost;
	public:
    
    //
    //  Player
    //
    //  Purpose: Default player constructor.
    //  Argument(s):
    //    N/A
    //  Precondition(s): N/A
    //  Returns: N/A
    //  Side Effect: Player player is initialized to have 0 values and -1, -1 position
    //
        Player();
    
		//
		//  Player
		//
		//  Purpose: To initialize a Player at a specific position.
		//  Argument(s):
		//    <1> start: The starting position for player
		//  Precondition(s): N/A
		//  Returns: N/A
		//  Side Effect: Player player is initialized to have default
		//               values and to be at the specified position.
		//
		Player(const Position& start);
    
        Player (const Player& original);
    
        ~Player ();  // empty
    
        Player& operator= (const Player& original);

		//
		//  isDead
		//
		//  Purpose: To determine if a Player is dead.
		//  Precondition(s): N/A
		//  Returns: Whether Player player is dead
		//  Side Effect: N/A
		//

		bool isDead () const;

		//
		//  getHealth
		//
		//  Purpose: To determine a Player's current health.
		//  Precondition(s): N/A
		//  Returns: Player player's current health.
		//  Side Effect: N/A
		//

		int getHealth () const;

		//
		//  getDamage
		//
		//  Purpose: To determine how much damage a Player deals when
		//           attacking.
		//  Precondition(s): N/A
		//  Returns: How much damage Player player deals when attacking.
		//  Side Effect: N/A
		//

		unsigned int getDamage () const;

		//
		//  getScore
		//
		//  Purpose: To determine a Player's current score.
		//  Precondition(s): N/A
		//  Returns: Player player's current score.
		//  Side Effect: N/A
		//

		unsigned int getScore () const;

		//
		//  getTotalMoveCost
		//
		//  Purpose: To determine a Player's total movement cost.
		//  Precondition(s): N/A
		//  Returns: Player player's total movement cost.
		//  Side Effect: N/A
		//

		unsigned int getTotalMoveCost () const;

		//
		//  getPosition
		//
		//  Purpose: To determine a Player's current position.
		//  Precondition(s): N/A
		//  Returns: Player player's current position.
		//  Side Effect: N/A
		//

		const Position& getPosition () const;

		//
		//  setPosition
		//
		//  Purpose: To change a Player's current position.
		//  Argument(s):
		//    <1> p: The new position
		//  Precondition(s): N/A
		//  Returns: N/A
		//  Side Effect: The current position of Player player is set to
		//               p.
		//

		void setPosition (const Position& p);

		//
		//  tryMoveNorth
		//  tryMoveSouth
		//  tryMoveEast
		//  tryMoveWest
		//
		//  Purpose: To move a player one position in the indicated
		//           direction.
		//  Precondition(s): N/A
		//  Returns: N/A
		//  Side Effect: If this move would put Player player outside of
		//               the level, there is no effect.  Otherwise,
		//               player is moved one position in the indicated
		//               direction.
		//

		void tryMoveNorth ();
		void tryMoveSouth ();
		void tryMoveEast  ();
		void tryMoveWest  ();

		//
		//  receiveDamage
		//
		//  Purpose: To reduce a Player's health.
		//    <1> amount: The amount to reduce player's health by
		//  Precondition(s): N/A
		//  Returns: N/A
		//  Side Effect: The health of Player player is reduced by
		//               amount.
		//

		void receiveDamage (unsigned int amount);

		//
		//  increaseScore
		//
		//  Purpose: To increase a Player's current score.
		//    <1> amount: The amount to increase player's current score
		//                by
		//  Precondition(s): N/A
		//  Returns: N/A
		//  Side Effect: The current score of Player player is increased
		//               by amount.
		//

		void increaseScore (unsigned int amount);

		//
		//  increaseTotalMoveCost
		//
		//  Purpose: To increase a Player's total move cost.
		//    <1> amount: The amount to increase player's total move
		//                cost by
		//  Precondition(s): N/A
		//  Returns: N/A
		//  Side Effect: The total move cost of Player player is
		//               increased by amount.
		//

		void increaseTotalMoveCost (unsigned int amount);

};

#endif