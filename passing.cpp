/// Problems here: (Brace yourself)
	///   1. passing has two different functions without similar functionality -- (nice try with the polymorphism)
	///   2. Impossible to read and sloppy
	///   3. Wayy too long for a normal person to consider reading it. 

#include "headers.h"

// & This file has over 526 lines and is unreadable!! It needs to be simplified!

void playerspassing(string suitname, player play, int & a, int & b, int & c, int & d, bool firsttime, string & c1, 
			string & c2, string & c3, string & c4);
	//playerspassing  --  located later in this .cpp

string get_passed_card_name(player north, int passed1);

bool check1to16(int *, int , int, int, bool); 
	// This makes sure the card is real(1to16), and isn't the same as another card.

void savespace(string suit, int * x, player play, int & a, int & b, int & c, int & d, bool firsttime, string & c1,string & c2, string & c3, string & c4);

void passing(int x, int card, string suitname, int & first, int  & second, int & third, int  & fourth, bool firsttime, string & c1, string & c2, string & c3, string & c4);

void passingwork(int * x, int card, int & first, int  & second, int  & third, int  & fourth, bool * happened);

string whichcardpassed(player & play, int card, int & returnval, string order1, string order2, string order3, string order4, string order5, string order6, string order7,  
string order8,string order9, string order10,string order11,string order12, string &  c1, string & c2, string &  c3, string & c4, int pass);

void passing(string winner, string & c1, string & c2, string & c3, string & c4, int & passed1, int & passed2,int & passed3,int & passed4, int & pass1, int & pass2, int & pass3,
 int & pass4, player & nc, player & wc, player & ec, player & pc, string suitname , bool & firsttime )
{
	// c1 - c4 are the cards chosen to be passed.
	
	if ((winner == "Player" && firsttime == true)||(winner == "North"&& firsttime == false)) // If Player wins
	{
		playerspassing(suitname, nc, passed1 , passed2, passed3, passed4, firsttime, c1, c2, c3, c4);
		
		c1 = get_passed_card_name(nc, passed1); 
		c2 = get_passed_card_name(nc, passed2);
		c3 = get_passed_card_name(nc, passed3);
		c4 = get_passed_card_name(nc, passed4);
	}
	if ((winner == "West"&& firsttime == true)||(winner == "East" && firsttime == false))
	{
		playerspassing(suitname, ec, passed1 , passed2, passed3, passed4, firsttime, c1, c2, c3, c4);
		
		line();
	}
	if ((winner == "North"&& firsttime == true)||(winner == "Player" && firsttime == false) )
	{
		cout << "Player passes next." << endl << endl;

		int card1a, card2a, card3a, card4a;
		
	for(;;)
	{
		cout << "The suit is: " << suitname << endl;
		cout << "Which cards do you want to pass?" << endl;

		int tempint1 = 1;  /// This is a faster more efficient way to print out the cards the player can choose from to the screen.
		string * pcpointer = &pc.order1;
		
		while (tempint1 < 13) /// How doesn't this cause a memory bug?
		{
			cout << " (" << tempint1 << ") " << *pcpointer << endl;
			pcpointer++;
			tempint1++;
		}

		if (firsttime == false)
		{
		cout << " (13) " << c1 << endl; /// This is a hack.. these cards are never in the players hand...
		cout << " (14) " << c2 << endl;
		cout << " (15) " << c3 << endl;
		cout << " (16) " << c4 << endl;
		}
		
		cout << "The first card: " ;
		cin >> card1a;
		check1to16(&card1a, 0, 0, 0, firsttime);
		cout << "The second card: " ;
		cin >> card2a;
		check1to16(&card2a, card1a, 0, 0, firsttime);
		cout << "The third card: " ;
		cin >> card3a;
		check1to16(&card3a, card1a, card2a, 0, firsttime);
		cout << "The fourth card: " ;
		cin >> card4a;
		check1to16(&card4a, card1a, card2a, card3a, firsttime);

		cout << "Are you sure about these cards?" << endl;
		cout << "(Y/N)" << endl;
		char input; 
		cin >> input;
		if (input == 'y' || input == 'Y') { break; }
		cout << endl;
	}

		c1 = whichcardpassed(pc,card1a, passed1,  pc.order1,pc.order2,pc.order3,pc.order4,pc.order5, pc.order6, 
			pc.order7, pc.order8, pc.order9, pc.order10,pc.order11, pc.order12, c1, c2, c3, c4, pass1);
		c2 = whichcardpassed(pc,card2a, passed2,  pc.order1,pc.order2,pc.order3,pc.order4,pc.order5, pc.order6, 
			pc.order7, pc.order8, pc.order9, pc.order10,pc.order11, pc.order12, c1, c2, c3, c4, pass2);
		c3 = whichcardpassed(pc,card3a, passed3,  pc.order1,pc.order2,pc.order3,pc.order4,pc.order5, pc.order6, 
			pc.order7, pc.order8, pc.order9, pc.order10,pc.order11, pc.order12, c1, c2, c3, c4 , pass3);
		c4 = whichcardpassed(pc,card4a, passed4, pc.order1,pc.order2,pc.order3,pc.order4,pc.order5, pc.order6, 
			pc.order7, pc.order8, pc.order9, pc.order10,pc.order11, pc.order12, c1, c2, c3, c4, pass4);
	}

	if ((winner == "East"&& firsttime == true)||(winner == "West" && firsttime == false))
	{
		cout << "West passes " <<  endl;
		cout << "The suit is: " << suitname << endl;
		playerspassing(suitname, wc, passed1 , passed2, passed3, passed4, firsttime, c1, c2, c3, c4);
	}                                                          
	cout << endl;


	firsttime = false; 
}

