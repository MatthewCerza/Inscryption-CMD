//Board.h

// CSCI 1300 Spring 2022
// Author: Matthew Cerza
// Recitation: 202 – Alex Ray
// Project 3

#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <vector>
#include "Card.h"
using namespace std;

class Board{
    private:
    //2*4 array of card objects
    Card board[2][4];
    //"scale" or score of the current round.
    int scale;


    public:
    int printBoard(int recur);
    void addCard(int row, int col, Card toAdd);
    void removeCard(int row, int col);
    int getScale();
    void setCardAt(int row, int col, Card givenCard);
    Card getCardAt(int row, int col);
    int giveDamage(int dmg);
    int takeDamage(int dmg);
    void cardTakesDamage(int row, int col, int dmg);
    void playEnemyStarterCards();
    void addEnemyCards(int difficulty);
    void startEnemyCards(int difficulty);
    Board();




};
#endif