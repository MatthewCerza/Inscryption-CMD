//Campfire.h

// CSCI 1300 Spring 2022
// Author: Matthew Cerza
// Recitation: 202 – Alex Ray
// Project 3

#ifndef CAMPFIRE_H
#define CAMPFIRE_H
#include <iostream>
#include <vector>
#include "Card.h"
using namespace std;


class Campfire{
    private:
    string type;
    //0 = Health, 1 = Attack
    
    public:
    Campfire();
    int chanceAttkUpgrade(Card givenCard);
    int chanceAttkUpgrade2(Card givenCard);
    int chanceHealthUpgrade(Card givenCard);
    int chanceHealthUpgrade2(Card givenCard);
    string getType();

};

#endif