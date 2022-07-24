//Campfire.cpp

// CSCI 1300 Spring 2022
// Author: Matthew Cerza
// Recitation: 202 – Alex Ray
// Project 3
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Card.h"
#include "Campfire.h"
using namespace std;

//Sets the type of campfire between health and attack randomly
//UNFINISHED
Campfire::Campfire(){
    double random = rand();
    random = rand();
    random = random/RAND_MAX;
    if (random>=0.5){
        type = "Health";
    } else {
        type = "Attack";
    }

}

string Campfire::getType(){
    return type;
}

//When given a card, upgrade it's attack by one and return one.
int Campfire::chanceAttkUpgrade(Card givenCard){
    cout << "The survivors were right about the flames. They had enhanced the "<< givenCard.getName() << "'s "<<type<<"." << endl;
    return 1;
    
}

//When given a card, have a 50% chance of upgrading it's attack, and a 50% chance of destroying the card and removing it from the player's hand
//returns 1 if successful, returns 0 to destroy the card
int Campfire::chanceAttkUpgrade2(Card givenCard){
    double random = rand();
    random = rand();
    random = random/RAND_MAX;
    if (random>=0.5){
        return 0;
    } else {
        return 1;
    }
    
}

//When given a card, upgrade it's health by two and return two.
int Campfire::chanceHealthUpgrade(Card givenCard){
    cout << "The survivors were right about the flames. They had enhanced the "<< givenCard.getName() << "'s "<<type<<"." << endl;
    return 2;
}

//When given a card, have a 50% chance of upgrading it's health, and a 50% chance of destroying the card and removing it from the player's hand
//returns 1 if successful, returns 0 to destroy the card
int Campfire::chanceHealthUpgrade2(Card givenCard){
    double random = rand();
    random = rand();
    random = random/RAND_MAX;
    if (random>=0.5){
        return 0;
    } else {
        return 2;
    }
}