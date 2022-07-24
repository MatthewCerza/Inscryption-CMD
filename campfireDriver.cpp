#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Card.h"
#include "Campfire.h"
using namespace std;

//toLowercase function, takes in a string a returns the lowecase version
string toLowercase(string orig){
    string lower = orig;
    for (int i = 0; i<orig.length(); i++){ //loop through the string
        if ((orig[i]>=65)&&(orig[i]<=90)){ //if the selected character is uppercase
            lower[i]=orig[i]+32; //replace it with the lowercase version
        }
    }
    return lower; //return the new lowercase version
}

int main(){
    srand(time(NULL));
    Card Wolf("Wolf", 2,3,"Leader","The tenacious wolf", 2, false);
    Card Elk("Elk", 3,2,"Sprinter","The flightly elk", 2, false);
    Campfire test1;
    string temp;
    cout << test1.getType() << endl;
    cout << "You stumbled across some survivors, huddled close around a campfire." << endl;
    getline(cin,temp);
    cout << "'We have not food' one said. 'Warm one of your creatures by the fire? Enhance it's power?' said another." << endl;
    getline(cin,temp);
    if (toLowercase(temp)!="no"){
        if (test1.getType()=="Attack"){
            test1.chanceAttkUpgrade(Wolf);
            Wolf.changeAttack(1);
        } else {
            test1.chanceHealthUpgrade(Wolf);
            Wolf.setHealth(Wolf.getHealth()+2);

        }
        cout << "'Keep it right there...' said one survivor. One licked their lips, another gnashed their teeth." << endl;
        getline(cin, temp);
        cout << "You sensed the risk was even greater now. Push your luck, or pull away?" << endl;
        getline(cin, temp);
        if ((toLowercase(temp)!="no")&&(toLowercase(temp)!="pull away")){
            if (test1.getType()=="Attack"){
                if (test1.chanceAttkUpgrade2(Wolf)==1){
                    cout << "As the survivors began approaching your " << Wolf.getName() << ", you pulled back." << endl;
                     Wolf.changeAttack(1);
                } else {
                    cout << "The survivors lunged at your creature, devouring it before you could even step in. With the rest of your pack in towe, you made a hasty retreat." << endl;
                    //REMOVE CARD FROM DECK.
                }
                
            } else {
                if (test1.chanceHealthUpgrade2(Wolf)==2){
                    cout << "As the survivors began approaching your " << Wolf.getName() << ", you pulled back." << endl;
                    Wolf.setHealth(Wolf.getHealth()+2);
                } else {
                    cout << "The survivors lunged at your creature, devouring it before you could even step in. With the rest of your pack in towe, you made a hasty retreat." << endl;
                    //REMOVE CARD FROM DECK.
                }

            }
        }

    }

}