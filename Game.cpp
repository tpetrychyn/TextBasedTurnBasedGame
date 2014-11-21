/*  Game.cpp
    Taylor Petrychyn
    200339577
    CS 115 Assignment 4
    Revision: November 4, 2014
    Purpose: To calculate and update the positions in a 2d grid based game
 */

#include "Game.h"
#include "Monster.h"
#include "Attacker.h"
#include "Sentry.h"
#include "Drone.h"
#include <iostream>

Game::Game (const string& filename) : level(filename), player(level.getPlayerStart()) {
    monsters=new Monster*[level.monsterCount];
    unsigned int currMonster = 0;
    for (int i=0;i<ROWS;i++) {
        for (int j=0;j<COLUMNS;j++) {
            if (level.getValue(toPosition(i, j)) == ATTACKER_START) {
                monsters[currMonster] = new Attacker(toPosition(i,j));
                currMonster++;
            } else if (level.getValue(toPosition(i, j)) == SENTRY_START) {
                monsters[currMonster] = new Sentry(toPosition(i,j));
                currMonster++;
            } else if (level.getValue(toPosition(i, j)) == DRONE_START) {
                monsters[currMonster] = new Drone(toPosition(i,j));
                currMonster++;
            }
        }
    }
}

Game::Game () : level(), player(level.getPlayerStart()) {
    monsters=new Monster*[level.monsterCount];
    unsigned int currMonster = 0;
    for (int i=0;i<ROWS;i++) {
        for (int j=0;j<COLUMNS;j++) {
            if (level.getValue(toPosition(i, j)) == ATTACKER_START) {
                monsters[currMonster] = new Attacker(toPosition(i,j));
                currMonster++;
            } else if (level.getValue(toPosition(i, j)) == SENTRY_START) {
                monsters[currMonster] = new Sentry(toPosition(i,j));
                currMonster++;
            } else if (level.getValue(toPosition(i, j)) == DRONE_START) {
                monsters[currMonster] = new Drone(toPosition(i,j));
                currMonster++;
            }
        }
    }
}

Game::Game (const Game& original) {
    player = original.player;
    monsters=new Monster*[level.monsterCount];
    for (int i=0;i<level.monsterCount;i++) {
        monsters[i] = original.monsters[i]->getClone();
    }
    level = original.level;
}

Game::~Game () {
    for (int i=0;i<level.monsterCount;i++)
        delete monsters[i];
    delete[] monsters;
}

Game& Game::operator= (const Game& original) {
    for (int i=0;i<level.monsterCount;i++) //Delete existing monsters and array
        delete monsters[i];
    delete[] monsters;
    
    monsters=new Monster*[level.monsterCount]; //Create new monsters array
    for (int i=0;i<level.monsterCount;i++) {
        monsters[i] = original.monsters[i]->getClone(); //set new monsters equal to original monsters
    }
    player = original.player;
    level = original.level;
    return *this;
}

void Game::playerCheck(const Position& lastPlayerPos) {
    if (level.isWall(player.getPosition()))
        player.setPosition(lastPlayerPos);
    for (int i=0;i<level.getMonsterCount();i++) {
        if (areEqual(player.getPosition(), monsters[i]->getPosition())) {
            monsters[i]->receiveDamage(player.getDamage());
            player.setPosition(lastPlayerPos);
            if (monsters[i]->isDead()) { //monsters died
                player.increaseScore(monsters[i]->getPoints()); //Add to players score
                monsters[i]->setPosition(toPosition(-1,-1));
            }
        }
    }
    if (!areEqual(player.getPosition(), lastPlayerPos)) //If player moved, increase cost
        player.increaseTotalMoveCost(level.getCost(player.getPosition()));
}

bool Game::isOver() const {
    if (player.isDead() || level.isGoalPosition(player.getPosition()))
        return true;
    return false;
}

void Game::printCurrentState() const {
    bool printedMon = false;
    cout << "+";
	for (int i=0;i<COLUMNS;i++) {
		cout << "-";
	}
	cout << "+";
	cout << endl;
    for (int i=0;i<ROWS;i++) {
		cout << "|";
        for (int j=0;j<COLUMNS;j++) {
            for (int h=0;h<level.getMonsterCount();h++) {
                if (i==monsters[h]->getPosition().row && j==monsters[h]->getPosition().column) { //Same but for target position
                    cout << monsters[h]->getDisplayChar();
                    printedMon = true;
                }
            }
            if (!printedMon) { //this is to check if we printed a monster, if we have we don't need to print a player or the map
                if (i==player.getPosition().row && j==player.getPosition().column) //Check if we are currently at our players position in the array
                    cout << 'P'; //If we are we print a 'P'
                else
                    cout << level.getDisplayChar(toPosition(i,j)); //Otherwise print the symbol for the level
            }
            printedMon = false;
        }
		cout << "|";
        cout << endl;
    }
	cout << "+";
	for (int i=0;i<COLUMNS;i++) {
		cout << "-";
	}
	cout << "+";
	cout <<endl;
    cout << "Health: " << player.getHealth() << "    Score: " << player.getScore() << "    Total move cost: " << player.getTotalMoveCost() << endl;
}

void Game::printEndGameInfo() const {
    cout << "<+> GAME OVER <+>" << endl;
	cout << "Final score: " << player.getScore() <<  endl << "Total move cost: " << player.getTotalMoveCost() << endl;
}


void Game::tryMoveNorth() {
    Position lastPlayerPos = player.getPosition();
    player.tryMoveNorth();
    playerCheck(lastPlayerPos);
}

void Game::tryMoveSouth() {
    Position lastPlayerPos = player.getPosition();
    player.tryMoveSouth();
    playerCheck(lastPlayerPos);
}

void Game::tryMoveEast() {
    Position lastPlayerPos = player.getPosition();
    player.tryMoveEast();
    playerCheck(lastPlayerPos);
}

void Game::tryMoveWest() {
    Position lastPlayerPos = player.getPosition();
    player.tryMoveWest();
    playerCheck(lastPlayerPos);
}

void Game::moveMonsters() {
    for (int i=0;i<level.getMonsterCount();i++) {
        Position lastmonstersPos = monsters[i]->getPosition();
        monsters[i]->setPosition(monsters[i]->calculateMove(*this, player.getPosition()));
        if (areEqual(player.getPosition(), monsters[i]->getPosition())) {
            player.receiveDamage(monsters[i]->getDamage());
            monsters[i]->setPosition(lastmonstersPos);
        }
    }
}

bool Game::isBlockedForMonster(const Position& p) const {
    if (level.isWall(p))
        return true;
    for(int i=0;i<level.getMonsterCount();i++) {
        if (areEqual(p, monsters[i]->getPosition())) {
            return true;
        }
    }
    return false;
}