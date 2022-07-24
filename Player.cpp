//Player.h

// CSCI 1300 Spring 2022
// Author: Matthew Cerza
// Recitation: 202 – Alex Ray
// Project 3
#include <iostream>
#include <vector>
#include "Player.h"
using namespace std;

//new player object with a blank name
Player::Player(){
    name = "";
}

//new player object with the given name
Player::Player(string givenName){
    name = givenName;
}

//returns a vector of card objects containing all cards useable by the player
vector<Card> Player::getDeck(){
    return deck;
}

//returns a vector of card objects containing all cards useable by the player
vector<Card> Player::getHand(){
    return hand;
}

//returns the player's name
string Player::getName(){
    return name;
}
//set the player's name
void Player::setName(string givenName){
    name = givenName;
}
//Adds a new card to the player's deck. 
void Player::addCardDeck(Card givenCard){
    deck.push_back(givenCard);
}

//Adds a new card to the player's deck. 
void Player::addCardHand(Card givenCard){
    hand.push_back(givenCard);
}

//Removes a card at a given index of a deck
//Returns 1 if successful, return 0 if out of the index of the deck.
int Player::removeCardDeck(int givenIndex){
    if (givenIndex<0||givenIndex>=deck.size()){
        return 0;
    } else {
        deck.erase(deck.begin()+givenIndex);
        return 1;
    }
}

//Removes a card at a given index of a Hand
//Returns 1 if successful, return 0 if out of the index of the Hand.
int Player::removeCardHand(int givenIndex){
    if (givenIndex<0||givenIndex>=hand.size()){
        return 0;
    } else {
        hand.erase(hand.begin()+givenIndex);
        return 1;
    }
}

void Player::printDeck(){
    for (int i=0; i<deck.size(); i++){
        if (deck[i].getSigil()==""){
            cout << "Name: " << deck[i].getName() << "  Attack: " << deck[i].getAttack() << "  Health: " << deck[i].getHealth() << "  Cost: " << deck[i].getCost() << "  Sigil: None" << endl;
        } else {
            cout << "Name: " << deck[i].getName() << "  Attack: " << deck[i].getAttack() << "  Health: " << deck[i].getHealth() << "  Cost: " << deck[i].getCost() << "  Sigil: " << deck[i].getSigil() << endl;
        }
    }
}

void Player::printHand(){
    for (int i=0; i<hand.size(); i++){
        if (hand[i].getSigil()==""){
            cout << "Name: " << hand[i].getName() << "  Attack: " << hand[i].getAttack() << "  Health: " << hand[i].getHealth() << "  Cost: " << hand[i].getCost() << "  Sigil: None" << endl;
        } else {
            cout << "Name: " << hand[i].getName() << "  Attack: " << hand[i].getAttack() << "  Health: " << hand[i].getHealth() << "  Cost: " << hand[i].getCost() << "  Sigil: " << hand[i].getSigil() << endl;
        }
    }
}

void Player::clearHand(){
    hand.clear();
}

void Player::campHealthBuff(int deckIndex){
    deck[deckIndex].setHealth(deck[deckIndex].getHealth()+2);
    
}

void Player::campAttackBuff(int deckIndex){
    deck[deckIndex].changeAttack(1);

}