string whichcardpassed(player & p, int card, int & returnval, string order1, string order2, string order3, string order4, string order5, string order6, string order7,  
string order8,string order9, string order10,string order11,string order12, string &  c1, string & c2, string &  c3, string &  c4, int pass)
{
	    if (card == 1) { returnval =  p.ord1 ;  cout << "You passed : " << order1 << endl;  return order1; }

		if (card == 2) { returnval =  p.ord2;  cout << "You passed : " << order2 << endl;  return order2;}

		if (card == 3) { returnval =  p.ord3;  cout << "You passed : " << order3 << endl; return order3;}

		if (card == 4)  { returnval =  p.ord4; cout << "You passed : " << order4 << endl; return order4;}

		if (card == 5) { returnval =  p.ord5;cout << "You passed : " << order5 << endl; return order5;}

		if (card == 6 ){ returnval =  p.ord6;cout << "You passed : " << order6 << endl;return order6;}

		if (card == 7) { returnval =  p.ord7;cout << "You passed : " << order7 << endl;return order7;}

		if (card == 8) { returnval =  p.ord8;cout << "You passed : " << order8 << endl;return order8;}
 
		if (card == 9)  { returnval =  p.ord9;cout << "You passed : " << order9 << endl;return order9;}

		if (card == 10){ returnval =  p.ord10;cout << "You passed : " << order10 << endl; return order10;}

		if (card == 11){ returnval =  p.ord11;cout << "You passed : " << order11 << endl; return order11;}

		if (card == 12){ returnval =  p.ord12;cout << "You passed : " << order12 << endl; return order12;}

		if (card == 13){ returnval = pass; cout << "You passed : " << c1 << endl; return c1;}

		if (card == 14){ returnval = pass; cout << "You passed : " << c2 << endl; return c2;}

		if (card == 15){ returnval = pass; cout << "You passed : " << c3 << endl; return c3;}

		if (card == 16){ returnval = pass; cout << "You passed : " << c4 << endl; return c4;}

		return "Error";
}

bool check1to16(int * card, int card1, int card2, int card3, bool firsttime)
{
	if ((*card > 12 || *card <1 || *card == card1 || *card == card2 || *card == card3)&&firsttime == true)
	{
		cout << "Please try again.";
		cin >> *card;
		check1to16(card, card1, card2, card3, firsttime);
		return false;
	}
	if ((*card > 16 || *card <1 || *card == card1 || *card == card2 || *card == card3)&&firsttime == false)
	{
		cout << "Please try again.";
		cin >> *card;
		check1to16(card, card1, card2, card3, firsttime);
		return false;
	}
	else 
		return true;
}

