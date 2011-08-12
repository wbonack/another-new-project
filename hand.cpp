/// My analysis on 8.8.11 is that this file is sloppy and isn't readable.  TODO: Write better code in the future.

#include "headers.h"
#include "scoreclass.h"
#include "hand.h"

void zero_out_array(int array_size, int * array) 
{
int array_element = 0;
while (array_element < array_size)
	{
		*array = 0; /// This is sloppy use of pointers, this could lead to a SERIOUS memory bug.
		array_element++;
		array++;
	}
}

void deal(int hand_counter, scoreclass & scr) /// Change howmany to something that makes sense
{
	int suitint = 0; 
	int bidding_times = 3;
	
	cout << "! # " << hand_counter << " !" << endl; 
	cout << "-------" << endl;
		
	string dealer;   
	finddealer(&hand_counter, &dealer);  /// in hand.cpp

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
	scoring_func(&playerpot, &westpot, &northpot, &eastpot, &westscore, &northscore, &eastscore, &playerscore, &play, &wplay, &nplay, &eplay);

	bool westpass = false, northpass = false, eastpass = false, playerpass = false; // Booleans to see if the player passed
	int newcounter = 1, finalbid = 0; /// newcounter -- Used in bid() and bid.cpp functions, finalbid -- holds finalbid
	
	string winnername, suitname; // Makes the string that will hold the winner's name | suitname

	suit heart("heart");

	//These return how many of each suit the players have -- Allows them to easily pick their best suit
	 heart.howmanyofsuit(wplay);
	 heart.howmanyofsuit(nplay);
	 heart.howmanyofsuit(eplay);
		
	string westsuit;  // Holds the best suit for the players  // & playersuits(), bid()
	string northsuit; // & playersuits(), bid()
	string eastsuit;  // & playersuits(), bid()
	
	 //located in cards.cpp -- Decides the best suit
	playersuits(&westsuit, &northsuit, &eastsuit, wplay, nplay, eplay);

	play.getorder();

	bool continuetheforloop = true; // Used below to keep the loop going // & Used in bid, if statement
	while(continuetheforloop == true) // Bidding Loop
{	 
	bid(westsuit, northsuit, eastsuit,&newcounter,&bidding_times, &continuetheforloop, &ongoin_bid, westpot , northpot, eastpot ,&playerpass, &westpass,&northpass,&eastpass,&westwin, &northwin, &eastwin, &playerwin, 
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
		if ( westpass == true&&northpass == true&& eastpass == true){break;}
}

	 /// The second call after all the bidding is over to scoring_func
	scoring_func(&playerpot, &westpot, &northpot, &eastpot, &westscore, &northscore, &eastscore, &playerscore, &play, 
		&wplay, &nplay,&eplay);

	bool firsttime = true; // Used to see if its the pass to the partner who won the deal or the pass back // & 2 x passing()
	
	///This will require knowing who are partners and then the passing probably will be quite difficult, but we will see.
	passing(winnername,  &ppassed1, &ppassed2, &ppassed3, &ppassed4, &card_passed[0], &card_passed[1],&card_passed[2], 
		&card_passed[3], &card_passed[4], &card_passed[5], &card_passed[6], &card_passed[7], &nplay, &wplay, &eplay, 
		suitname, &firsttime, &play); // & Ideally these will take only player instances to make them work -- This code 
		//looks like a project to simplify however.
		// Rule: Make all your code as easy to read as possible when writing it... name it for what it does.

	passing(winnername, &ppassed1, &ppassed2, &ppassed3, &ppassed4, &card_passed[4], &card_passed[5],&card_passed[6], 
		&card_passed[7], &card_passed[0], &card_passed[1], &card_passed[2], &card_passed[3], &nplay, &wplay, &eplay, 
		suitname, &firsttime, &play);
	
	cardschangehands(winnername, &card_passed[0], &card_passed[1], &card_passed[2],&card_passed[3],&card_passed
		[4],&card_passed[5],&card_passed[6],&card_passed[7], &play, &wplay, &nplay, &eplay);

	play.getorder();
	
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

int finddealer(int * whoptr, string * dealer)
{
	int local_counter = *whoptr;
	while (local_counter > 4)
	{
		local_counter -=  4;
	}
	switch(local_counter)
	{
	case 1: 
		{
			cout << "You are the dealer." << endl;
			*dealer = "Player";
			break;
		}
	case 2:
		{
			cout << "West is dealing" << endl;
			*dealer = "West";
			break;
		}
	case 3: 
		{
			cout << "North is dealing" << endl;
			*dealer = "North" ;
			break;
		}
	case 4:
		{bool continuetheforloop = true; // Used below to keep the loop going // & Used in bid, if statement
			cout << "East is dealing" << endl;
			*dealer = "East";
			break;
		}
	default:
		{
			cout << "I don't know who is dealing --- This is an error!" << endl;
		}
	}
return *whoptr;
}


void playersuits(string * westsuit, string * northsuit, string * eastsuit, player west_player, player north_player, player east_player) 
				 /// This is confusing: TODO: Clean this so it makes sense/ check if it even works
{
	/// This is a hack and doesn't really pick the best suit for the opposing player.  
	
	/* To find the best suit:
		1) Find the suit with the most cards
		2) Pick the suit with the most powerful cards / best chance at winning the hand.
		3) Keep pinochles in mind when deciding / double runs although rare.
	*/
	
	if (west_player.howmanyhearts > west_player.howmanydiamonds && west_player.howmanyhearts > west_player.howmanyspades && west_player.howmanyhearts > west_player.howmanyclubs)
	{	*westsuit = "Hearts";	}

	if (west_player.howmanydiamonds > west_player.howmanyhearts && west_player.howmanydiamonds > west_player.howmanyspades && west_player.howmanydiamonds >  west_player.howmanyclubs)
	{*westsuit = "Diamonds";}

	if (west_player.howmanyspades > west_player.howmanydiamonds && west_player.howmanyspades > west_player.howmanyhearts && west_player.howmanyspades >  west_player.howmanyclubs)
	{	*westsuit = "Spades";}

	if ( west_player.howmanyclubs > west_player.howmanydiamonds &&  west_player.howmanyclubs > west_player.howmanyspades &&  west_player.howmanyclubs > west_player.howmanyhearts)
	{	*westsuit = "Clubs";}
	
	ofstream out("error.txt");
	out << "West power is: " << west_player.first1.power << endl;
	out.close();
	if (west_player.howmanyhearts == west_player.howmanydiamonds)
	{
		/// Check which suit has more power.
		
		
	}
	if (*westsuit != "Hearts" && *westsuit != "Diamonds" && *westsuit != "Spades" && *westsuit != "Clubs")
	{
		//if (west_clubs == west_diamonds || west_diamonds == west_hearts 
		//cout << "There was an error with Westsuit! in cards.cpp -- playersuits()" << endl;
		*westsuit = "Clubs";
	}

	if (north_player.howmanyhearts > north_player.howmanydiamonds && north_player.howmanyhearts >north_player.howmanyspades&& north_player.howmanyhearts > north_player.howmanyclubs)
	{	*northsuit = "Hearts";}

	if (north_player.howmanydiamonds > north_player.howmanyhearts && north_player.howmanydiamonds > north_player.howmanyspades && north_player.howmanydiamonds > north_player.howmanyclubs)
	{	*northsuit = "Diamonds";}

	if (north_player.howmanyspades > north_player.howmanydiamonds && north_player.howmanyspades > north_player.howmanyhearts && north_player.howmanyspades > north_player.howmanyclubs)
	{	*northsuit = "Spades";}

	if (north_player.howmanyclubs > north_player.howmanydiamonds && north_player.howmanyclubs > north_player.howmanyspades && north_player.howmanyclubs > north_player.howmanyhearts)
	{	*northsuit = "Clubs"; }

	if (*northsuit != "Hearts" && *northsuit != "Diamonds" && *northsuit != "Spades" && *northsuit != "Clubs")
	{
		//cout << "There was an error with Northsuit! in cards.cpp -- playersuits()" << endl;
		*northsuit = "Clubs";
	}

	if (east_player.howmanyhearts > east_player.howmanydiamonds && east_player.howmanyhearts > east_player.howmanyspades && east_player.howmanyhearts > east_player.howmanyclubs)
	{	*eastsuit = "Hearts";}

	if (east_player.howmanydiamonds > east_player.howmanyhearts && east_player.howmanydiamonds > east_player.howmanyspades && east_player.howmanydiamonds > east_player.howmanyclubs)
	{	*eastsuit = "Diamonds";}

	if (east_player.howmanyspades > east_player.howmanydiamonds && east_player.howmanyspades > east_player.howmanyhearts && east_player.howmanyspades > east_player.howmanyclubs)
	{	*eastsuit = "Spades";}

	if (east_player.howmanyclubs > east_player.howmanydiamonds && east_player.howmanyclubs >east_player.howmanyspades && east_player.howmanyclubs > east_player.howmanyhearts)
	{	*eastsuit = "Clubs"; }

	if (*eastsuit != "Hearts" && *eastsuit != "Diamonds" && *eastsuit != "Spades" && *eastsuit != "Clubs")
	{
		//cout << "There was an error with Eastsuit! in cards.cpp -- playersuits()" << endl;
		*eastsuit = "Clubs";
	}
}


