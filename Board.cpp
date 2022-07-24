//Board.cpp

// CSCI 1300 Spring 2022
// Author: Matthew Cerza
// Recitation: 202 – Alex Ray
// Project 3

#include <iostream>
#include "Board.h"
using namespace std;

//Creates a new board object and sets all slots to be empty.
Board::Board(){
    scale = 0;
    for (int i=0; i<2; i++){
        for (int j=0; j<4; j++){
            Card blank;
            board[i][j] = blank;
        }
    }
}
//Recursive Print Board function.
//Prints out the board for the current combat scenario. A board is defined as a 2x4 area of spaces, each of which can either be empty or contain a card
//The top row contain's the computer's creatures, and the bottom the player's.
//A "scale" containing the current score of the combat scenario is also printed on the left. 
//The combat scenario ends when the score reaches 5 (player wins) or -5 (player loses)
int Board::printBoard(int recur){
    if (recur==0){
        cout << "                         Inscryption-CMD" << endl;
        return printBoard(1);
    } else if (recur==1){
        cout << "  Scale   ---------------------------------------------" << endl;
        return printBoard(2);
    } else if (recur==2){
        cout << "          | " << board[0][0].getAttack() << "      " << board[0][0].getHealth() << " | " << board[0][1].getAttack() << "      " << board[0][1].getHealth() << " | " << board[0][2].getAttack() << "      " << board[0][2].getHealth() << " | " << board[0][3].getAttack() << "      " << board[0][3].getHealth() << " | " << endl;
        return printBoard(3);
    } else if (recur==3){
        cout << "          ";
        for (int i=0; i<4; i++){
            string s = board[0][i].getSigil();
            string s2;
            if (s.length()>9){
                s2 = s.substr(0,9);
            } else {
                s2 = s;
            }
            if (s2.length() == 0){
                cout << "|          ";
            } else {
                cout << "|" << s2;
                for (int j=s2.length(); j<10; j++){
                    cout << " ";
                }
            }
            
        }
        cout << "|" << endl;
        return printBoard(4);
    } else if (recur==4){
        cout << "          ";
        for (int i=0; i<4; i++){
            string s = board[0][i].getName();
            string s2;
            if (s.length()>9){
                s2 = s.substr(0,9);
            } else {
                s2 = s;
            }
            if (s2.length() == 0){
                cout << "|          ";
            } else {
                cout << "|" << s2;
                for (int j=s2.length(); j<10; j++){
                    cout << " ";
                }
            }
            
        }
        cout << "|" << endl;
        return printBoard(5);
    } else if (recur==5){
        if(getScale()>=0){
            cout << "    +" << getScale() << "    ---------------------------------------------" << endl;
        } else {
            cout << "    " << getScale() << "    ---------------------------------------------" << endl;
        }
        return printBoard(6);
    } else if (recur==6){
        cout << "          | " << board[1][0].getAttack() << "      " << board[1][0].getHealth() << " | " << board[1][1].getAttack() << "      " << board[1][1].getHealth() << " | " << board[1][2].getAttack() << "      " << board[1][2].getHealth() << " | " << board[1][3].getAttack() << "      " << board[1][3].getHealth() << " | " << endl;
        return printBoard(7);
    } else if (recur==7){
        cout << "          ";
        for (int i=0; i<4; i++){
            string s = board[1][i].getSigil();
            string s2;
            if (s.length()>9){
                s2 = s.substr(0,9);
            } else {
                s2 = s;
            }
            if (s2.length() == 0){
                cout << "|          ";
            } else {
                cout << "|" << s2;
                for (int j=s2.length(); j<10; j++){
                    cout << " ";
                }
            }
            
        }
        cout << "|" << endl;
        return printBoard(8);
    } else if (recur==8){
        cout << "          ";
        for (int i=0; i<4; i++){
            string s = board[1][i].getName();
            string s2;
            if (s.length()>9){
                s2 = s.substr(0,9);
            } else {
                s2 = s;
            }
            if (s2.length() == 0){
                cout << "|          ";
            } else {
                cout << "|" << s2;
                for (int j=s2.length(); j<10; j++){
                    cout << " ";
                }
            }
            
        }
        cout << "|" << endl;
        return printBoard(9);
    } else if (recur==9){
        cout << "          ---------------------------------------------" << endl;
        return printBoard(10);

    } else if (recur==10){
        return 1;
    } else {
        //Something is very wrong if this gets triggered.
        return 0;
    }
    

}

//Adds a card in the given space to the current board
void Board::addCard(int row, int col, Card toAdd){
    board[row][col] = toAdd;
}
//Removes a card in the given space
void Board::removeCard(int row, int col){
    Card blank;
    board[row][col] = blank;
}
//Gets the "score" of the current board. 
int Board::getScale(){
    return scale;
}
//Gets the card at a given row and column
Card Board::getCardAt(int row, int col){
    return board[row][col];
}
//Give damage to the scale, increasing the player's current score.
int Board::giveDamage(int dmg){
    scale+=dmg;
    return scale;
}
//Take damage to the scale, decreasing the player's score
int Board::takeDamage(int dmg){
    scale-=dmg;
    return scale;
}

