///Pinochle Project Main.cpp
///This will start as a command line project and eventually I hope to use it in a window based environment.

#include "headers.h"    
#include "scoreclass.h"

void welcome();
void namepicking(string & name);
void game_loop(string * nameptr, int counter, bool * keep_goingptr, int &, scoreclass &);
void thanks_for_playing();

ostream &operator<<(ostream &os, card & c){ cout << "(" << c.order << ") " << c.name ; 
	return os;
	} //11:  What class does this go to? What does this do?

int main()	 ///main function - Program starts here
{                  
	string name;  /// Makes the name ( first is the first name - second is the optional last name or second part)
		
	bool keep_going = true;			/// Helps determine if the game should keep going
	int score = 0;
	scoreclass scr;  
	welcome();						/// this function is in maindialouge.cpp, it welcomes the player
	namepicking(name);		///In maindialouge..helps the player make a name  
	//-- This passes the names that the player will use

	candp();	//Windows only commands that make a Press any key to continue ..... and clear the console
	// (I will have to find an alterative to this in linux.)  system("ifconfig") works great in linux!
	
	for(int counter = 1; keep_going == true; counter++)  // Counter for the number of hands played
	{
		if (keep_going)				// The loops for the game to continue
	  {		
		 game_loop(&name, counter, &keep_going, score, scr); /// Goes to game loop in gameloop.cpp
						
		keep_going == false;
	  }
		if (!keep_going)				// If keep going is false, this exits the game 
	  {
		 thanks_for_playing();			// Thanks for playing, which is after welcome, two functions down
	  }
	}
}

