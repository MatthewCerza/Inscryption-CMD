//Player.h

// CSCI 1300 Spring 2022
// Author: Matthew Cerza
// Recitation: 202 – Alex Ray
// Project 3

#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <vector>
#include "Card.h"

using namespace std;

class Player{
    private:
    //the "hand" of cards/creatures following the player
    vector<Card> deck;
    vector<Card> hand;
    
    string name;



    public:
    //constructors
    Player();
    Player(string givenName);
    //getters and setters
    vector <Card> getHand();
    vector<Card> getDeck();
    void setName(string givenName);
    string getName();
    void addCardDeck(Card givenCard);
    void addCardHand(Card givenCard);
    int removeCardDeck(int givenIndex);
    int removeCardHand(int givenIndex);
    void printDeck();
    void printHand();
    void clearHand();
    void campHealthBuff(int deckIndex);
    void campAttackBuff(int deckIndex);


};

#endif