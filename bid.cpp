#include "headers.h"

void otherbidding(int * ongoinptr, int, bool*);  // Bidding depending on their initial cards
	
int bidding(int * bidding_counter, bool * loop, int * ongoinprt, bool * playerbidding, player);

int suitpicking(string, string, string,int *, string, player play1); // Used later to declare trump.

void bidding_dialouge(int counter);

int suittonumber(string);

void bid(string westsuit, string northsuit, string eastsuit, int* newcounter, int * timesbidding, bool * forloopptr, int * ongoinptr, int west , int north, int east, bool * playerpass, bool*westpass,bool*northpass, bool*eastpass, bool * westwin, bool * northwin, bool * eastwin, bool * playerwin, int * finalbid, string * winner, int * suit, player play1)
{
	string bidder; 
	int bidforloopcounter = *timesbidding;
	bool dog = true;
	bool bidding_func(string, string, string,string bidder, int *, int * timesbidding, int bidforloopcounter,bool * 		loop, int * ongoinptr,int,int,int,bool *,bool*, bool*, bool*, bool*, bool*, bool*, bool*, string *, 	
		int*, player);
	
	*forloopptr = bidding_func(westsuit, northsuit, eastsuit, bidder, newcounter, timesbidding, bidforloopcounter, &dog, 	
		ongoinptr,west, north, east, playerpass,westpass, northpass, eastpass, westwin, northwin, eastwin, playerwin, 
		winner, suit, play1 );

    	*finalbid = *ongoinptr;
	
	bidforloopcounter ++;
}

bool bidding_func(string westsuit, string northsuit, string eastsuit,string bidder, int * newcounter, int * timesbidding, int bidforloopcounter, bool * loop, int * ongoinptr, int west, int north,int east, bool * playerpass, bool * westpass, bool* northpass, bool*eastpass, bool * westwin, bool * northwin,bool * eastwin, bool * playerwin, string * winner, int * suit, player play1)
{
	switch(*timesbidding)/// Used to output who is bidding
	{
	case 1: 
		{
			cout << endl << "East bids." << endl;
			bidder = "East bids ";
			break;
		}
	case 2:
		{
			cout << endl<< "You bid." << endl;
			bidder = "You bid ";
			break;
		}
	case 3:
		{
			cout << endl<< "West bids." << endl;
			bidder = "West bids " ;
			break;
		}
	case 4:
		{
			cout << endl<< "North bids." << endl;
			bidder = "North bids " ;
			break;
		}

	default:
		{
			cout << endl<< "ERROR in Bid" << endl;
		}
	}

	candp();
	int bidcounter = 1;
	while (bidcounter < 5)
{
	if (bidder == "You bid ")
	{
		if (*playerpass == false)
		{
		cout << "You bid next, what will you do?" << endl <<endl;
		*ongoinptr = bidding(newcounter, loop, ongoinptr, playerpass, play1);
		}
		bidder = "West bids ";
		bidcounter++;
	}	
	if (bidcounter == 5) { break;}
	if (bidder == "West bids ")
	{
		if (*westpass == false)
		{
		cout << "West bids next" << endl;
		otherbidding(ongoinptr, west, westpass);
		}
		bidder = "North bids ";
		bidcounter++;
	}
	if (bidcounter == 5) { break;}
	if (bidder == "North bids ")
	{
		if (*northpass == false)
		{
		cout << "North bids next" << endl;
		otherbidding(ongoinptr, north, northpass);
		}
		bidder = "East bids ";
		bidcounter++;
	}
	if (bidder == "East bids ")
	{
		if (*eastpass == false)
		{
		cout << "East bids next" << endl;
		otherbidding(ongoinptr, east, eastpass);
		}
		bidder = "You bid ";
		bidcounter++;
	}
	if (bidcounter == 5) { break;}
	
}

	if (*playerpass == true) { *playerwin = true; }

	if (*westpass == true) { *westwin = true;}

	if (*northpass == true) { *northwin = true;}

	if (*eastpass == true) { *eastwin = true;}

	if (*eastwin == true && *northwin == true && *westwin == true) // This one says the player won the bid
	{
		cout << "Player got the bid! For: " << *ongoinptr << endl;
		*winner = "Player";
		suitpicking(westsuit, northsuit, eastsuit, suit, *winner, play1);
		p();
		return false;
	}

	if (*playerwin == true && *northwin == true && *westwin == true) //Says East player got the bid!
	{
		cout << "East player got the bid! For: " << *ongoinptr << endl;
		*winner = "East";
		suitpicking(westsuit, northsuit, eastsuit, suit, *winner, play1);
		p();
		return false;
	}

	if (*eastwin == true && *playerwin == true && *westwin == true) // Says North got the bid
	{
		cout << "North got the bid!  For: " << *ongoinptr<< endl;
		*winner = "North";
		suitpicking(westsuit, northsuit, eastsuit, suit, *winner,play1);
		p();
		return false;
	}

	if (*eastwin == true && *northwin == true && *playerwin == true)  // Says West got the bid
	{
		cout << "West player got the bid!  For: " << *ongoinptr << endl;
		*winner = "West";
		suitpicking(westsuit, northsuit, eastsuit, suit, *winner, play1);
		p();
		return false;
	}



	if (*loop == true) 
	{
		return true;
	}

	if (*loop == false)
	{
	return false;
	}

}

