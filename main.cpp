///Pinochle Project Main.cpp
///This will start as a command line project and eventually I hope to use it in a window based environment.

#include "headers.h"    
#include "scoreclass.h"

void welcome();
void pickname(string & name);
bool game_loop( int counter,  scoreclass &);
void thanks_for_playing();

int main()	 ///main function - Program starts here
{                  
	string Player_name; 
		
	bool keep_going = true;		
	
	int score = 0;
	
	scoreclass scr;      		/// Is this really necessary / What does this do?
	
	welcome();					///  in maindialouge.cpp
	
	pickname(Player_name);				///In maindialouge.cpp
	
	candp();	
	
	for(int counter = 1; keep_going == true; counter++)  /// counter keeps track of the number of hands played
	{
		if (keep_going)				
	  {		
		 keep_going = game_loop( counter,  scr); /// In game_loop.cpp	
	  }
		if (!keep_going)				
	  {
		 thanks_for_playing();			/// In maindialouge.cpp
	  }
	}
}

