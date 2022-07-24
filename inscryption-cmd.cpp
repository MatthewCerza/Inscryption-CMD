//inscryption-cmd.cpp

// CSCI 1300 Spring 2022
// Author: Matthew Cerza
// Recitation: 202 – Alex Ray
// Project 3

#include <iostream>
#include <vector>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "Card.h"
#include "Board.h"
#include "Combat.h"
#include "Map.h"
#include "Player.h"
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

void endOfGame(bool won){
    if (won){
        string wonTemp;
        cout << "As you approached the steps of the cabin, it's inhabitants turned towards you." << endl;
        getline(cin, wonTemp);
        cout << "With care in their eyes, they sought to feed and give medical aid to you and your managerie." << endl;
        getline(cin, wonTemp);
        cout << "Little did you know... This was just the beginning, challenger." << endl;
        getline(cin, wonTemp);
        cout << "Thank you for playing Inscryption-CMD!" << endl;
        cout << "Congratulations!" << endl;
        cout << "Press return to quit." << endl;
        getline(cin, wonTemp);
        exit(1);
    } else {
        string lostTemp;
        cout << "As the creatures of your pack fell and perished around you, the creatures of the forest grew unsatisfied." << endl;
        getline(cin, lostTemp);
        cout << "'Failure, challenger...' a whispering voice echoed." << endl;
        getline(cin, lostTemp);
        cout << "Thank you for playing Inscryption-CMD!" << endl;
        cout << "Better luck next time." << endl;
        cout << "Press return to quit." << endl;
        getline(cin, lostTemp);
        exit(1);
    }
}

