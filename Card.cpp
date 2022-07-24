//Card.cpp

// CSCI 1300 Spring 2022
// Author: Matthew Cerza
// Recitation: 202 – Alex Ray
// Project 3


#include "Card.h"
#include <iostream>
using namespace std;

//default constructor that sets all values to 0
//The default constructor is called for empty spaces on a board
Card::Card(){
    origHealth = 0;
    origAttack = 0;
    health = 0;
    attack = 0;
    name = "";
    special = false;
    bio = "";
    sigil = "";
    cost = 0;
}
//paramaterized constructor that takes in stats for a given card
Card::Card(string givenName, int givenHealth, int givenAttack, string givenSigil, string givenBio, int givenCost, bool givenSpecial){
    origHealth = givenHealth;
    origAttack = givenAttack;
    health = givenHealth;
    attack = givenAttack;
    name = givenName;
    special = givenSpecial;
    bio = givenBio;
    sigil = givenSigil;
    cost = givenCost;
}
//returns health for a given card
int Card::getHealth(){
    return health;
}
//sets the health of a given card
int Card::setHealth(int givenHealth){
    health = givenHealth;
    return health;
}
//gets the original health of a creature (before a campfire)
int Card::getOrigHealth(){
    return origHealth;
} //decreases the health and returns the new value
int Card::takeDmg(int damage){
    health -= damage;
    return health;
}
int Card::getAttack(){
    return attack;
}
//changes the attack of a card by a given value, returns the new value
int Card::changeAttack(int attackChange){
    attack +=attackChange;
    return attack;
    
}
//getter methods
int Card::getCost(){
    return cost;
}

void Card::setCost(int givenCost){
    cost = givenCost;
}

string Card::getName(){
    return name;
}

void Card::setName(string givenName){
    name = givenName;
}

void Card::setAttack(int givenAttack){
    attack = givenAttack;
}

string Card::getBio(){
    return bio;
}

void Card::setBio(string givenBio){
    bio = givenBio;
}

string Card::getSigil(){
    return sigil;
}

void Card::setSigil(string givenSigil){
    sigil = givenSigil;
}
bool Card::isSpecial(){
    return special;
}

void Card::setSpecial(bool givenSpecial){
    special = givenSpecial;
}

void Card::printInfo(){
    cout <<  "Name: " << name << endl;
    cout << "Sigil: " << sigil << endl;
    cout << "Attack: " << attack << " Health: " << health << endl;
    cout << "Cost: " << cost << endl;
    cout << "Biography: " << bio << endl;
}