void playerspassing(string suitname, player play, int & passed1, int & passed2, int & passed3, int & passed4, bool firsttime, string & c1, 
			string & c2, string & c3, string & c4)
{
	int x =0, y = 0;
	string suit;
	
	if (suitname == "Hearts")
	{
		savespace(suitname, &x, play,
		passed1,passed2,passed3,passed4, firsttime, c1, c2, c3, c4);
	}

	if (suitname == "Diamonds")
	{

		savespace(suitname, &x,  play,
			passed1,passed2,passed3,passed4, firsttime, c1, c2, c3, c4);
	}

	if (suitname == "Spades")
	{
		savespace(suitname, &x,  play,
			passed1,passed2,passed3,passed4, firsttime, c1, c2, c3, c4);
	}

	if (suitname == "Clubs")
	{
		savespace(suitname, &x,  play,
			passed1,passed2,passed3,passed4, firsttime, c1, c2, c3, c4);
	}
}

void savespace(string suit, int * x, player play, int & a, int & b, int & c, int & d, bool firsttime, string & c1, string & c2, string & c3, string & c4)
{
		passing(*x, play.card1, suit, a, b, c, d, firsttime, c1, c2, c3, c4 );
		passing(*x, play.card2, suit, a, b, c, d , firsttime, c1, c2, c3, c4);
		passing(*x, play.card3, suit, a, b, c, d , firsttime, c1, c2, c3, c4);
		if (*x < 4) {passing(*x, play.card4, suit, a, b, c, d , firsttime, c1, c2, c3, c4 );}
		if (*x < 4) {passing(*x, play.card5, suit, a, b, c, d , firsttime, c1, c2, c3, c4);}
		if (*x < 4) {passing(*x, play.card6, suit, a, b, c, d , firsttime, c1, c2, c3, c4);}
		if (*x < 4) {passing(*x, play.card7, suit, a, b, c, d , firsttime, c1, c2, c3, c4 );}
		if (*x < 4) {passing(*x, play.card8, suit, a, b, c, d , firsttime, c1, c2, c3, c4);}
		if (*x < 4) {passing(*x, play.card9, suit, a, b, c, d , firsttime, c1, c2, c3, c4);}
		if (*x < 4) {passing(*x, play.card10, suit, a, b, c, d , firsttime, c1, c2, c3, c4);}
		if (*x < 4) {passing(*x, play.card11, suit, a, b, c, d , firsttime, c1, c2, c3, c4);}
		if (*x < 4) {passing(*x, play.card12, suit, a, b, c, d , firsttime, c1, c2, c3, c4);}
}

string get_passed_card_name(player north, int passed1)
{
		 if (passed1 == north.card1)   { return north.name1;}
		 if (passed1 == north.card2)   { return north.name2;}
		 if (passed1 == north.card3)   { return north.name3;}
		 if (passed1 == north.card4)   { return north.name4;}
		 if (passed1 == north.card5)   { return north.name5;}
		 if (passed1 == north.card6)   { return north.name6;}
		 if (passed1 == north.card7)   { return north.name7;}
		 if (passed1 == north.card8)   { return north.name8;}
		 if (passed1 == north.card9)   { return north.name9;}
		 if (passed1 == north.card10)  { return north.name10;}
		 if (passed1 == north.card11)  { return north.name11;}
		 if (passed1 == north.card12)  { return north.name12;}
		 else 
		 {
			 // Error catching goes here...
		 }
}

void passing(int x, int card, string suitname, int & first, int  & second, int & third, int  & fourth, bool firsttime, string & c1, string & c2, string & c3, string & c4)

