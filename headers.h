#include <iostream>   //& Included for Cout - Cin
#include <string>     //& Allows me to use strings
#include <stdlib.h>   //& Needed for random integers, a few other things
#include <fstream>    //& Used for fileinput/output

#include "classes.h"  //& This defines all the classes used in this game

using namespace std;

//& Some global functions that are frequently used
void srand_(); // Tells the compiler about the function in hand which gets a time to convert to a random integer
void pressakey();
void line();  /// In dialouge.cpp
void p();
void c();
void candp();
void erase();

int number(player play, int lower_number_limit , int upper_number_limit); // This is in classes.cpp

void playersuits(string & westsuit, string & northsuit, string & eastsuit, player & west_player, player & north_player, player & east_player); //  This is in cards.cpp
