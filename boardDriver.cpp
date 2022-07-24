#include <iostream>
#include "Card.h"
#include "Board.h"
using namespace std;


/*Board
    Col:
Row:   0   1   2   3 
0    |   |   |   |   |
1    |   |   |   |   |
*/
int main(){
    Card Wolf("Wolf", 3,2,"Leader","The tenacious wolf", 2, false);
    Card Elk("Elk", 2,3,"Sprinter","The flightly elk", 2, false);
    Board test1;
    test1.addCard(0,2,Wolf);
    test1.addCard(1,1,Elk);
    cout << test1.getCardAt(0,2).getBio() << endl;
    cout << test1.getCardAt(0,0).getHealth() << endl;
    test1.printBoard(0);
    test1.giveDamage(3);
    test1.removeCard(0,2);
    test1.printBoard(0);

}