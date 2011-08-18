/// My analysis on 8.8.11 is that this file is sloppy and isn't readable.  TODO: Write better code in the future.

#include "headers.h"
#include "scoreclass.h"
#include "hand.h"



void zero_out_array(int array_size, int * array) /// C# pointer problem fixed here.
{
int array_element = 0;
while (array_element < array_size)
	{
		*array = 0; /// This is sloppy use of pointers, this could lead to a SERIOUS memory bug.
		array_element++;
		array++;
	}
} // For C# this will be Array.clear()

void deal(int hand_counter, scoreclass & scr) /// Change howmany to something that makes sense
{
	int suitint = 0; 
	int bidding_times = 3;
	
	cout << "! # " << hand_counter << " !" << endl; 
	cout << "-------" << endl;
		
	string dealer;
	finddealer(hand_counter, dealer);  /// in hand.cpp

	player play = recieve_cards(1); 

	player wplay = recieve_cards(2); 
	
	play.getorder();
	
	cout << endl << "You recieved: " << endl; 
	
	play.cardnames();

	///These are the north computer players cards
	player nplay = recieve_cards(3); 

	///These are the east computer players cards
	player eplay = recieve_cards(4);  
	
	int ongoin_bid = 1; /// The bid that will be passed around alot

	int westpot = 0,northpot = 0,eastpot = 0,westscore = 0, northscore = 0,eastscore = 0, playerpot = 0, playerscore = 0;

	bool  westwin = false, northwin = false, eastwin = false, playerwin = false; 
	
	int card_passed[8];
	
	zero_out_array(8, &card_passed[0]); /// at the beginning of this file.

	string ppassed1, ppassed2, ppassed3, ppassed4; //Names of the cards passed later
	///The first call which tells the computer players their bids
	
	//The function that will give the players their score and allows the computerized players bid 
	
	scoring_func( &westscore, &northscore, &eastscore, &playerscore, &play, &wplay, &nplay, &eplay);

	bool westpass = false, northpass = false, eastpass = false, playerpass = false; // Booleans to see if the player passed
	
	int newcounter = 1, finalbid = 0; /// newcounter -- Used in bid() and bid.cpp functions, finalbid -- holds finalbid
	
	string winnername, suitname; // Makes the string that will hold the winner's name | suitname

	int howmanyofsuit(player &); ///In suit.cpp

	//These return how many of each suit the players have -- Allows them to easily pick their best suit
	howmanyofsuit(wplay);
	howmanyofsuit(nplay);
	howmanyofsuit(eplay);
		
	string westsuit;  // Holds the best suit for the players  // & playersuits(), bid()
	string northsuit; // & playersuits(), bid()
	string eastsuit;  // & playersuits(), bid()
	
	 //located in hand.cpp -- Decides the best suit
	playersuits( westsuit, northsuit, eastsuit, wplay, nplay, eplay);

	play.getorder();

	bool continue_bidding = true; // Used below to keep the loop going // & Used in bid, if statement
	while(continue_bidding == true) // Bidding Loop
{	 
	bid(westsuit, northsuit, eastsuit,&newcounter,&bidding_times, &continue_bidding, &ongoin_bid, westpot , northpot, eastpot ,&playerpass, &westpass,&northpass,&eastpass,&westwin, &northwin, &eastwin, &playerwin, 
		&finalbid, &winnername, &suitint, play); 

		if (suitint > 0)
		{	switch(suitint)
			{
			case 1:
				suitname = "Hearts";
				break;
			case 2:
				suitname = "Diamonds";
				break;
			case 3:
				suitname = "Spades" ;
				break;
			case 4:
				suitname = "Clubs" ;
				break;
			default:
				error();
				break;
			}
		}
		if ( westpass == true &&northpass == true && eastpass == true)
		{
			break;
		}
}

	 /// The second call after all the bidding is over to scoring_func
	scoring_func( &westscore, &northscore, &eastscore, &playerscore, &play, 
		&wplay, &nplay,&eplay);

	bool firsttime = true; // Used to see if its the pass to the partner who won the deal or the pass back // & 2 x passing()
	
	/// Passing is ugly and should only require one function that is 100 times simpler than this one.
	
	///This will require knowing who are partners and then the passing probably will be quite difficult, but we will see.
	passing(winnername,  &ppassed1, &ppassed2, &ppassed3, &ppassed4, &card_passed[0], &card_passed[1],&card_passed[2], 
		&card_passed[3], &card_passed[4], &card_passed[5], &card_passed[6], &card_passed[7], nplay, wplay, eplay, play,
		suitname,  &firsttime); 
		// & Ideally these will take only player instances to make them work -- This code 
		//looks like a project to simplify however.
		// Rule: Make all your code as easy to read as possible when writing it... name it for what it does.

	passing(winnername, &ppassed1, &ppassed2, &ppassed3, &ppassed4, &card_passed[4], &card_passed[5],&card_passed[6], 
		&card_passed[7], &card_passed[0], &card_passed[1], &card_passed[2], &card_passed[3], nplay, wplay, eplay, play,
		suitname,   &firsttime);
	
	cardschangehands(winnername, &card_passed[0], &card_passed[1], &card_passed[2],&card_passed[3],&card_passed
		[4],&card_passed[5],&card_passed[6],&card_passed[7], &play, &wplay, &nplay, &eplay);

	play.getorder(); /// Why do these need to be called?
	
	wplay.getorder(); 

	nplay.getorder();

	eplay.getorder();

	line();

	alltrick test; // & This holds all the tricks played in play_hands()

	play_hand(winnername, suitname, play, wplay, nplay, eplay, test, suitint);

	p();
	
	cout << endl << "--Meld--" << endl;
	cout << " Player is: " << playerscore << endl;
	cout << " West is : " <<  westscore << endl; 
	cout << " North is : " <<  northscore << endl;
	cout << " East is : " <<  eastscore << endl;

	line();
	
	finalscoring(test, scr);

	//cout << endl << "Winnername: " << winnername << endl;
	cout << "Finalbid: " << finalbid << endl;
	//cout << "Playerscore is : " << playerscore << endl << endl;

	if (winnername == "Player" || winnername == "North")
	{
		if (finalbid <= (playerscore + northscore + scr.scoreteam1()) && (scr.accessplayer() > 0 || scr.accessnorth() >0) 
			&& (winnername == "North" || winnername == "Player"))
	{
		
		cout << "You got your bid!" << endl;
		scr.accessplayer(scr.accessplayer()+playerscore);
		scr.accessnorth(scr.accessnorth() + northscore);

	}
		else { cout << "You got set!" << endl;
		scr.accessplayer(0);
		scr.accessnorth(0);
		}
		if (scr.accesswest() > 0 || scr.accesseast() > 0) { 
		scr.accesswest(scr.accesswest()+westscore);
		scr.accesseast(scr.accesseast()+eastscore);
		}
	}
	
	if (winnername == "West" || winnername == "East")
	{
		if (finalbid <= (westscore + eastscore + scr.scoreteam2()) &&( scr.accesswest() > 0 && winnername == "West") ||
			(scr.accesseast() > 0 && winnername == "East"))
	{
		cout << "The other team got the bid!" << endl;
	scr.accesswest(scr.accesswest()+westscore);
	scr.accesseast(scr.accesseast()+eastscore);
		}
		else { cout << "The other team got set!" << endl;
		scr.accesswest(0);
		scr.accesseast(0);
		}
		if (scr.accessnorth() > 0 || scr.accessplayer() > 0) 
		{
		scr.accessplayer(scr.accessplayer()+playerscore);
		scr.accessnorth(scr.accessnorth() + northscore);
		}
	}
	scr.scoreboard();
}

