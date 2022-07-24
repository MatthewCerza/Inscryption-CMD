#include <iostream>
#include "Card.h"
#include "Map.h"
using namespace std;


int main(){
    Map test1("map.txt");
    cout << test1.getMapName() << endl;
    int mapIndex = 0;
    cout << "Two paths stood in front of you. A " << test1.getOption1(0) << " and a " << test1.getOption2(0) << ". Which will you choose?" << endl;
    test1.readCardsFromFile("cards.txt");
    cout << test1.getCardAtIndex(0).getName() << endl;
    cout << test1.getCardAtIndex(0).getCost() << endl;
    
}