//Set the card at a given row and column
void Board::setCardAt(int row, int col, Card givenCard){
    board[row][col] = givenCard;
}

void Board::cardTakesDamage(int row, int col, int dmg){
    board[row][col].setHealth(board[row][col].getHealth() - dmg);

}

void Board::addEnemyCards(int difficulty){
    int cardsPlayed = 0;
    bool twoCardsPlayed = false;
    double random = rand();
    
    random = rand();
    random = random/RAND_MAX;
    if ((random>=0.97-(difficulty/10.0))&&board[0][0].getHealth()==0){
        Card grizzly("Grizzly", 6,4,"","The massive grizzly. It's mere presense makes other creatures shudder in fear.",3,false);
        board[0][0] = grizzly;
        cardsPlayed++;
        //Hardest
    } else if ((random>=0.85-(difficulty/10.0))&&board[0][0].getHealth()==0){
        Card Wolf("Wolf", 3,2,"","The tenacious wolf. It's presense inspires confidince on creatures near it.", 2, false);
        board[0][0] = Wolf;
        cardsPlayed++;
        //Hard
    } else if ((random>=0.6-(difficulty/10.0)&&board[0][0].getHealth()==0)){
        Card Mouse("Mouse",1,1,"","A tiny field mouse. While seemingly weak, it's agility makes it a possible threat.",1,false);
        board[0][0] = Mouse;
        cardsPlayed++;
        //Easy
    }
    
    double randomTwo = rand();
    randomTwo = rand();
    randomTwo = randomTwo/RAND_MAX;
    if ((randomTwo>=0.97-(difficulty/10.0))&&board[0][1].getHealth()==0){
        Card grizzly("Grizzly", 6,4,"","The massive grizzly. It's mere presense makes other creatures shudder in fear.",3,false);
        board[0][1] = grizzly;
        cardsPlayed++;

        //Hardest
    } else if ((randomTwo>=0.85-(difficulty/10.0)&&board[0][1].getHealth()==0)){
        Card Wolf("Wolf", 3,2,"","The tenacious wolf. It's presense inspires confidince on creatures near it.", 2, false);
        board[0][1] = Wolf;
        cardsPlayed++;
        //Hard
    } else if ((randomTwo >=0.6-(difficulty/10.0)&&board[0][1].getHealth()==0)){
        Card Mouse("Mouse",1,1,"","A tiny field mouse. While seemingly weak, it's agility makes it a possible threat.",1,false);
        board[0][1] = Mouse;
        cardsPlayed++;
        //Easy
    }
    double randomThree = rand();
    randomThree = rand();
    randomThree = randomThree/RAND_MAX;
    if (cardsPlayed<2){
        if ((randomThree>=0.97-(difficulty/10.0))&&board[0][2].getHealth()==0){
            //Hardest
            Card grizzly("Grizzly", 6,4,"","The massive grizzly. It's mere presense makes other creatures shudder in fear.",3,false);
            board[0][2] = grizzly;
            cardsPlayed++;
        } else if ((randomThree>=0.85-(difficulty/10.0)&&board[0][2].getHealth()==0)){
            Card Wolf("Wolf", 3,2,"","The tenacious wolf. It's presense inspires confidince on creatures near it.", 2, false);
            board[0][2] = Wolf;
            cardsPlayed++;
            //Hard
        } else if ((randomThree >=0.6-(difficulty/10.0)&&board[0][2].getHealth()==0)){
            Card Mouse("Mouse",1,1,"","A tiny field mouse. While seemingly weak, it's agility makes it a possible threat.",1,false);
            board[0][2] = Mouse;
            cardsPlayed++;
            //Easy
        }
    }
    double randomFour = rand();
    randomFour = rand();
    randomFour = randomFour/RAND_MAX;
    if (cardsPlayed<2){
        if ((randomFour>=0.97-(difficulty/10.0))&&board[0][3].getHealth()==0){
            //Hardest
            Card grizzly("Grizzly", 6,4,"","The massive grizzly. It's mere presense makes other creatures shudder in fear.",3,false);
            board[0][3] = grizzly;
            cardsPlayed++;
        } else if ((randomFour>=0.85-(difficulty/10.0)&&board[0][3].getHealth()==0)){
            Card Wolf("Wolf", 3,2,"","The tenacious wolf. It's presense inspires confidince on creatures near it.", 2, false);
            board[0][3] = Wolf;
            //Hard
            cardsPlayed++;
        } else if ((randomFour >=0.6-(difficulty/10.0)&&board[0][3].getHealth()==0)){
            Card Mouse("Mouse",1,1,"","A tiny field mouse. While seemingly weak, it's agility makes it a possible threat.",1,false);
            board[0][3] = Mouse;
            //Easy
            cardsPlayed++;
        }
    }
    
    cout << "Random: " << random << " Random2: " << randomTwo << " Random3: " << randomThree << " Random4: " << randomFour << endl;
    
}

