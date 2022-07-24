#include <iostream>
#include "Card.h"
#include "Board.h"
#include "Combat.h"
#include <time.h>
using namespace std;

int main(){
    srand(time(NULL));
    int diff = 1;
    Card Wolf("Wolf", 2,3,"Leader","The tenacious wolf", 2, false);
    Card Elk("Elk", 3,2,"Sprinter","The flightly elk", 2, false);
    Card Adder("Adder",1,1,"Touch of Death","The caustic Adder",1,false);
    Card Stoat("Stoat",4,2,"","The lowly stoat",1,true);
    Card KingFisher("King Fisher",1,1,"Waterborne","Kingfisher bio idk",1,false);
    Board test;
    test.addCard(1,1,Wolf);
    test.addCard(1,2,Adder);
    //test.addCard(0,1,Stoat);
    //test.addCard(0,2,Elk);
    Combat scenario1(test);

    cout <<"Before Combat: " << endl;
    scenario1.returnBoard().printBoard(0);
    scenario1.startEnemyCards(diff);
    cout << "After Leshy Plays Initial Cards" << endl;
    scenario1.returnBoard().printBoard(0);
    scenario1.playersTurn();
    cout <<"After Player's Turn: " << endl;
    scenario1.returnBoard().printBoard(0);
    scenario1.enemysTurn();
    cout << "After Enemy's Turn:" << endl;
    scenario1.returnBoard().printBoard(0);
    scenario1.addEnemyCards(diff);
    cout << "Player's turn to play cards:" << endl;
    scenario1.returnBoard().printBoard(0);

    /*cout << endl << endl << "Scenario 2:" << endl << endl;
    Board test2;
    test2.addCard(0,1,KingFisher);
    test2.addCard(0,2,Adder);
    test2.addCard(1,1,Stoat);
    test2.addCard(1,2,Elk);
    Combat scenario2(test2);
    cout <<"Before Combat: " << endl;
    scenario2.returnBoard().printBoard(0);
    scenario2.playersTurn();
    cout <<"After Player's Turn: " << endl;
    scenario2.returnBoard().printBoard(0);
    scenario2.enemysTurn();
    cout << "After Enemy's Turn:" << endl;
    scenario2.returnBoard().printBoard(0);*/





}