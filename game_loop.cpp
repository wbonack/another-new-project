#include "headers.h"
#include "scoreclass.h"
void deal(string * nameptr,int counter,  scoreclass & scr);
bool play_more();

void game_loop(string * nameptr, int counter, bool * keep_goingptr, int & score, scoreclass & scr) // Runs every hand to keep the hand going
///Later we will need a way to pass scores from hand to hand
{
	scr.counter = counter;
	deal(nameptr,counter, scr);	 ///  located in hand.cpp -- Starts the function deal

	//& = is the rewrite symbol -- Notes made of the rewrite starting June 7th 2010
	//& This game currently has tons of hacks and temporary solutions that you never fixed... It will be a lot of work.
			
	if (scr.scoreteam1() >= 150) 
		{ line();  cout << "Team1 won the game!" << endl;  p(); *keep_goingptr = false;}
			
	if (scr.scoreteam2() >= 150) 
		{ line();  cout << "Team2 won the game!" << endl;  p(); *keep_goingptr = false;}
			
	//Later I will implement the hiscores/wins to a file or something.

	///Asks if the player wishes to play more -- Takes that answer and converts it to a boolean
	*keep_goingptr = play_more(); // play_more is now in game_loop_dialouge

	c();      //Clears the screen after a hand has been played
}

bool play_more()
{
	cout << "Do you want to keep playing this game."  << endl << "(Y/N)" << endl;
	
	bool decision;
	char yes_or_no;

	cin >> yes_or_no;

	if (yes_or_no == 'y' || yes_or_no == 'Y')	{decision = true;}

	if (yes_or_no == 'n' || yes_or_no == 'N')	{ decision = false;}

	if (yes_or_no != 'y' && yes_or_no != 'Y' && yes_or_no != 'n' && yes_or_no != 'N')
	{	
		cout << "Try again." << endl;
		return play_more();
	}
	
	return decision;
}
