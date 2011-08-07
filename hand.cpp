#include "headers.h"
#include "scoreclass.h"
#include "hand.h"

void initarray(int howbig, int * array) // & 
{
int initialize = 0;
while (initialize < howbig)
	{
		*array = 0; 
		initialize++;
		array++;
	}
}

void deal(string * nameptr, int howmany, scoreclass & scr) //&Why is The function called deal - file called hand
{
	scoring score;   ///Class Scoring definition
	//& This is a good example of ugly code writing -- There is a class called scoring and a scoreclass.....
	//& I however do not know how to fix this at the moment

	int suitint = 0; //Defined later by the player who bid the highest //& Used Two Times
	int bidding_times = 3; //Used to say how many times the players have bid -- Used to return the bidder //& Used Once
		//This needs to be kept either throughout the hand or use the howmany to figure it out!!
	cout << "! # " << howmany << " !" << endl; 
	cout << "-------" << endl;
		// Displays the number of times the program has run //&Passed in Used Twice in deal
	string dealerstring;   //String to return who is dealing //& Used in finddealer two times.
	finddealer(&howmany, &dealerstring);  // Interger function that helps tell us who is dealing -- Found later in hand.cpp

	//cout << "Dealerstring: " << dealerstring << endl;
	p();

	int counter = 1;
        player play = recieve_cards(counter); // & This deals the player their cards.

	player wplay = recieve_cards(counter); // & This deals the westplayer their cards.
	
	play.getorder();
	cout << endl << "You recieved: " << endl; // goes before telling the players all the cards they recieved
	//cout << "A " ;
	play.cardnames();

	///These are the north computer players cards
	player nplay = recieve_cards(counter); // & This deals the northplayer their cards

	///These are the east computer players cards
	player eplay = recieve_cards(counter);  // & This deals the eastplayer their cards
	
	int ongoin_bid = 1; // The bid that will be passed around alot to help the players bid

	// The right bid for the computer is passed into the bid function, not all the cards/ junk
	int westpot = 0,northpot = 0,eastpot = 0,westscore = 0, northscore = 0,eastscore = 0, playerpot = 0, playerscore = 0;

	bool  westwin = false, northwin = false, eastwin = false, playerwin = false; 
		//The winning variables which are used by passing|scoring|playhand ..etc
	
	int card_passed[8];
	initarray(8, &card_passed[0]); // Located before deal(), it has

	string ppassed1, ppassed2, ppassed3, ppassed4; //Names of the cards passed later
	///The first call which tells the computer players their bids
	//The function that will give the players their score and allows the computerized players bid 
	scoring_func(&playerpot, &westpot, &northpot, &eastpot, &westscore, &northscore, &eastscore, &playerscore, &play, &wplay, &nplay, &eplay);

	bool westpass = false, northpass = false, eastpass = false, playerpass = false; // Booleans to see if the player passed
	int newcounter = 1, finalbid = 0; /// newcounter -- Used in bid() and bid.cpp functions, finalbid -- holds finalbid
	string winnername, suitname; // Makes the string that will hold the winner's name | suitname

	//hearts heart;
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

int finddealer(int * whoptr, string * dealerstring)
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
			*dealerstring = "Player";
			break;
		}
	case 2:
		{
			cout << "West is dealing" << endl;
			*dealerstring = "West";
			break;
		}
	case 3: 
		{
			cout << "North is dealing" << endl;
			*dealerstring = "North" ;
			break;
		}
	case 4:
		{bool continuetheforloop = true; // Used below to keep the loop going // & Used in bid, if statement
			cout << "East is dealing" << endl;
			*dealerstring = "East";
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
				 int ws,int ns, int es, int wc,int nc, int ec)
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
