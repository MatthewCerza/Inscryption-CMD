# Inscryption-CMD
Inscryption-CMD is a miniaturized version of a game named "Inscryption". Inscryption-CMD features a player making their way through a forest in search of food and shelter. The only thing the player has to help them are their animal companions. During their treacherous journey, they will encounter obstacles and surprises, some good, and some deadly. Can you make it to the end... if there even is one? 

Created as a final project for CSCI 1300 at CU Boulder.

------------------------
FEATURES  
Inscryption-CMD has a modular map and cards. The included defaults are map.txt and cards.txt, which contain the stock map ("The Snow Line"), and thirteen cards can be loaded but can also be modified to include whatever path and cards you want.  
COMBAT ENGINE
The combat system inside the game acts just like the original Inscryption, but can be modified in combat.cpp to add new features such as sigils. Combat engages from left to right.

------------------------
HOW TO COMPILE AND RUN
------------------------
Compile: g++ -std=c++17 inscryption-cmd.cpp Card.cpp Board.cpp Combat.cpp Map.cpp Player.cpp Campfire.cpp -o proj3  
Run: ./proj3

------------------------
DEPENDENCIES
------------------------
Card.cpp, Board.cpp, Combat.cpp, Map.cpp, Player.cpp, and their corresponding .h files must be in the same directory as inscryption-cmd.cpp in order to compile.

------------------------
SUBMISSION INFORMATION
------------------------
CSCI1300 Spring 2022 Project 3  
Author: Matthew Cerza  
Recitation: 202 - Alex Ray  
Date: April 21, 2022  

------------------------

