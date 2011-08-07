#include "headers.h"

////This function welcomes the player and asks his name
void welcome()
{
	cout <<"Welcome to my Pinochle Game, I hope you enjoy it."<< endl << endl;
	cout << "In this console version of the game you will have " << endl;
	cout << "to press ENTER when prompted in certain places." << endl << endl;
}  //Main

//The following comes from main and gives the player an option to have a two word name.
void namepicking(string & name){
	cout << "What name do you want? " << endl;
	getline(cin, name);
	cout << endl << "Nice to meet you " << name << ", let's get started!" << endl; // Tells the player we are going to get started
} //Main

void thanks_for_playing(){
	cout << "Thanks for playing! " << endl;
	//p();		/// final pause to allow thanks for playing to be read
} //Main

void line(){
	cout << endl << " ----------------------------------------------------------" << endl << endl;
}

void error()
{
	cout << "There was a error." << endl;
	cout << "The one in maindialouge.cpp" << endl;
	p();
}

void p(){ cout << endl;
	std::string command = "raw_input('Press ENTER to continue...";
		system("python /home/'Pinochle Linux'/pressanykey.py"); 
			//system("PAUSE");  Which says press any key to continue..
	}

void c()  {// system("cls");  Windows clear the command prompt
		system("clear"); // Linux Equivalent
	}

void candp()   {p(); c();}  // Calls pause and then clear