void srand_()
{
	srand((unsigned)time(NULL));
}

int finddealer(int & whoptr, string & dealer)
{
	int local_counter = whoptr;
	while (local_counter > 4)
	{
		local_counter -=  4;
	}
	switch(local_counter)
	{
	case 1: 
		{
			cout << "You are the dealer." << endl;
			dealer = "Player";
			break;
		}
	case 2:
		{
			cout << "West is dealing" << endl;
			dealer = "West";
			break;
		}
	case 3: 
		{
			cout << "North is dealing" << endl;
			dealer = "North" ;
			break;
		}
	case 4:
		{
			cout << "East is dealing" << endl;
			dealer = "East";
			break;
		}
	default:
		{
			cout << "I don't know who is dealing --- This is an error!" << endl;
		}
	}
return whoptr;
}


void playersuits(string & westsuit, string & northsuit, string & eastsuit, player & west_player, player & north_player, player & east_player) 
				 /// This is confusing: TODO: Clean this so it makes sense/ check if it even works
{
	void pick_suit_logic(player & west_player, string & westsuit);
	
	pick_suit_logic(west_player, westsuit);
	
	pick_suit_logic(north_player, northsuit);

	pick_suit_logic(east_player, eastsuit);
}

void pick_suit_logic(player & west_player, string & westsuit)
{
		/// This uses the west_player as a prototype and picks the best suit for the players. 
	int x = 1; // x - 1 is the number of suits eliminated by the first check.
	int suit[4];
	zero_out_array(4, &suit[0]); 
	
	//First check if any can be easily eliminated
	//Adds a value to the howmanyplace array if there are less than 3 cards in a suit.
	if (west_player.howmanyhearts < 3) 
	{
		suit[0] = x; 
		x++;
	}
	if (west_player.howmanydiamonds < 3) 
	{
		suit[1] = x; 
		x++;
	}
	if (west_player.howmanyspades < 3) 
	{
		suit[2] = x; 
		x++;
	}
	if (west_player.howmanyclubs < 3) 
	{
		suit[3] = x; 
		x++;
	}	
	
	
	ofstream outplayer1("playersuitsdebugging.txt");
	outplayer1 << "X is: " <<  x << endl;
	outplayer1 <<  "hearts: " << west_player.howmanyhearts << endl;
	outplayer1 << "hearts power: " << west_player.heartspower << endl;
	outplayer1 <<  "diamonds: " << west_player.howmanydiamonds << endl;
	outplayer1 << "diamonds power: " << west_player.diamondspower << endl;
	outplayer1 <<  "spades: " << west_player.howmanyspades << endl;
	outplayer1 << "spades power: " << west_player.spadespower << endl;
	outplayer1 <<  "clubs: " << west_player.howmanyclubs << endl;
	outplayer1 << "clubs power: " << west_player.clubspower << endl;
	
	outplayer1 << "suit[0] is: " << suit[0] << endl; // If this is greater than 0 the suit is eliminated from consideration.
	
	outplayer1 << "suit[1] is: " << suit[1] << endl;
	outplayer1 << "suit[2] is: " << suit[2] << endl;
	outplayer1 << "suit[3] is: " << suit[3] << endl;
	
	outplayer1 << x - 1 << " can be eliminated from consideration." << endl;
	
	double suitworth_hearts = 7,suitworth_diamonds = 7,suitworth_spades = 7,suitworth_clubs = 7;
	// The 7s allow me to rule out the eliminated suits.
	
	if(suit[0] == 0 ) // If hearts is not eliminated
	{
		double suitworth1 = ((double)west_player.heartspower / west_player.howmanyhearts);
		outplayer1 << "suitworth 1st operation! " << suitworth1 << endl;
		suitworth1 = suitworth1 - (west_player.howmanyhearts - 1 ) * .75;
		outplayer1 << "suitworth of hearts: " << suitworth1 << endl;
		suitworth_hearts = suitworth1;
	}
	
	if(suit[1] == 0 ) // If diamonds is not eliminated
	{
		double suitworth2 = ((double)west_player.diamondspower / west_player.howmanydiamonds);
		outplayer1 << "suitworth 1st operation! " << suitworth2 << endl;
		suitworth2 = suitworth2 - (west_player.howmanydiamonds -1 ) * .75;
		outplayer1 << "suitworth of diamonds: " << suitworth2 << endl;
		suitworth_diamonds = suitworth2;
	}
	
	if(suit[2] == 0 ) // If spades is not eliminated
	{
		double suitworth3 = ((double)west_player.spadespower / west_player.howmanyspades);
		outplayer1 << "suitworth 1st operation! " << suitworth3 << endl;
		suitworth3 = suitworth3 - (west_player.howmanyspades - 1) * .75;
		outplayer1 << "suitworth of spades: " << suitworth3 << endl;
		suitworth_spades = suitworth3;
	}
	
	if(suit[3] == 0 ) // If clubs is not eliminated
	{
		double suitworth4 = ((double)west_player.clubspower / west_player.howmanyclubs);
		outplayer1 << "suitworth 1st operation! " << suitworth4 << endl;
		suitworth4 = suitworth4 - (west_player.howmanyclubs - 1) * .75;
		outplayer1 << "suitworth of clubs: " << suitworth4 << endl;
		suitworth_clubs = suitworth4;
	}
	
	bool itworked = false;
	
	if(suitworth_hearts != 7 && (suitworth_hearts < suitworth_diamonds && suitworth_hearts < suitworth_spades
	 && suitworth_hearts < suitworth_clubs)) 
	{
		outplayer1 << "Suit hearts was picked!" << endl;
		westsuit = "Hearts";
		itworked = true;
	}
	
	if(suitworth_diamonds != 7 && (suitworth_diamonds < suitworth_hearts && suitworth_diamonds < suitworth_spades 
		&& suitworth_diamonds < suitworth_clubs))
	{
		outplayer1 << "Suit diamonds was picked!" << endl;
		westsuit = "Diamonds";
		itworked = true;
	}
	
	if(suitworth_spades != 7 && (suitworth_spades < suitworth_diamonds && suitworth_spades < suitworth_hearts 
	&& suitworth_spades < suitworth_clubs)) 
	{
		outplayer1 << "Suit spades was picked!" << endl;
		westsuit = "Spades";
		itworked = true;
	}
	
	if(suitworth_clubs != 7 && (suitworth_clubs < suitworth_diamonds && suitworth_clubs < suitworth_spades 
	&& suitworth_clubs < suitworth_hearts)) 
	{
		outplayer1 << "Suit clubs was picked!" << endl;
		westsuit = "Clubs";
		itworked = true;
	}
	if (itworked == false)
	{
		outplayer1 << "Itworked is false! Last chance to declare suit." << endl;
		// These take it down to two for sure.  Will finish when I have a chance.
		if (suitworth_hearts != 7 && (suitworth_hearts <= suitworth_diamonds && suitworth_hearts <= suitworth_spades
		 && suitworth_hearts <= suitworth_clubs))
		{
			
		}
		if (suitworth_diamonds != 7 && (suitworth_diamonds <= suitworth_hearts && suitworth_diamonds <= suitworth_spades 
		&& suitworth_diamonds <= suitworth_clubs))
		{
			
		}
		if (suitworth_spades != 7 && (suitworth_spades <= suitworth_diamonds && suitworth_spades <= suitworth_hearts 
		&& suitworth_spades <= suitworth_clubs))
		{
			
		}
		if (suitworth_clubs != 7 && (suitworth_hearts <= suitworth_diamonds && suitworth_clubs <= suitworth_spades 
		&& suitworth_clubs <= suitworth_hearts))
		{
			
		}
		westsuit = "Hearts"; // This is cheating, I think other functions need to be developed before I finish this.  
		/// Specifically I am looking for something that checks for pinochles and meld so they can see which hand is 
		///better for them.
	}
	
	if (westsuit != "Hearts" && westsuit != "Diamonds" && westsuit != "Spades" && westsuit != "Clubs")
	{
		//if (west_clubs == west_diamonds || west_diamonds == west_hearts 
		//cout << "There was an error with Westsuit! in cards.cpp -- playersuits()" << endl;
		westsuit = "Clubs";
	}
	outplayer1.close();	
}


