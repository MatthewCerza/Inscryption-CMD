//Card.h

// CSCI 1300 Spring 2022
// Author: Matthew Cerza
// Recitation: 202 – Alex Ray
// Project 3

#ifndef CARD_H
#define CARD_H
#include <iostream>
using namespace std;

class Card{
    private:
    int origHealth;
    int origAttack;
    int health;
    int attack;
    int cost;
    string sigil;
    string name;
    string bio;
    bool special;

    public:
    Card();
    Card(string givenName, int givenHealth, int givenAttack, string givenSigil, string givenBio, int givenCost, bool givenSpecial);
    int getHealth();
    int setHealth(int givenHealth);
    int getOrigHealth();
    int takeDmg(int damage);
    int getAttack();
    int getCost();
    void setCost(int givenCost);
    int changeAttack(int attackChange);
    void setAttack(int givenAttack);
    string getName();
    void setName(string givenName);
    string getBio();
    void setBio(string givenBio);
    string getSigil();
    void setSigil(string givenSigil);
    bool isSpecial();
    void setSpecial(bool givenSpecial);
    void printInfo();

};

#endif