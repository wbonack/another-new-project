#include "headers.h"

void welcome()
{
	cout <<"Welcome to my Pinochle Game, I hope you enjoy it."<< endl << endl;
	cout << "In this console version of the game you will have " << endl;
	cout << "to press ENTER when prompted in certain places." << endl << endl;
}  // Called from Main


void pickname(string & name){
	cout << "What name do you want? " << endl;
	getline(cin, name);
	cout << endl << "Nice to meet you " << name << ", let's get started!" << endl; // Tells the player we are going to get started
} // Called from Main

void thanks_for_playing(){
	cout << "Thanks for playing! " << endl;
} // Called from Main

void line(){
	cout << endl << " ----------------------------------------------------------" << endl << endl;
}

void error()
{
	cout << "There was error()." << endl;
	cout << "The one in maindialouge.cpp" << endl;
	p();
}

void p(){ 
	} // Pause

void c()  {
		// system("cls");  Windows clear the command prompt
		system("clear"); // Linux Equivalent
	}

void candp()   {p(); c();}  // Calls pause and then clear