void runTutorial(){
    string tutorialInput;
    cout << endl << "Navigation of menus:" << endl << "When a dialogue piece is displayed, but no obvious question is asked, press return (enter) to continue." << endl;
    cout << "This is one such scenario. No question is asked, so press enter to continue." << endl;
    getline(cin, tutorialInput);
    cout << "Some questions may ask you to make a choice. For example, please choose between a squirrel and a cat." << endl;
    bool tutorialLoop = true;
    while (tutorialLoop){
        cout << "Type either 'squirrel' or 'cat' below and press enter. Capitalization does not matter." << endl;
        getline(cin, tutorialInput);
        if ((toLowercase(tutorialInput)=="squirrel")||(toLowercase(tutorialInput)=="cat")){
            tutorialLoop = false;
        } else {
            cout << "Invalid input." << endl;
        }
    }
    cout << endl << "The last type of prompt is one that asks for numerical input." << endl;
    cout << "These will be denoted by a list, like this..." << endl;
    cout << "1. Option 1" << endl << "2. Option 2" << endl << "etc..." << endl;
    getline(cin, tutorialInput);
    cout << "Or the question will ask you for a number within a range." << endl;
    cout << "IT IS CRUCIAL that you enter a number, otherwise the program may crash." << endl;
    tutorialLoop = true;
    while (tutorialLoop){
        cout << "Enter a number between 1 and 5..." << endl;
        getline(cin, tutorialInput);
        if ((stoi(tutorialInput)>=1)&&(stoi(tutorialInput)<=5)){
            tutorialLoop = false;
        } else {
            cout << "Invalid input." << endl;
        }
    }
    cout << "Well done, challenger. Now onto the tutorial for game mechanics" << endl;
    getline(cin, tutorialInput);
    cout << "You are a starving survivor making your way through a forsest on the edge of winter." << endl;
    getline(cin, tutorialInput);
    cout << "Some creatures in the forsest seemed willing to help. Creatures are also known as CARDS." << endl;
    getline(cin, tutorialInput);
    cout << "Creatures that are currently following you reside in your DECK. You may get the opportunity to add CARDS to your DECK, or you may lose them." << endl;
    getline(cin, tutorialInput);
    cout << "Some creatures you encounter along the way may not be so friendly. You need to be prepared to battle." << endl;
    getline(cin, tutorialInput);
    Board demoBoard;
    Combat demoCombat(demoBoard);
    Player demoPlayer;
    demoCombat.returnBoard().printBoard(0);
    cout << endl << "This is the BOARD. This is where you can play CARDS (creatures) to defend yourself." << endl;
    getline(cin, tutorialInput);
    cout << "The top row shows creatures that are opposing you. The bottom row shows friendly creatures fighting for you. They are both empty for now." << endl;
    getline(cin, tutorialInput);
    cout << "The scale on the left denotes who is currently winning. YOU win if the scale gets to +5 points." << endl;
    getline(cin, tutorialInput);
    cout << "You LOSE if the scale gets to -5 points" << endl;
    getline(cin, tutorialInput);
    cout << "When you enter a battle, you draw CARDS into your HAND from your DECK" << endl;
    getline(cin, tutorialInput);
    cout << "Before you can play CARDS, however, you must appease the creature you are defending yourself with." << endl;
    cout << "Sacrafices Must Be Made. Each creature has a COST. That is, the Number of sacrafices a given creature demands." << endl;
    getline(cin, tutorialInput);
    cout << endl << "This is your current hand. You have a Squirrel, and a Stoat." << endl;
    Card Mouse("Mouse",1,1,"","A tiny field mouse. While seemingly weak, it's agility makes it a possible threat.",1,false);
    Card Stoat("Stoat",3,1,"","The swift stoat. A feeble yet resilient forest-going creature.",1,true);
    Card Squirrel("Squirrel",1,0,"","The feeble squirrel. Good free fodder for larger creatures.",0,false);
    demoPlayer.addCardHand(Stoat);
    demoPlayer.addCardHand(Squirrel);
    demoPlayer.printHand();
    getline(cin, tutorialInput);
    cout << "The squirrel is free to play, and has a cost of zero. The Stoat, however, demands a sacrafice before coming to your aid." << endl;
    getline(cin, tutorialInput);
    demoCombat.setCardAt(0,2,Mouse);
    demoCombat.returnBoard().printBoard(0);
    cout << "A Mouse opposes you. The number in the top left is it's attack, and the number in the top right it's health." << endl;
    getline(cin, tutorialInput);
    cout << "In this scenario, one would play their Squirrel, and then sacrafice it in order to play the Stoat." << endl;
    getline(cin, tutorialInput);
    cout << "Creatures in the same column will attack each other at the end of the turn. Your creatures attack first." << endl;
    getline(cin, tutorialInput);
    cout << "When a creature's health reaches zero, it dies." << endl;
    getline(cin, tutorialInput);
    cout << "Do not fret- even when a creature dies on the board, it remains in your DECK, living to see another day." << endl;
    getline(cin, tutorialInput);
    cout << "During each turn, you have the opportunity to draw another card into your HAND from your DECK. Alternativley, you may draw a Squirrel to use as fodder." << endl;
    getline(cin, tutorialInput);
    cout << "When a creature stands unopposed, it will deal damage directly to the opponent, adding points to the scale." << endl;
    cout << "As mentioned before, the battle is won when the scale gets at least +5 points, and is lost at -5." << endl;
    getline(cin, tutorialInput);
    cout << "One last thing, challenger." << endl;
    cout << "Some creatures may have special SIGILS on them that have the chance to turn the tide of the battle." << endl;
    getline(cin, tutorialInput);
    cout << "For example, the caustic Adder, a vicious snake, features the 'Touch of Death' SIGIL." << endl << "This means that when it attacks a creature, that creature perishes, regardless of health." << endl;
    cout << "You can get more information on various creatures during battle by choosing 'Get information'" << endl;
    getline(cin, tutorialInput);
    cout << "Good luck, challenger. Tread carefully, and trust your animal companions. This will not be easy." << endl;
    getline(cin, tutorialInput);
    cout << endl;
}