{	
	if (suitname == "Hearts")
	{
		bool happened = false;
		
		if (firsttime == true)
		{
		if (card==1||card ==2||card ==3||card ==4||card==5||card==6||card == 7|| card == 8||card == 9||card==10)
			{
				passingwork(&x, card, first, second, third, fourth, &happened);
			}
		
		if (card == 13||card == 14||card == 25 || card == 26 || card== 37 || card == 38 ) 
			{
				passingwork(&x, card, first, second, third, fourth, &happened);
			}
		
		if (card == 17 || card == 18 || card == 19 || card == 20 || card == 29 || card == 30 || card == 31 || card == 
			32||card == 41 || card ==42  || card == 43 || card == 44)
			{
				passingwork(&x, card, first, second, third, fourth, &happened);
			}
		}

		if (firsttime == false)
		{
			if (card == 11 || card == 12 || card == 23 || card == 24 || card == 35 || card == 36 || card == 47 || 
				card == 48)
			{
				passingwork(&x, card , first, second, third, fourth, &happened);
			}
			if (card == 17 || card == 18 || card == 19 || card ==20 || card == 29 || card == 30 || card == 31 || 	
				card == 32|| card == 41 || card == 42 || card == 43 || card == 44)
			{
				passingwork(&x, card , first, second , third, fourth, &happened);
			}
		}
}

	if (suitname == "Diamonds")
{
	bool happened = false;

	if (firsttime == true)
	{
	
	if (card==13||card ==14||card ==15||card ==16||card==17||card==18||card == 19|| card == 20||card == 21||card==22)
		{
			passingwork(&x, card, first, second, third, fourth, &happened);
		}
	if (card == 1|| card ==2 || card == 25 || card == 26 || card== 37 || card == 38 )
		{
			passingwork(&x, card, first, second, third, fourth, &happened);
		}

	if (card == 5 || card == 6 || card == 7 || card == 8 || card == 29 || card == 30 || card == 31 || card == 32||
			card == 41 || card ==42  || card == 43 || card == 44)
		{
			passingwork(&x, card, first, second, third, fourth, &happened);
		}
	}

	if (firsttime == false)
	{
			if (card == 11 || card == 12 || card == 23 || card == 24 || card == 35 || card == 36 || card == 47 || 
				card == 48)
			{
				passingwork(&x, card , first, second, third, fourth, &happened);
			}
			if (card == 4 || card == 5 || card == 6 || card ==7 || card == 29 || card == 30 || card == 31 || card 
				== 32|| card == 41 || card == 42 || card == 43 || card == 44)
			{
				passingwork(&x, card , first, second , third, fourth, &happened);
			}
	}
}

	if (suitname == "Spades")
	{
	bool happened = false;

	if (firsttime == true)

	{
	if (card==25||card ==26||card ==27||card ==28||card==29||card==30||card == 31|| card == 32||card == 33||card==34)
		{
			passingwork(&x, card, first, second, third, fourth, &happened);
		}

	if (card == 1|| card ==2 || card == 13 || card == 14 || card== 37 || card == 38 )
		{
			passingwork(&x, card, first, second, third, fourth, &happened);
		}

	if (card == 5 || card == 6 || card == 7 || card == 8 || card == 17 || card == 18 || card == 19 || card == 20||
			card == 41 || card ==42  || card == 43 || card == 44)
		{
			passingwork(&x, card, first, second, third, fourth, &happened);
		}
	}

	if (firsttime == false)
	{
			if (card == 11 || card == 12 || card == 23 || card == 24 || card == 35 || card == 36 || card == 47 || 
				card == 48)
			{
				passingwork(&x, card , first, second, third, fourth, &happened);
			}
			if (card == 4 || card == 5 || card == 6 || card ==7 || card == 17 || card == 18 || card == 19 || card 
				== 20|| card == 41 || card == 42 || card == 43 || card == 44)
			{
				passingwork(&x, card , first, second , third, fourth, &happened);
			}
	}
}

	if (suitname == "Clubs")
	{
	bool happened = false;
	if (firsttime == true)
	{
	if (card==37||card ==38||card ==39||card ==40||card==41||card==42||card == 43|| card == 44||card == 45||card==46)
		{
			passingwork(&x, card, first, second, third, fourth, &happened);
		}
	
	if (card == 1|| card ==2 || card == 13 || card == 14 || card== 25 || card == 26 ) // Aces
		{
			passingwork(&x, card, first, second, third, fourth, &happened);
		}

	if (card == 5 || card == 6 || card == 7 || card == 8 || card == 17 || card == 18 || card == 19 || card == 20||
			card == 29 || card ==30  || card == 31 || card == 32)
		{
			passingwork(&x, card, first, second, third, fourth, &happened);
		}
	}

	if (firsttime == false)
		{
			if (card == 11 || card == 12 || card == 23 || card == 24 || card == 35 || card == 36 || card == 47 || 
				card == 48)
			{
				passingwork(&x, card , first, second, third, fourth, &happened);
			}
			if (card == 4 || card == 5 || card == 6 || card ==7 || card == 17 || card == 18 || card == 19 || card 

				== 20|| card == 29 || card == 30 || card == 31 || card == 32 )
			{
				passingwork(&x, card , first, second , third, fourth, &happened);
			}
		}
	}
}

