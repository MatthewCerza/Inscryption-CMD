//Map.cpp

// CSCI 1300 Spring 2022
// Author: Matthew Cerza
// Recitation: 202 – Alex Ray
// Project 3

#include <iostream>
#include <vector>
#include <fstream>
#include "Card.h"
#include "Map.h"
using namespace std;

//Split function: Takes in a string, array, seperator and information about them and splits the string into elements of the array based upon the location of the seperators
//Algorithm: Create an array of the indexes of the seperators, and count them. Loop through the string, creating substrings and storing them of the elements between the seperators
int split(string inputString, char separator, string arr[], int size){
    if (inputString.length() == 0){ //If the length of the string is zero, meaning no values, return 0
        return 0;
    }
    int indexes[inputString.length()]; //An array of the indexes of the seperators, length of inputString.length() because there will never be more seperators than string characters
    int indexesIndex=0; //An index of the indexes, keeps track of how many seperators have been found
    for (int i = 0; i<inputString.length(); i++){ //Loop through the length of the string checking for seperators
        if (inputString[i] == separator){
            indexes[indexesIndex] = i; //If a seperator is found, add it's location to the indexes array
            indexesIndex++; //Increase number of seperators found by one
        }
    }
    indexesIndex++; //Increase indexesIndex by one after the loop completes, as the variable is now used to represent the number of arrays being output
    //cout << "indexesIndex evals to " << indexesIndex << endl;
    for (int i = 0; i<indexesIndex; i++){ //Loop through the number of output arrays (number of seperators + 1)
        if (i==0){ //Special case if it's the first string in the array as there will only be a seperator on one side of the string
            if (indexesIndex == 1){ //Even more special case: if there is only one array, it can be set to the input string and returned immediatley
                arr[0] = inputString; //Set first element in array and return
                return 1;
            }
            arr[i] = inputString.substr(0,(indexes[i])); //If it's just the first (and not only) element, set the first element to the start of the array up to the first seperator

        } else if (i == indexesIndex-1){ //Special case for the last element in the array. The algorithm below will exceed the length of the array, so this is a special case to not cause that.
            arr[i] = inputString.substr(indexes[i-1]+1); //Set last string to the last comma without a specified length, meaning it will go to the end of the string
        
        } else { //If it's a string in the middle, not the first or last...
            
            /*Set the string in the array to the index of the previous seperator +1, so just to the right, then
            give it a length of the seperator after minus the seperator before, giving the length of the string, 
            and subtracting one because that accounts for both seperators.*/
            arr[i] = inputString.substr(indexes[i-1]+1,(indexes[i]-indexes[i-1]-1));
        }
        
    }
    if (indexesIndex-1>size){ //Finally, there is a special case where there was not enough room for all the strings, in which case this returns -1
        return -1;
    }
    return indexesIndex; //If all of these trials have passed, return IndexesIndex, which is currently the number of arrays.
}



//A blank map
Map::Map(){
    vector<string> temp;
    map = temp;
}
//A map that is read in from the given file
Map::Map(string fileName){
    readMapFromFile(fileName);
    //cout << "completed reading" << endl;
}
//Returns the current map
vector<string> Map::getMap(){
    return map;
}
//Reads in the map from the given file. First line is the name, last line is the boss. All middle lines are the choices the player can make
int Map::readMapFromFile(string fileName){
    ifstream fin;
    fin.open(fileName);
    //cout << "opened filestream" << endl;
    if ((fin.fail())||(!fin.is_open())){
        return -1;
    }
    //cout << "passed input check" << endl;
    getline(fin, mapName);
    //cout << "Map name loaded as: " << mapName << endl;
    for (int i=0; !fin.eof(); i++){
        string temp;
        getline(fin, temp);
        //cout << "stored " << temp << " at index " << i << endl;
        map.push_back(temp);
    }
    fin.close();
    return 1;

}
//returns the name of the current map
string Map::getMapName(){
    return mapName;
}
//Get the first option on a given line of the map
string Map::getOption1(int mapIndex){
    int slashIndex = -1;
    for (int i=0; i<map[mapIndex].length(); i++){
        if (map[mapIndex][i]=='/'){
            slashIndex = i;
        }
    }
    if (slashIndex==-1){
        return map[mapIndex];
    } else {
        return (map[mapIndex].substr(0,slashIndex));
    }   
}
//Get the second option on a given line of the map
string Map::getOption2(int mapIndex){
    int slashIndex = -1;
    for (int i=0; i<map[mapIndex].length(); i++){
        if (map[mapIndex][i]=='/'){
            slashIndex = i;
        }
    }
    if (slashIndex==-1){
        return "";
    } else {
        return map[mapIndex].substr(slashIndex+1);
    }
    
}
//Erases the map, return 1 if successful.
int Map::clearMap(){
    vector<string> temp;
    map = temp;
    return 1;
}

int Map::getTotalCards(){
    return allCards.size();
}

Card Map::getCardAtIndex(int index){
    return allCards[index];
}

//Reads in cards from file.
//Card(string givenName, int givenHealth, int givenAttack, string givenSigil, string givenBio, int givenCost, bool givenSpecial);
int Map::readCardsFromFile(string fileName){
    ifstream fin;
    fin.open(fileName);
    //cout << "opened filestream" << endl;
    if ((fin.fail())||(!fin.is_open())){
        return -1;
    }
    //cout << "passed input check" << endl;
    string currentLine;
    for (int i=0; !fin.eof(); i++){
        
        Card temp;
        string arr[8];
        getline(fin, currentLine);
        if (currentLine.length()==0){
            continue;
        }
        int result = split(currentLine,',',arr,8);
        //cout << result << endl;
        temp.setName(arr[0]);
        //cout << "Current health is " << arr[1] << endl;
        temp.setHealth(stoi(arr[1]));
        //cout << "Current attack is " << arr[2] << endl;
        temp.setAttack(stoi(arr[2]));
        temp.setSigil(arr[3]);
        temp.setBio(arr[4]);
        //cout << "Current cost is " << arr[5] << endl;
        temp.setCost(stoi(arr[5]));
        if ((arr[0]=="Stoat")||(arr[0]=="Stinkbug")){
            temp.setSpecial(true);
        } else {
            temp.setSpecial(false);
        }
        allCards.push_back(temp);

    }
    fin.close();
    return 1;

}