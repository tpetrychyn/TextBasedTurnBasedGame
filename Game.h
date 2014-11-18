/*  Game.h
    Taylor Petrychyn
    200339577
    CS115 Assignment 4 
    Revision: November 4, 2014 - Created function headers
    Purpose: Holds prototypes for a Game class that holds the functions to calculate and output a 2d grid based console game
 
*/

#ifndef Game_h
#define Game_h

#include "Position.h"
#include "Level.h"
#include "Monster.h"
#include "Player.h"

class Game {
private:
    
    Level level;
    Player player;
    Monster**monsters;
    
    //
    //  playerCheck
    //
    //  Purpose: handles if a player moves onto a monster or onto an invalid location
    //  Argument(s):
    //    <1> lastPlayerPos: the position the player is moving from
    //  Precondition: N/A
    //  Returns: N/A
    //  Side Effect: player score may be increased, move cost may be increased, player may be set back to their previous position
    //
    /*Personal function so I didn't have to have 15 of the same lines in each tryMove function*/
    void playerCheck(const Position& lastPlayerPos);
    
public:
    //
    //  Game
    //
    //  Purpose: To initialize a game instance from a given input file
    //  Argument(s):
    //    <1> filename: the text file containing the level
    //  Precondition: N/A
    //  Returns: N/A
    //  Side Effect: level and player instances will be initialized
    //               and the monsters array will be populated with monster instances
    //
    Game (const string& filename);
    
    Game ();
    Game (const Game& original);
    ~Game ();
    Game& operator= (const Game& original);
    
    //
    //  isOver
    //
    //  Purpose: To determine if the game is over
    //  Argument(s): N/A
    //  Precondition: an instance of player
    //  Returns: true if player is dead or at the goal position
    //  Side Effect: N/A
    //
    bool isOver () const;
    
    //
    //  printCurrentState
    //
    //  Purpose: To update the game window with updated player and monster positions
    //  Argument(s): N/A
    //  Precondition: there are instances of player and level
    //  Returns: N/A
    //  Side Effect: N/A
    //
    void printCurrentState () const;
    
    //
    //  printEndGameInfo
    //
    //  Purpose: To show the final score and move cost of the player
    //  Argument(s): N/A
    //  Precondition: N/A
    //  Returns: N/A
    //  Side Effect: N/A
    //
    void printEndGameInfo () const;
    
    //
    //  tryMoveNorth
    //  tryMoveSouth
    //  tryMoveEast
    //  tryMoveWest
    //
    //  Purpose: To attempt to move the player in the desired direction by calling the player function
    //  Argument(s): N/A
    //  Precondition: N/A
    //  Returns: N/A
    //  Side Effect: Calls the playerCheck function
    //
    void tryMoveNorth ();
    void tryMoveSouth ();
    void tryMoveEast ();
    void tryMoveWest ();
    
    //
    //  moveMonsters
    //
    //  Purpose: Moves all the monsters in the grid by calculating a new location for each
    //  Argument(s): N/A
    //  Precondition: N/A
    //  Returns: N/A
    //  Side Effect: N/A
    //
    void moveMonsters ();
    
    //
    //  isBlockedForMonster
    //
    //  Purpose: checks if the position is invalid for a monster to move on to
    //  Argument(s):
    //    <1> p: position to check
    //  Precondition: N/A
    //  Returns: if a space is invalid for a monster: true
    //  Side Effect: N/A
    //
    bool isBlockedForMonster(const Position& p) const;
};

#endif
