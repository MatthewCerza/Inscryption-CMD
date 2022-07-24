//Combat.cpp

// CSCI 1300 Spring 2022
// Author: Matthew Cerza
// Recitation: 202 – Alex Ray
// Project 3

#include <iostream>
#include "Card.h"
#include "Combat.h"
using namespace std;

//Combat scenarios need a board to be initiated, so this is the only constructor
Combat::Combat(Board currentBoard){
    board = currentBoard;

}
//return the current board
Board Combat::returnBoard(){
    return board;
}

//Goes from left to right and has each creature on the player's side attack an opposing creature, or score points.
//Partially Finished
void Combat::playersTurn(){ 
    for (int i=0; i<4; i++){
        if (board.getCardAt(1,i).getAttack()>0){
            cout << "Attacker: " << board.getCardAt(1,i).getName() << " Defender: " << board.getCardAt(0,i).getName() << endl;
        }
        if (board.getCardAt(1,i).getHealth()>0){
            if ((board.getCardAt(0,i).getHealth()<=0)||(board.getCardAt(0,i).getSigil()=="Waterborne")||(board.getCardAt(1,i).getSigil()=="Airborne")){
            //Attacking the opponent directly
                if (board.getCardAt(1,i).getAttack()>0){
                    cout << board.getCardAt(1,i).getName() << " deals " << board.getCardAt(1,i).getAttack() << " damage directly." << endl;
                }
                
                board.giveDamage(board.getCardAt(1,i).getAttack());
            } else {
                if (board.getCardAt(1,i).getSigil()=="Touch of Death"){
                    //cout << "Touch of death creature detected" << endl;
                    //board.getCardAt(0,i).setHealth(0);
                    //cout << endl << "HEALTH OF ELK IS " << board.getCardAt(0,i).getHealth() << endl << endl;
                    board.cardTakesDamage(0,i,999);
                    //cout << endl << "HEALTH OF ELK IS " << board.getCardAt(0,i).getHealth() << endl << endl;
                } else {
                    //cout << "Normal creature attacking other creature" << endl;
                    if (board.getCardAt(0,i).getHealth()>board.getCardAt(1,i).getAttack()){
                        //board.getCardAt(0,i).takeDmg(board.getCardAt(1,i).getAttack());
                        //int difference = (board.getCardAt(1,i).getAttack()-board.getCardAt(0,i).getHealth());
                        board.cardTakesDamage(0,i,board.getCardAt(1,i).getAttack());
                    } else {
                        board.cardTakesDamage(0,i,999);
                    }
                }
            } 


        }
        
    }
    for (int i=0; i<4; i++){
        Card blank;
        //cout << "Health of " << board.getCardAt(0,i).getName() << " is " << board.getCardAt(0,i).getHealth() << endl;
        if (board.getCardAt(0,i).getHealth()<=0){
            
            //cout << "Set health of creature at index " << i << " to 0." << endl;
            board.setCardAt(0,i,blank);
        }
        
    }
}
//The same as the player's turn, but for the computer controlled enemy
//Goes from left to right and has each creature on the computer's side attack an opposing creature, or score points.
//Partially Finished
void Combat::enemysTurn(){
    for (int i=0; i<4; i++){
        if (board.getCardAt(0,i).getAttack()>0){
            cout << "Attacker: " << board.getCardAt(0,i).getName() << " Defender: " << board.getCardAt(1,i).getName() << endl;
        }
        if (board.getCardAt(0,i).getHealth()>0){
            if ((board.getCardAt(1,i).getHealth()<=0)||(board.getCardAt(1,i).getSigil()=="Waterborne")||(board.getCardAt(0,i).getSigil()=="Airborne")){
                //Attacking the opponent directly
                if (board.getCardAt(0,i).getAttack()>0){
                    cout << board.getCardAt(0,i).getName() << " deals " << board.getCardAt(0,i).getAttack() << " damage to you." << endl;
                }
            
                board.takeDamage(board.getCardAt(0,i).getAttack());
            } else {
                if (board.getCardAt(0,i).getSigil()=="Touch of Death"){
                    //cout << "Touch of death creature detected" << endl;
                    //board.getCardAt(0,i).setHealth(0);
                    //cout << endl << "HEALTH OF ELK IS " << board.getCardAt(0,i).getHealth() << endl << endl;
                    board.cardTakesDamage(1,i,999);
                    //cout << endl << "HEALTH OF ELK IS " << board.getCardAt(0,i).getHealth() << endl << endl;
                } else {
                    //cout << "Normal creature attacking other creature" << endl;
                    if (board.getCardAt(1,i).getHealth()>board.getCardAt(0,i).getAttack()){
                        //board.getCardAt(0,i).takeDmg(board.getCardAt(1,i).getAttack());
                        //int difference = (board.getCardAt(1,i).getAttack()-board.getCardAt(0,i).getHealth());
                        board.cardTakesDamage(1,i,board.getCardAt(0,i).getAttack());
                    } else {
                        board.cardTakesDamage(1,i,999);
                    }
                }
            } 
        }
        
    }
    for (int i=0; i<4; i++){
        Card blank;
        //cout << "Health of " << board.getCardAt(1,i).getName() << " is " << board.getCardAt(1,i).getHealth() << endl;
        if (board.getCardAt(1,i).getHealth()<=0){
            
            //cout << "Set health of creature at index " << i << " to 0." << endl;
            board.setCardAt(1,i,blank);
        }
        
    }
}

void Combat::addEnemyCards(int difficulty){
    board.addEnemyCards(difficulty);
}

void Combat::startEnemyCards(int difficulty){
    board.startEnemyCards(difficulty);
}

void Combat::setCardAt(int row, int col, Card givenCard){
    board.setCardAt(row,col,givenCard);
}