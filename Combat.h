//Combat.h

// CSCI 1300 Spring 2022
// Author: Matthew Cerza
// Recitation: 202 – Alex Ray
// Project 3

#ifndef COMBAT_H
#define COMBAT_H
#include <iostream>
#include "Board.h"
#include "Card.h"
using namespace std;

class Combat{
    private:
    //int scale;
    Board board;

    public:
    //Returns the amount of damage to deal to the computer
    Combat(Board currentBoard);
    //int attack(Card attacker, Card defender);
    void playersTurn();
    void enemysTurn();
    int getScale();
    Board returnBoard();
    void addEnemyCards(int difficulty);
    void startEnemyCards(int difficulty); 
    void setCardAt(int row, int col, Card givenCard);
};

#endif