void Board::startEnemyCards(int difficulty){
    int cardsPlayed = 0;
    double random = rand();
    
    random = rand();
    random = random/RAND_MAX;
    if ((random>=0.97-(difficulty/10.0))&&board[0][0].getHealth()==0){
        Card grizzly("Grizzly", 6,4,"","The massive grizzly. It's mere presense makes other creatures shudder in fear.",3,false);
        board[0][0] = grizzly;
        cardsPlayed++;
        //Hardest
    } else if ((random>=0.85-(difficulty/10.0))&&board[0][0].getHealth()==0){
        Card Wolf("Wolf", 3,2,"","The tenacious wolf. It's presense inspires confidince on creatures near it.", 2, false);
        board[0][0] = Wolf;
        cardsPlayed++;
        //Hard
    } else if ((random >=0.6-(difficulty/10.0))&&board[0][0].getHealth()==0){
        Card Mouse("Mouse",1,1,"","A tiny field mouse. While seemingly weak, it's agility makes it a possible threat.",1,false);
        board[0][0] = Mouse;
        cardsPlayed++;
        //Easy
    }
    
    double randomTwo = rand();
    randomTwo = rand();
    randomTwo = randomTwo/RAND_MAX;
    if ((randomTwo>=0.97-(difficulty/10.0))&&board[0][1].getHealth()==0){
        Card grizzly("Grizzly", 6,4,"","The massive grizzly. It's mere presense makes other creatures shudder in fear.",3,false);
        board[0][1] = grizzly;
        cardsPlayed++;

        //Hardest
    } else if ((randomTwo>=0.85-(difficulty/10.0)&&board[0][1].getHealth()==0)){
        Card Wolf("Wolf", 3,2,"","The tenacious wolf. It's presense inspires confidince on creatures near it.", 2, false);
        board[0][1] = Wolf;
        cardsPlayed++;
        //Hard
    } else if ((randomTwo >=0.6-(difficulty/10.0)&&board[0][1].getHealth()==0)){
        Card Elk("Elk",4,2,"Sprinter","The flightly Elk. It attempts to move to the right after it's turn",2,false);
        board[0][1] = Elk;
        cardsPlayed++;
        //Easy
    }
    double randomThree = rand();
    randomThree = rand();
    randomThree = randomThree/RAND_MAX;
    if (cardsPlayed<2){
        if ((randomThree>=0.97-(difficulty/10.0))&&board[0][2].getHealth()==0){
            //Hardest
            Card grizzly("Grizzly", 6,4,"","The massive grizzly. It's mere presense makes other creatures shudder in fear.",3,false);
            board[0][2] = grizzly;
            cardsPlayed++;
        } else if ((randomThree>=0.85-(difficulty/10.0)&&board[0][2].getHealth()==0)){
            Card Wolf("Wolf", 3,2,"","The tenacious wolf. It's presense inspires confidince on creatures near it.", 2, false);
            board[0][2] = Wolf;
            cardsPlayed++;
            //Hard
        } else if ((randomThree >=0.6-(difficulty/10.0)&&board[0][2].getHealth()==0)){
            Card Elk("Elk",4,2,"Sprinter","The flightly Elk. It attempts to move to the right after it's turn",2,false);
            board[0][2] = Elk;
            cardsPlayed++;
            //Easy
        }
    }
    double randomFour = rand();
    randomFour = rand();
    randomFour = randomFour/RAND_MAX;
    if (cardsPlayed<2){
        if ((randomFour>=0.97-(difficulty/10.0))&&board[0][3].getHealth()==0){
        //Hardest
            Card grizzly("Grizzly", 6,4,"","The massive grizzly. It's mere presense makes other creatures shudder in fear.",3,false);
            board[0][3] = grizzly;
            cardsPlayed++;
        } else if ((randomFour>=0.85-(difficulty/10.0)&&board[0][3].getHealth()==0)){
            Card Wolf("Wolf", 3,2,"","The tenacious wolf. It's presense inspires confidince on creatures near it.", 2, false);
            board[0][3] = Wolf;
            cardsPlayed++;
            //Hard
        } else if (randomFour>=(0.6-(difficulty/10.0))&&board[0][3].getHealth()==0){
            Card Elk("Elk",4,2,"Sprinter","The flightly Elk. It attempts to move to the right after it's turn",2,false);
            board[0][3] = Elk;
            cardsPlayed++;
            //Easy
        }
    }
    
    
    cout << "Random: " << random << " Random2: " << randomTwo << " Random3: " << randomThree << " Random4: " << randomFour << " CardsPlayed: " <<cardsPlayed << endl;
    
}