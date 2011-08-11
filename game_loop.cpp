#include "headers.h"
#include "scoreclass.h"

void deal( int counter,  scoreclass & scr);
bool play_more();

bool game_loop( int counter, scoreclass & scr) 
///TODO:  Later we will need a way to pass scores from hand to hand
{
	deal( counter, scr);	 /// in hand.cpp
	
	if ((scr.scoreteam1() >= 150 && scr.scoreteam2() < scr.scoreteam1()) 
		{ line();  cout << "Team1 won the game!" << endl;  p(); return false;}
			
	if (scr.scoreteam2() >= 150 && scr.scoreteam1() < scr.scoreteam2()) 
		{ line();  cout << "Team2 won the game!" << endl;  p(); return false;}
			
	//TODO:  implement the hiscores/wins to a file or something.

	return play_more(); // in this file

	c();
}

bool play_more()
{
	bool decision;
	char yes_or_no;
	
	cout << "Do you want to keep playing this game."  << endl << "(Y/N)" << endl;
	
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