//This is the main method containing the menu system and story
int main(){
    srand(time(NULL));
    bool menuRunning = true;
    bool gameRunning = false;
    bool lostOnce = false;
    int difficulty = 0;
    string userInput;
    Card squirrel("Squirrel",1,0,"","The feeble squirrel. Useful fodder to get other creatures to follow you.",0,false);
    //squirrel.setCost(0);
    //cout << "SQCOST: " << squirrel.getCost() << endl;
    while (menuRunning){
        cout << endl << "Welcome to Inscryption-CMD" << endl;
        cout << "Please choose an option below." << endl;
        cout << "1. Play The Tutorial" << endl;
        cout << "2. Start A New Game" << endl;
        cout << "3. Options" << endl;
        cout << "4. Quit" << endl;
        cout << "Enter a number: ";
        getline(cin,userInput);
        if ((userInput=="1")||(toLowercase(userInput)=="one")){
            runTutorial();
        } else if ((userInput=="2")||(toLowercase(userInput)=="two")){
            //hell of some code here
            
            Player player;
            Map map;
            int mapIndex = 0;
            string fileName;
            string temp;

            bool invalidLoop = true;
            cout << "Please enter a file to load the Map from. (Default: map.txt)" << endl << "Filename: ";
            while (invalidLoop){
                getline(cin, fileName);
                int result = map.readMapFromFile(fileName);
                if (result==-1){
                    cout << endl << "Please enter a valid file name" << endl << "Filename: ";
                } else {
                    invalidLoop = false;
                }
            }
            cout << "Please enter a file to load the Cards (creatures) from. (Default: cards.txt)" << endl << "Filename: ";
            invalidLoop = true;
            while (invalidLoop){
                getline(cin, fileName);
                int result = map.readCardsFromFile(fileName);
                if (result==-1){
                    cout << endl << "Please enter a valid file name" << endl << "Filename: ";
                } else {
                    invalidLoop = false;
                }
            }
            player.addCardDeck(map.getCardAtIndex(0));
            player.addCardDeck(map.getCardAtIndex(1));
            player.addCardDeck(map.getCardAtIndex(2));
            player.addCardDeck(map.getCardAtIndex(3));
            cout << endl << "Your starting deck..." << endl;
            player.printDeck();
            getline(cin, temp);
            
            cout << "--" << map.getMapName() << "--" << endl;
            getline(cin,temp);

            cout << "You approached an opening in the woods, and faintly saw two paths in front of you. " << endl;
            getline(cin,temp);

            cout << "The flock of animals following you encouraged you forward. You were out of food and needed to make progress." << endl;
            getline(cin,temp);

            bool mapLoop = true;
            while (mapLoop){
                cout << endl;
                if (map.getOption2(mapIndex)==""){
                    cout << "One path stood in front of you. A " << map.getOption1(mapIndex) << ". Where will you go?" << endl;
                } else {
                    cout << "Two paths stood in front of you. A " << map.getOption1(mapIndex) << " and a " << map.getOption2(mapIndex) << ". Which will you choose?" << endl;
                }
                cout << "Choice: ";
                invalidLoop = true;
                while (invalidLoop){
                    getline(cin, userInput);
                    if ((toLowercase(userInput)=="battle")&&((map.getOption1(mapIndex)=="battle")||(map.getOption2(mapIndex)=="battle"))){
                        invalidLoop = false;
                        Board board;
                        Combat combat(board);
                        bool combatLoop = true;
                        combat.addEnemyCards(difficulty);
                        cout << "Some unfriendly creatures stood in your way." << endl;
                        player.addCardHand(player.getDeck()[0]);
                        player.addCardHand(player.getDeck()[1]);
                        player.addCardHand(player.getDeck()[2]);
                        bool battleWon = false;
                        int deckIndex = 0;
                        while (combatLoop){
                            bool cardDrawn = false;
                            
                            bool invalidLoopPlayersTurn = true;
                            while (invalidLoopPlayersTurn){
                                combat.returnBoard().printBoard(0);
                                cout << "Your Hand:" << endl;
                                player.printHand();
                                getline(cin,temp);
                                cout << "What will you do?" << endl;
                                cout << "1. Draw A Card" << endl << "2. Play a Card" << endl << "3. Get Info on a Card on the Board" << endl << "4. Commence Combat" << endl;
                                getline (cin, userInput);
                                if (((toLowercase(userInput)=="draw")||(toLowercase(userInput)=="1")||(toLowercase(userInput)=="one"))&&(!cardDrawn)){
                                    
                                    cout << "Draw a card from your deck or a squirrel?" << endl << "Choice: ";
                                    
                                    bool invalidLoopDraw = true;
                                    while (invalidLoopDraw){
                                        getline(cin, userInput);
                                        if ((toLowercase(userInput)=="squirrel")||(toLowercase(userInput)=="1")||(toLowercase(userInput)=="one")){
                                            player.addCardHand(squirrel);
                                            cardDrawn = true;
                                            invalidLoopDraw = false;
                                            
                                        } else if ((toLowercase(userInput)=="card")||(toLowercase(userInput)=="2")||(toLowercase(userInput)=="two")||(toLowercase(userInput)=="deck")){
                                            player.addCardHand(player.getDeck()[deckIndex]);
                                            deckIndex++;
                                            cardDrawn = true;
                                            invalidLoopDraw = false;

                                        } else {
                                            cout << "Invalid input." << endl;
                                        }
                                    }
                                    
                                } else if (((toLowercase(userInput)=="draw")||(toLowercase(userInput)=="1")||(toLowercase(userInput)=="one"))&&(cardDrawn)){
                                    cout << "You have already drawn a card this turn." << endl;
                                    getline(cin, temp);
                                } else if ((toLowercase(userInput)=="play")||(toLowercase(userInput)=="2")||(toLowercase(userInput)=="two")){
                                    
                                    cout << "Choose a card from your hand to play" << endl;
                                    player.printHand();
                                    int cardIndex = -1;
                                    bool invalidLoop2 = true;
                                    while (invalidLoop2){
                                        getline(cin, userInput);
                                        for (int i=0; i<player.getHand().size(); i++){
                                            string currentName = player.getHand()[i].getName();
                                            if (toLowercase(currentName)==toLowercase(userInput)){
                                                invalidLoop2 = false;
                                                cardIndex = i;
                                                break;
                                            }
                                        }
                                        if (cardIndex == -1){
                                            cout << "Card not found. Enter a valid card name." << endl;
                                        }

                                    }
                                    if (player.getHand()[cardIndex].getCost()==0){
                                        cout << "Where would you like to place the card? (Columns 1 through 4)" << endl;
                                        getline(cin, userInput); //CHANGE USER INPUT VARIABLES??
                                        invalidLoop2 = true;
                                        while(invalidLoop2){
                                            if ((stoi(userInput)>=1)&&(stoi(userInput)<=4)){
                                                int position = stoi(userInput)-1;
                                                combat.setCardAt(1,(position),player.getHand()[cardIndex]);
                                                invalidLoop2 = false;
                                                cout << "played card on board and ended loop" << endl;
                                                cout << "Preparing to remove card at index " << cardIndex << endl;
                                                player.removeCardHand(cardIndex);
                                                cout << "removed card from hand sucessfully" << endl;

                                            } else {
                                                cout << "Choose a valid spot." << endl;
                                            }
                                        }

                                    } else {
                                        int sacraficesNeeded = player.getHand()[cardIndex].getCost();
                                        int creaturesSacraficed = 0;
                                        int possibleSacrafices = 0;
                                        for (int c=0; c<4; c++){
                                            if (combat.returnBoard().getCardAt(1,c).getHealth()>0){
                                                possibleSacrafices++;

                                            }
                                        }
                                        if (possibleSacrafices<sacraficesNeeded){
                                            cout << "Not enough creatures on your side of the board to sacrafice" << endl;
                                            getline(cin, temp);
                                        } else {
                                            while (sacraficesNeeded>creaturesSacraficed){
                                                cout << "Choose a creature to sacrafice. (Enter a column)" << endl;
                                                getline(cin,userInput);
                                                
                                                
                                                if ((stoi(userInput)>=1)&&(stoi(userInput)<=4)){
                                                    if (combat.returnBoard().getCardAt(1,stoi(userInput)-1).getHealth()>0){
                                                        cout << "The " << combat.returnBoard().getCardAt(1,stoi(userInput)-1).getName() << " has been sacraficed." << endl;
                                                        Card blank;
                                                        combat.setCardAt(1,stoi(userInput)-1,blank);
                                                        creaturesSacraficed++;

                                                    } else {
                                                        cout << "Pick a valid creature" << endl;
                                                    }
                                                } else {
                                                    cout << "Pick a valid column. (1 through 4)" << endl;
                                                }
                                            }
                                            cout << "Where would you like to place your " << player.getHand()[cardIndex].getName() << "?" << endl;
                                            invalidLoop2 = true;
                                            while (invalidLoop2){
                                                getline(cin, userInput);
                                                int position = stoi(userInput)-1;
                                                if ((position>=0)&&(position<=4)){
                                                    combat.setCardAt(1,position,player.getHand()[cardIndex]);
                                                    invalidLoop2 = false;
                                                    player.removeCardHand(cardIndex);
                                                } else {
                                                    cout << "Choose a valid column. (1-4)" << endl;
                                                }
                                                
                                            }

                                        }
                                    

                                    }
                                } else if ((toLowercase(userInput)=="info")||(toLowercase(userInput)=="3")||(toLowercase(userInput)=="three")){
                                    bool invalidInfoLoop = true;
                                    string infoRow;
                                    string infoCol;
                                    while (invalidInfoLoop){
                                        cout << "Select a row: (Row 1 for enemy creatures, Row 2 for your creatures)" << endl;
                                        getline(cin,infoRow);
                                        cout << "Select a column: (1 through 4)" << endl;
                                        getline(cin,infoCol);
                                        //cout << "InfoRow: " << infoRow << " InfoCol: " << infoCol << endl;
                                        int adjustedRow = stoi(infoRow)-1;
                                        int adjustedCol = stoi(infoCol)-1;
                                        if ((adjustedRow>=0)&&(adjustedRow<=1)&&(adjustedCol>=0)&&(adjustedCol<=3)){
                                            invalidInfoLoop = false;
                                            cout << endl;
                                            combat.returnBoard().getCardAt(adjustedRow,adjustedCol).printInfo();
                                            getline(cin, temp);
                                        } else {
                                            cout << "Please enter a valid row and column" << endl;

                                        }
                                        
                                    }


                                } else if ((toLowercase(userInput)=="combat")||(toLowercase(userInput)=="4")||(toLowercase(userInput)=="four")) {
                                    //Commence combat
                                    invalidLoopPlayersTurn = false;
                                    cardDrawn = false;
                                    cout << "Commencing combat..." << endl;
                                    combat.playersTurn();
                                    if ((combat.returnBoard().getScale()>=5)||(combat.returnBoard().getScale()<=(-5))){
                                        combatLoop = false;
                                        if ((combat.returnBoard().getScale()>=5)){
                                            battleWon = true;
                                            cout << endl << "You won the battle!" << endl;
                                            getline(cin, temp);
                                        } else {
                                            cout << endl << "You lost the battle..." << endl;
                                            getline(cin, temp);
                                            if (lostOnce == false){
                                                cout << endl << "Dissapointing, challenger." << endl;
                                                getline(cin, temp);
                                                cout << "That was one of two mistakes you can make here. If you make another, YOU will be sacraficed." << endl;
                                                getline(cin, temp);
                                                cout << "Do not dissapoint." << endl;
                                                getline(cin, temp);
                                                lostOnce = true;
                                            } else {
                                                endOfGame(false);
                                            }
                                        }
                                        
                                        player.clearHand();
                                        break;

                                    }
                                    cout << endl << "Enemy's turn: " << endl;
                                    combat.enemysTurn();
                                    combat.returnBoard().printBoard(0);
                                    if ((combat.returnBoard().getScale()>=5)||(combat.returnBoard().getScale()<=(-5))){
                                        combatLoop = false;
                                        if ((combat.returnBoard().getScale()>=5)){
                                            battleWon = true;
                                            cout << endl << "You won the battle!" << endl;
                                            getline(cin, temp);
                                        } else {
                                            cout << endl << "You lost the battle..." << endl;
                                            getline(cin, temp);
                                            if (lostOnce == false){
                                                cout << endl << "Dissapointing, challenger." << endl;
                                                getline(cin, temp);
                                                cout << "That was one of two mistakes you can make here. If you make another, YOU will be sacraficed." << endl;
                                                getline(cin, temp);
                                                cout << "Do not dissapoint." << endl;
                                                getline(cin, temp);
                                                lostOnce = true;
                                            } else {
                                                endOfGame(false);
                                            }
                                        }
                                        if (lostOnce == false){
                                            cout << endl << "Dissapointing, challenger." << endl;
                                            getline(cin, temp);
                                            cout << "That was one of two mistakes you can make here. If you make another, YOU will be sacraficed." << endl;
                                            getline(cin, temp);
                                            cout << "Do not dissapoint." << endl;
                                            getline(cin, temp);
                                            lostOnce = true;
                                        } else {
                                            endOfGame(false);
                                        }
                                        player.clearHand();
                                        break;

                                    }
                                    getline(cin, temp);
                                    cout << "The enemy played new cards:" << endl;
                                    combat.addEnemyCards(difficulty);



                                } else {
                                    cout << "Invalid input." << endl;
                                }

                                


                            }


                            

                        }
                        
                    } else if ((toLowercase(userInput)=="card")&&((map.getOption1(mapIndex)=="card")||(map.getOption2(mapIndex)=="card"))){
                        invalidLoop = false;
                        cout << "Some creatures of the forsest seemed instested in following you. Only one may grace your paltry deck." << endl;
                        double random = rand();
                        random = rand();
                        random = ((int)random)%(map.getTotalCards());
                        double random2 = rand();
                        random2 = rand();
                        random2 = ((int)random2)%(map.getTotalCards());
                        double random3 = rand();
                        random3 = rand();
                        random3 = ((int)random3)%(map.getTotalCards());
                        cout << "Total cards in allCards: " << map.getTotalCards() << endl;
                        cout << "Generated random numbers rand1: " << (int)random << " rand2: " << (int)random2 << " rand3: " << (int)random3  << endl;
                        Card option1 = map.getCardAtIndex((int)random);
                        Card option2 = map.getCardAtIndex((int)random2);
                        Card option3 = map.getCardAtIndex((int)random3);
                        cout << "Which card would you like to add to your deck?" << endl;
                        cout << endl;
                        option1.printInfo();
                        cout << endl;
                        option2.printInfo();
                        cout << endl;
                        option3.printInfo();
                        cout << "Choice: ";

                        bool cardChooseLoop = true;
                        while (cardChooseLoop){
                            getline(cin,userInput);
                            if ((toLowercase(userInput)==toLowercase(option1.getName()))||(toLowercase(userInput)=="1")||(toLowercase(userInput)=="one")){
                                player.addCardDeck(option1);
                                cardChooseLoop = false;
                                cout << "The " << option1.getName() << " joined your managerie." << endl;
                            } else if ((toLowercase(userInput)==toLowercase(option2.getName()))||(toLowercase(userInput)=="2")||(toLowercase(userInput)=="two")){
                                player.addCardDeck(option2);
                                cardChooseLoop = false;
                                cout << "The " << option2.getName() << " joined your managerie." << endl;
                            } else if ((toLowercase(userInput)==toLowercase(option3.getName()))||(toLowercase(userInput)=="3")||(toLowercase(userInput)=="three")){
                                player.addCardDeck(option3);
                                cardChooseLoop = false;
                                cout << "The " << option3.getName() << " joined your managerie." << endl;
                            } else {
                                cout << "Please choose a card. (Enter name of creature or 1 through 3)" << endl;
                                
                            }
                        }

                    } else if ((toLowercase(userInput)=="campfire")&&((map.getOption1(mapIndex)=="campfire")||(map.getOption2(mapIndex)=="campfire"))){
                        invalidLoop = false;
                        Campfire test1;
                        cout << "You stumbled across some survivors, huddled close around a campfire." << endl;
                        getline(cin,temp);
                        cout << "'We have not food' one said. 'Warm one of your creatures by the fire? Enhance it's power?' said another." << endl;
                        getline(cin,temp);
                        if (toLowercase(temp)!="no"){
                            bool creatureChoiceLoop = true;
                            int creatureIndex = -1;
                            while (creatureChoiceLoop){
                                player.printDeck();
                                cout << "Which creature shall you put forward?" << endl;
                                
                                getline(cin, userInput);
                                for (int p=0; p<player.getDeck().size(); p++){
                                    if ((toLowercase(userInput)==(toLowercase(player.getDeck()[p].getName())))){
                                        creatureIndex = p;
                                    }
                                }
                                if (creatureIndex!=(-1)){
                                    creatureChoiceLoop = false;
                                }
                            }
                            
                            if (test1.getType()=="Attack"){
                                test1.chanceAttkUpgrade(player.getDeck()[creatureIndex]);
                                player.campAttackBuff(creatureIndex);
                            } else {
                                test1.chanceHealthUpgrade(player.getDeck()[creatureIndex]);
                                player.campHealthBuff(creatureIndex);

                            }
                            cout << "'Keep it right there...' said one survivor. One licked their lips, another gnashed their teeth." << endl;
                            getline(cin, temp);
                            cout << "You sensed the risk was even greater now. Push your luck, or pull away?" << endl;
                            getline(cin, temp);
                            if ((toLowercase(temp)!="no")&&(toLowercase(temp)!="pull away")){
                                if (test1.getType()=="Attack"){
                                    if (test1.chanceAttkUpgrade2(player.getDeck()[creatureIndex])==1){
                                        cout << "As the survivors began approaching your " << player.getDeck()[creatureIndex].getName() << ", you pulled back." << endl;
                                        player.campAttackBuff(creatureIndex);
                                    } else {
                                        cout << "The survivors lunged at your creature, devouring it before you could even step in. With the rest of your pack in towe, you made a hasty retreat." << endl;
                                        player.removeCardDeck(creatureIndex);
                                        getline(cin, temp);
                                    }
                                    
                                } else {
                                    if (test1.chanceHealthUpgrade2(player.getDeck()[creatureIndex])==2){
                                        cout << "As the survivors began approaching your " << player.getDeck()[creatureIndex].getName() << ", you pulled back." << endl;
                                        player.campHealthBuff(creatureIndex);
                                    } else {
                                        cout << "The survivors lunged at your creature, devouring it before you could even step in. With the rest of your pack in towe, you made a hasty retreat." << endl;
                                        player.removeCardDeck(creatureIndex);
                                        getline(cin, temp);
                                    }

                                }
                            }
                        } else {
                            cout << "You decided that further interacting with the survivors was not worth the risk." << endl;
                            getline(cin, temp);
                        }


                    } else if ((toLowercase(userInput)=="sacrafice")&&((map.getOption1(mapIndex)=="sacrafice")||(map.getOption2(mapIndex)=="sacrafice"))){
                        invalidLoop = false;
                        //CUT FEATURE
                        //I did not have time to write this. 
                    } else if ((toLowercase(userInput)=="boss")&&((map.getOption1(mapIndex)=="boss")||(map.getOption2(mapIndex)=="boss"))){
                        invalidLoop = false;
                        system ("CLS");
                        cout<< "In the distance you could see fair shimmers and shadows of light."<<flush; //flush forces the printing to the screen before it clears
                        getline(cin, temp);
                        //system ("CLS");
                        cout<< "A cabin, lively and bountiful. It was only a couple hundred feet away."<<endl;
                        getline(cin, temp);
                        cout << "However, between you and it stood one final test." << endl;
                        getline(cin, temp);
                    } else {
                        cout << "Please enter a valid input." << endl;
                        cout << "Choice: ";
                    }
                }





                mapIndex++;
                //IF NEXT IS BOSS, BREAK FROM THE LOOP??
            }


        } else if ((userInput=="3")||(toLowercase(userInput)=="three")){
            bool optionsRunning = true;
            while (optionsRunning){
                
                cout << endl << "Options" << endl;
                cout << "1. Change Difficulty" << endl;
                cout << "2. Change Audio Engine (EXPERIMENTAL, this probably does nothing)" << endl;
                cout << "3. Back to Main Menu" << endl;
                cout << "Enter a number: ";
                getline(cin,userInput);
                if ((userInput=="1")||(toLowercase(userInput)=="one")){
                    bool invalidDiff = true;
                    cout << endl << "What would you like to set the difficulty to?" << endl << "(-1: Very Easy, 0: Easy (Default), 1: Normal, 2: Hard, 3: Very Hard, 4: Impossible)" << endl;
                    while (invalidDiff){
                        getline(cin, userInput);
                        if ((stoi(userInput)>=(-1))&&(stoi(userInput)<=4)){
                            invalidDiff = false;
                            difficulty = stoi(userInput);
                            if (stoi(userInput)==(-1)){
                                cout << "Difficulty set to 'Very Easy'" << endl;
                            } else if (stoi(userInput)==0){
                                cout << "Difficulty set to 'Easy'" << endl;
                            } else if (stoi(userInput)==1){
                                cout << "Difficulty set to 'Normal'" << endl;
                            } else if (stoi(userInput)==2){
                                cout << "Difficulty set to 'Hard'" << endl;
                            } else if (stoi(userInput)==3){
                                cout << "Difficulty set to 'Very Hard'" << endl;
                            } else if (stoi(userInput)==4){
                                cout << "Good Luck. You're going to need it." << endl;
                                string doomMode;
                                getline(cin,doomMode);
                            }
                        } else {
                            cout << "Please enter a valid numerical difficulty value." << endl;
                        }
                    }
                } else if ((userInput=="2")||(toLowercase(userInput)=="two")){
                    //CODE FOR SOLOUD OR MINIAUDIO HERE
                    //CUT Feature, out of time.
                } else if ((userInput=="3")||(toLowercase(userInput)=="three")){
                    optionsRunning = false;
                } else if ((userInput=="4")||(toLowercase(userInput)=="four")){
                    optionsRunning = false;
                } else {
                    cout << "Please enter a valid input." << endl;
                }
            }
        } else if ((userInput=="4")||(toLowercase(userInput)=="four")){
            menuRunning = false;
            return 0;
        } else {
            cout << "Please enter a valid input." << endl;
        }
    }
}