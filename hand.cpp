/// My analysis on 8.8.11 is that this file is sloppy and isn't readable and not useful.  TODO: Write better code in the future.

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


	p();

	int counter = 1;
        player play = recieve_cards(counter); 

	player wplay = recieve_cards(counter); 
	
	play.getorder();
	
	cout << endl << "You recieved: " << endl; 
	
	play.cardnames();

	///These are the north computer players cards
	player nplay = recieve_cards(counter); 

	///These are the east computer players cards
	player eplay = recieve_cards(counter);  
	
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
	suit diamond("diamond");
	suit spade("Spade");
	suit club("clubs");

	//These return how many of each suit the players have -- Allows them to easily pick their best suit
	int westheartnumber = heart.howmanyofsuit(wplay.card1, wplay.card2, wplay.card3, wplay.card4, wplay.card5, 
		wplay.card6, wplay.card7, wplay.card8, wplay.card9, wplay.card10, wplay.card11, wplay.card12);
	int northheartnumber = heart.howmanyofsuit(nplay.card1, nplay.card2, nplay.card3, nplay.card4, nplay.card5, 
		nplay.card6, nplay.card7, nplay.card8, nplay.card9, nplay.card10, nplay.card11, nplay.card12);
	int eastheartnumber = heart.howmanyofsuit(eplay.card1, eplay.card2, eplay.card3, eplay.card4, eplay.card5, 
		eplay.card6, eplay.card7, eplay.card8, eplay.card9, eplay.card10, eplay.card11, eplay.card12);
	int westdiamondnumber = diamond.howmanyofsuit(wplay.card1, wplay.card2, wplay.card3, wplay.card4, wplay.card5, 
		wplay.card6, wplay.card7, wplay.card8, wplay.card9, wplay.card10, wplay.card11, wplay.card12);
	int northdiamondnumber = diamond.howmanyofsuit(nplay.card1, nplay.card2, nplay.card3, nplay.card4, nplay.card5, 
		nplay.card6, nplay.card7, nplay.card8, nplay.card9, nplay.card10, nplay.card11, nplay.card12);
	int eastdiamondnumber = diamond.howmanyofsuit(eplay.card1, eplay.card2, eplay.card3, eplay.card4, eplay.card5, 
		eplay.card6, eplay.card7, eplay.card8, eplay.card9, eplay.card10, eplay.card11, eplay.card12);
	int westspadenumber = spade.howmanyofsuit(wplay.card1, wplay.card2, wplay.card3, wplay.card4, wplay.card5, 	
		wplay.card6, wplay.card7, wplay.card8, wplay.card9, wplay.card10, wplay.card11, wplay.card12);
	int northspadenumber = spade.howmanyofsuit(nplay.card1, nplay.card2, nplay.card3, nplay.card4, nplay.card5, 
		nplay.card6, nplay.card7, nplay.card8, nplay.card9, nplay.card10, nplay.card11, nplay.card12);
	int eastspadenumber = spade.howmanyofsuit(eplay.card1, eplay.card2, eplay.card3, eplay.card4, eplay.card5, 
		eplay.card6, eplay.card7, eplay.card8, eplay.card9, eplay.card10, eplay.card11, eplay.card12);
	int westclubnumber = club.howmanyofsuit(wplay.card1, wplay.card2, wplay.card3, wplay.card4, wplay.card5, wplay.card6, 
		wplay.card7, wplay.card8, wplay.card9, wplay.card10, wplay.card11, wplay.card12);
	int northclubnumber = club.howmanyofsuit(nplay.card1, nplay.card2, nplay.card3, nplay.card4, nplay.card5, 
		nplay.card6, nplay.card7, nplay.card8, nplay.card9, nplay.card10, nplay.card11, nplay.card12);
	int eastclubnumber = club.howmanyofsuit(eplay.card1, eplay.card2, eplay.card3, eplay.card4, eplay.card5, 
		eplay.card6, eplay.card7, eplay.card8, eplay.card9, eplay.card10, eplay.card11, eplay.card12);
		
	string westsuit;  // Holds the best suit for the players  // & playersuits(), bid()
	string northsuit; // & playersuits(), bid()
	string eastsuit;  // & playersuits(), bid()
	
	 //located in cards.cpp -- Decides the best suit
	playersuits(&westsuit, &northsuit, &eastsuit, westheartnumber,northheartnumber,eastheartnumber, westdiamondnumber,
		northdiamondnumber, eastdiamondnumber,westspadenumber,northspadenumber,eastspadenumber, westclubnumber,
		northclubnumber,eastclubnumber);

	play.getorder();

	bool continuetheforloop = true; // Used below to keep the loop going // & Used in bid, if statement
	while(continuetheforloop == true) // Bidding Loop
{	 
	bid(westsuit, northsuit, eastsuit,&newcounter,&bidding_times, &continuetheforloop, &ongoin_bid, westpot , northpot, 			eastpot ,&playerpass, &westpass,&northpass,&eastpass,&westwin, &northwin, &eastwin, &playerwin, 
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


void playersuits(string * westsuit, string * northsuit, string * eastsuit, int wh, int nh, int eh, int wd, int nd, int ed, 
				 int ws,int ns, int es, int wc,int nc, int ec) /// This is confusing: TODO: Clean this so it makes sense/ check if it even works
{
	//Explain the letters and if statements
	//.  Here is the deal.  This needs a better AI to work efficiently.

	//wh : westheartnumber 	    //nh : northheartnumber     //eh : eastheartnumber
	//wd : westdiamondnumber    //nd : northdiamondnumber   //ed : eastdiamondnumber
	//ws : westspadenumber      //ns : northspadenumber     //es : eastspadenumber
	//wc : westclubnumber	    //nc : northclubnumber      //ec : eastclubnumber
	
	if (wh > wd && wh > ws && wh > wc)
	{	*westsuit = "Hearts";	}

	if (wd > wh && wd > ws && wd > wc)
	{*westsuit = "Diamonds";}

	if (ws > wd && ws > wh && ws > wc)
	{	*westsuit = "Spades";}

	if (wc > wd && wc > ws && wc > wh)
	{	*westsuit = "Clubs";}

	if (*westsuit != "Hearts" && *westsuit != "Diamonds" && *westsuit != "Spades" && *westsuit != "Clubs")
	{
		//cout << "There was an error with Westsuit! in cards.cpp -- playersuits()" << endl;
		*westsuit = "Clubs";
	}

	if (nh > nd && nh >ns && nh > nc)
	{	*northsuit = "Hearts";}

	if (nd > nh && nd > ns && nd > nc)
	{	*northsuit = "Diamonds";}

	if (ns > nd && ns > nh && ns > nc)
	{	*northsuit = "Spades";}

	if (nc > nd && nc > ns && nc > nh)
	{	*northsuit = "Clubs"; }

	if (*northsuit != "Hearts" && *northsuit != "Diamonds" && *northsuit != "Spades" && *northsuit != "Clubs")
	{
		//cout << "There was an error with Northsuit! in cards.cpp -- playersuits()" << endl;
		*northsuit = "Clubs";
	}

	if (eh > ed && eh > es && eh > ec)
	{	*eastsuit = "Hearts";}

	if (ed > eh && ed > es && ed > ec)
	{	*eastsuit = "Diamonds";}

	if (es > ed && es > eh && es > ec)
	{	*eastsuit = "Spades";}

	if (ec > ed && ec >es && ec > eh)
	{	*eastsuit = "Clubs"; }

	if (*eastsuit != "Hearts" && *eastsuit != "Diamonds" && *eastsuit != "Spades" && *eastsuit != "Clubs")
	{
		//cout << "There was an error with Eastsuit! in cards.cpp -- playersuits()" << endl;
		*eastsuit = "Clubs";
	}
}
