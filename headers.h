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

int number(int, int, int, int,int,int,int,int,int,int,int,int, int , int); // This is in classes.cpp

void playersuits(string * westsuit, string * northsuit, string * eastsuit, int wh, int nh, int eh, int wd, int nd, int ed, 
				 int ws,int ns, int es, int wc,int nc, int ec); //  This is in cards.cpp