int bidding(int * bidding_counter, bool * loop, int * ongoinptr, bool * playerpass, player play1)
{
	int ongoing_bid = *ongoinptr;
	if (*ongoinptr ==1)
	{
		ongoing_bid = 25; 
	}

	if (*ongoinptr >1)
	{
		ongoing_bid = *ongoinptr;
	}

	cout << " -----------------------------" << endl;
	cout << "|                             |" <<endl;
	cout << "| Current bid is :" << ongoing_bid << "          |" << endl;
	cout << "|                             | " <<  endl;
	cout << " -----------------------------" << endl;
	cout << endl;

	play1.cardnames();
	
	bidding_dialouge(*bidding_counter);

	int bidding_decision;
	cin >> bidding_decision;
	
	if (bidding_decision == 1)
	{
		ongoing_bid++;
		cout << "You bid " << ongoing_bid << "." <<  endl;
	}
	
	if (bidding_decision ==2)
	{
		cout << "2" << endl;
		cout << "You passed." << endl;
		*playerpass = true;

	}
	if (bidding_decision ==3)
	{
		cout << "3" << endl;
		cout << "What bid would you like to place?" << endl;
		int bidtoplace;
		cin >> bidtoplace;
		
		if (bidtoplace >= ongoing_bid + 10)
		{
			cout << "Are you sure you want to place that high of a bid? (Y/N)" << endl;
			char yes_or_no;
			cin >> yes_or_no;
			if (yes_or_no == 'y' ||yes_or_no == 'Y')
			{
				cout << "Ok, you bid: " << bidtoplace << endl;
				ongoing_bid = bidtoplace;
			}
			else
			{
				cout << "Ok, you will bid one up for now." << endl;
				///The above line should be changed and make it start over 
				ongoing_bid ++;
				cout << "You bid: " << ongoing_bid << endl;
			}
		}
		
		if (bidtoplace < ongoing_bid)
		{
			cout << "The number you entered was lower than the original bid" << endl;
			///Here will be something to return the user to start over
		}
		
		if (bidtoplace >= ongoing_bid + 1 && bidtoplace <= ongoing_bid +19)
		{
			cout << "You bid: " << bidtoplace << endl;
			ongoing_bid = bidtoplace;
		}
	}

	if (bidding_decision == 4 && ongoing_bid <26 )
	{
		cout << "You bid : " << 25 << endl;
		ongoing_bid = 25;
	}

	if (bidding_decision ==5)
	{
		cout << "Cheater!: Ok, you bid: " << 99 << endl;
				ongoing_bid = 99;
	}
	
	if (bidding_decision <1 || bidding_decision >5 )
	{
		cout << "none of those" << endl;
		p();
		bidding(bidding_counter,  loop, ongoinptr,  playerpass, play1);
		//*loop = false;
	}
	
	return ongoing_bid;
}

//suitpicking
int suitpicking(string westsuit, string northsuit, string eastsuit,int * suit, string winner, player play1)
{
	cout << "The winner was: " << winner << endl;
	p();
	
	if (winner == "Player")
	{ 
	cout << "Which suit do you want to be trump?" <<endl << endl ;

	play1.cardnames();
	cout << endl << "(1) Hearts " << endl;
	cout << "(2) Diamonds"<< endl;
	cout << "(3) Spades" << endl;
	cout << "(4) Clubs" << endl;
	int decision;
	cin >> decision;

	if (decision > 4 || decision <1)
	{
		cout << "Try again." << endl << endl;
		suitpicking(westsuit, northsuit, eastsuit, suit, winner, play1);
	}

	if (decision == 1)
	{
		cout << "You picked Hearts to be trump." << endl;
		*suit = 1;
	}
	if (decision == 2)
	{
		cout << "You picked Diamonds to be trump." << endl;
		*suit = 2;
	}
	if (decision == 3)
	{
		cout << "You picked Spades to be trump." << endl;
		*suit = 3;
	}
	if (decision == 4)
	{
		cout << "You picked Clubs to be trump." << endl;
		*suit = 4;
	}
	
	}
	
	if (winner == "West"|| winner == "North" || winner == "East") 
		//Whats needs to go here is a trump picker for the computer players
	{
		if (winner == "West"){  *suit = suittonumber(westsuit) ;}
		if (winner == "North"){ *suit = suittonumber(northsuit);}
		if (winner == "East"){  *suit = suittonumber(eastsuit);}
	}
	return 0;
}


int suittonumber(string suit)	// A useful function that can be reused  -- Makes a suit into a number
{
	if (suit == "Hearts") {return 1;}
	if (suit == "Diamonds") { return 2;}
	if (suit == "Spades") { return 3;}
	if (suit == "Clubs")  { return 4;}
}

///This comes from bid.cpp from the function bidding
void bidding_dialouge(int counter)
{
	cout << "Would you like to... " << endl;
	cout << "  (1)Bid 1 up" << endl;
	cout << "  (2)Pass" << endl;
	cout << "  (3)Write in your own bid." << endl;
	if (counter ==2 )  { cout << "  (4)Open with 25." << endl;}
	cout << endl;
}

	void otherbidding(int * ongoinptr, int maxbid, bool * pass)
	{
		
		if (*ongoinptr ==1)
	{
		*ongoinptr  = 25; 
	}
		//cout << "---players bidding in others---" << endl;
		if (*ongoinptr > maxbid)
		{
			cout << "The player passed" << endl;
			*pass = true;
		}

		if (*ongoinptr <= maxbid && *pass == false)
		{
			cout << "Player bid up one" << endl;
			(*ongoinptr)++;
		}
		cout << endl;
	}