void passingwork(int * x, int card, int & first, int & second, int & third, int &fourth, bool * happened)
{
		if (first < 1&&*happened == false){first = card; (*x)++; *happened = true; } 
		
		if (first >0 && second <1 && *happened == false){second = card; (*x)++; *happened = true; } 
		
		if (first >0 && second>0 && third <1&& *happened == false){third = card; (*x)++; *happened = true; } 
		
		if (first >0 && second>0 && third >0&&fourth <1&& *happened == false){fourth = card; (*x)++; *happened = true;} 
}

void test1(player *, player *, player *, player *, int *, int *, int *, int *, string);
int work(int , player *);

void cardschangehands(string winner, int * card1, int * card2, int * card3, int * card4, int *card5, int * card6, int * card7
	, int * card8,  player & play, player & wplay, player & nplay, player & eplay) // This comes from hand.cpp
{
	int winnersfirst, winnerssecond, winnersthird, winnersfourth ; /// These will be equal to the players passes
	int whichcard; // Should only be 1 to 12
	
	winnersfirst = *card1; /// This makes no sense.
	*card1 = *card5;
	winnerssecond = *card2;
	*card2 = *card6;
	winnersthird = *card3;
	*card3 = *card7;
	winnersfourth = *card4;
	*card4 = *card8;

	int go(player &, int, int);

	if (winner == "Player" )
	{
		whichcard  = go(play, *card1, winnersfirst);

		whichcard  = go(play, *card2, winnerssecond);

		whichcard  = go(play, *card3, winnersthird);

		whichcard  = go(play, *card4, winnersfourth);

		whichcard  = go(nplay, winnersfirst, *card1); /// What the fuck! Why do the arguments change?

		whichcard  = go(nplay, winnerssecond, *card2);

		whichcard  = go(nplay,  winnersthird, *card3);

		whichcard  = go(nplay, winnersfourth, *card4 );

		play.get_names();
		nplay.get_names();
	}
	if (winner == "West")
	{
		whichcard  = go(wplay, *card1, winnersfirst);

		whichcard  = go(wplay, *card2, winnerssecond);

		whichcard  = go(wplay, *card3, winnersthird);

		whichcard  = go(wplay, *card4, winnersfourth);

		whichcard  = go(eplay, winnersfirst, *card1);
		cout << "Whichcard: " << whichcard << endl;

		whichcard  = go(eplay, winnerssecond, *card2);
		cout << "Whichcard: " << whichcard << endl;

		whichcard  = go(eplay,  winnersthird, *card3);
		cout << "Whichcard: " << whichcard << endl;

		whichcard  = go(eplay, winnersfourth, *card4 );
		cout << "Whichcard: " << whichcard << endl;

		wplay.get_names();
		eplay.get_names();

	}
	if (winner == "North")
	{
		whichcard  = go(nplay, *card1, winnersfirst);

		whichcard  = go(nplay, *card2, winnerssecond);

		whichcard  = go(nplay, *card3, winnersthird);

		whichcard  = go(nplay, *card4, winnersfourth);

		whichcard  = go(play, winnersfirst, *card1);
		cout << "Whichcard: " << whichcard << endl;

		whichcard  = go(play, winnerssecond, *card2);
		cout << "Whichcard: " << whichcard << endl;

		whichcard  = go(play,  winnersthird, *card3);
		cout << "Whichcard: " << whichcard << endl;

		whichcard  = go(play, winnersfourth, *card4 );
		cout << "Whichcard: " << whichcard << endl;

		nplay.get_names();
		play.get_names();

	}
	if (winner == "East")
	{
		whichcard  = go(eplay, *card1, winnersfirst);

		whichcard  = go(eplay, *card2, winnerssecond);

		whichcard  = go(eplay, *card3, winnersthird);

		whichcard  = go(eplay, *card4, winnersfourth);

		whichcard  = go(wplay, winnersfirst, *card1);
		cout << "Whichcard: " << whichcard << endl;

		whichcard  = go(wplay, winnerssecond, *card2);
		cout << "Whichcard: " << whichcard << endl;

		whichcard  = go(wplay,  winnersthird, *card3);
		cout << "Whichcard: " << whichcard << endl;

		whichcard  = go(wplay, winnersfourth, *card4 );
		cout << "Whichcard: " << whichcard << endl;

		eplay.get_names();
		wplay.get_names();

	}

}

int go(player & play, int card, int passed)
{
	int * playercard = &play.card1;
	int x = 1;
	while (x < 13)
	{
	if (*playercard == card)
	{
		*playercard = passed;
		return x;
		
	}
		x++;
		playercard++;
	}
	
	return 0;
}
