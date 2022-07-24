//Map.h

// CSCI 1300 Spring 2022
// Author: Matthew Cerza
// Recitation: 202 – Alex Ray
// Project 3

#ifndef MAP_H
#define MAP_H
#include <iostream>
#include <vector>
using namespace std;

//A Map that the player can traverse. The game is won by the player making it to the end.
//The map is stored as a vector of strings and is read in from a file.
//The slash in each element symbolizes the two choices the player has at any given intersection
class Map{
    private:
    vector<string> map;
    string mapName;
    vector<Card> allCards;


    public:
    vector<string> getMap();
    int readMapFromFile(string fileName);
    int clearMap();
    string getMapName();
    string getOption1(int mapIndex);
    string getOption2(int mapIndex);
    Map();
    Map(string fileName);
    int readCardsFromFile(string fileName);
    Card getCardAtIndex(int index);
    int getTotalCards();



};

#endif