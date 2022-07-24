#include <iostream>
#include "Card.h"
using namespace std;


int main(){
    //Expected output: "Wolf"
    //Creates new card object and prints out the name of it.
    Card Wolf("Wolf", 3,2,"","The tenacious wolf", 2, false);
    cout << Wolf.getName() << endl;
}