#include "headers.h"

// & This file has over 526 lines and is unreadable!! It needs to be simplified!

void playerspassing(string, int, int, int, int, int, int, int, int, int, int, int, int, int & , int &, int &, int &, bool, 
	string *, string *, string *, string*);
	//playerspassing  --  located later in this .cpp

void savemorespace(player *, int *, string *);

bool check1to16(int *, int , int, int, bool); 
	// This makes sure the card is real(1to16), and isn't the same as another card.

void savespace(string suit, int * x, int card1, int card2, int card3, int card4, int card5, int card6, int card7, int card8, 
	int card9, int card10, int card11, int card12, int & a, int & b, int & c, int & d, bool firsttime, string *,string *, 
	string *, string *);

void passing(int *, int, string, int &, int &, int &, int &, bool, string * , string *, string *, string *);

void passingwork(int * x, int card, int & first, int  & second, int  & third, int  & fourth, bool * happened, string *, 
	string *, string *, string *);

string whichcardpassed(player &,int, int *, string,string,string,string,string,string,string,string,string,string,string,
	string, string, string, string, string, int);

void passing(string winner, string * c1, string * c2, string * c3, string * c4, int* passed1, int* passed2,int* passed3,int* passed4, int* pass1, int* pass2, int* pass3,
 int* pass4, player & nc, player & wc, player & ec, player & pc, string suitname , bool * firsttime )
{
	// c1 - c4 are the cards chosen to be passed.
	
	if ((winner == "Player"&& *firsttime == true)||(winner == "North"&& *firsttime == false)) // If Player wins
	{
		playerspassing(suitname, nc.card1,nc.card2,nc.card3,nc.card4,nc.card5,nc.card6,nc.card7,nc.card8,nc.card9,
			nc.card10,nc.card11,nc.card12, *passed1 , *passed2, *passed3, *passed4, *firsttime, c1, c2, c3, c4);
		
		 savemorespace(&nc, passed1, c1);
		 savemorespace(&nc, passed2, c2);
		 savemorespace(&nc, passed3, c3);
		 savemorespace(&nc, passed4, c4);
	}
	if ((winner == "West"&& *firsttime == true)||(winner == "East" && *firsttime == false))
	{
		playerspassing(suitname, ec.card1,ec.card2,ec.card3,ec.card4,ec.card5,ec.card6,ec.card7,ec.card8,ec.card9,
		ec.card10, ec.card11,ec.card12, *passed1 , *passed2, *passed3, *passed4, *firsttime, c1, c2, c3, c4);
		
		line();
	}
	if ((winner == "North"&& *firsttime == true)||(winner == "Player" && *firsttime == false) )
	{
		cout << "Player passes next." << endl << endl;

		int card1a, card2a, card3a, card4a;
		
	for(;;)
	{
		cout << "The suit is: " << suitname << endl;
		cout << "Which cards do you want to pass?" << endl;

		int tempint1 = 1;  /// This is a faster more efficient way to print out the cards the player can choose from to the screen.
		string * pcpointer = &pc.order1;
		while (tempint1 < 13)
		{
			cout << " (" << tempint1 << ") " << *pcpointer << endl;
			pcpointer++;
			tempint1++;
		}

		if (*firsttime == false)
		{
		cout << " (13) " << *c1 << endl;
		cout << " (14) " << *c2 << endl;
		cout << " (15) " << *c3 << endl;
		cout << " (16) " << *c4 << endl;
		}
		
		cout << "The first card: " ;
		cin >> card1a;
		check1to16(&card1a, 0, 0, 0, *firsttime);
		cout << "The second card: " ;
		cin >> card2a;
		check1to16(&card2a, card1a, 0, 0, *firsttime);
		cout << "The third card: " ;
		cin >> card3a;
		check1to16(&card3a, card1a, card2a, 0, *firsttime);
		cout << "The fourth card: " ;
		cin >> card4a;
		check1to16(&card4a, card1a, card2a, card3a, *firsttime);

		cout << "Are you sure about these cards?" << endl;
		cout << "(Y/N)" << endl;
		char input; 
		cin >> input;
		if (input == 'y' || input == 'Y') { break; }
		cout << endl;
	}

		*c1 = whichcardpassed(pc,card1a, passed1,  pc.order1,pc.order2,pc.order3,pc.order4,pc.order5, pc.order6, 
			pc.order7, pc.order8, pc.order9, pc.order10,pc.order11, pc.order12, *c1, *c2, *c3, *c4, *pass1);
		*c2 = whichcardpassed(pc,card2a, passed2,  pc.order1,pc.order2,pc.order3,pc.order4,pc.order5, pc.order6, 
			pc.order7, pc.order8, pc.order9, pc.order10,pc.order11, pc.order12, *c1, *c2, *c3, *c4, *pass2);
		*c3 = whichcardpassed(pc,card3a, passed3,  pc.order1,pc.order2,pc.order3,pc.order4,pc.order5, pc.order6, 
			pc.order7, pc.order8, pc.order9, pc.order10,pc.order11, pc.order12, *c1, *c2, *c3, *c4 , *pass3);
		*c4 = whichcardpassed(pc,card4a, passed4, pc.order1,pc.order2,pc.order3,pc.order4,pc.order5, pc.order6, 
			pc.order7, pc.order8, pc.order9, pc.order10,pc.order11, pc.order12, *c1, *c2, *c3, *c4, *pass4);
	}

	if ((winner == "East"&& *firsttime == true)||(winner == "West" && *firsttime == false))
	{
		cout << "West passes " <<  endl;
		cout << "The suit is: " << suitname << endl;
		playerspassing(suitname, wc.card1,wc.card2,wc.card3,wc.card4,wc.card5,wc.card6,wc.card7,wc.card8,wc.card9,wc.card10,
			wc.card11,wc.card12, *passed1 , *passed2, *passed3, *passed4, *firsttime, c1, c2, c3, c4);
	}                              //a           b         c         d
	cout << endl;

void savemorespace(player *, int *, string *);
	*firsttime = false; 
}

string whichcardpassed(player & play, int card, int * returnval, string order1, string order2, string order3, string order4, string order5, string order6, string order7,  string order8,string order9, string order10,string order11,string order12, string  c1, string c2, string  c3, string  c4, int pass)
{
	player p = (play); 
	    if (card == 1) { *returnval =  p.ord1 ;  cout << "You passed : " << order1 << endl;  return order1; }

		if (card == 2) { *returnval =  p.ord2;  cout << "You passed : " << order2 << endl;  return order2;}

		if (card == 3) { *returnval =  p.ord3;  cout << "You passed : " << order3 << endl; return order3;}

		if (card == 4)  { *returnval =  p.ord4; cout << "You passed : " << order4 << endl; return order4;}

		if (card == 5) { *returnval =  p.ord5;cout << "You passed : " << order5 << endl; return order5;}

		if (card == 6 ){ *returnval =  p.ord6;cout << "You passed : " << order6 << endl;return order6;}

		if (card == 7) { *returnval =  p.ord7;cout << "You passed : " << order7 << endl;return order7;}

		if (card == 8) { *returnval =  p.ord8;cout << "You passed : " << order8 << endl;return order8;}
 
		if (card == 9)  { *returnval =  p.ord9;cout << "You passed : " << order9 << endl;return order9;}

		if (card == 10){ *returnval =  p.ord10;cout << "You passed : " << order10 << endl; return order10;}

		if (card == 11){ *returnval =  p.ord11;cout << "You passed : " << order11 << endl; return order11;}

		if (card == 12){ *returnval =  p.ord12;cout << "You passed : " << order12 << endl; return order12;}

		if (card == 13){ *returnval = pass; cout << "You passed : " << c1 << endl; return c1;}

		if (card == 14){ *returnval = pass; cout << "You passed : " << c2 << endl; return c2;}

		if (card == 15){ *returnval = pass; cout << "You passed : " << c3 << endl; return c3;}

		if (card == 16){ *returnval = pass; cout << "You passed : " << c4 << endl; return c4;}

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

void playerspassing(string suitname, int card1, int card2, int card3, int card4, int card5, int card6, int card7, int card8, 
		int card9, int card10, int card11, int card12, int & a, int & b, int & c, int & d, bool firsttime, string * c1, 
			string * c2, string * c3, string * c4)
{
	int x =0, y = 0;
	string suit;
	
	if (suitname == "Hearts")
	{
		savespace(suitname, &x, card1, card2, card3, card4, card5, card6, card7, card8, card9, card10, card11, card12,
		a,b,c,d, firsttime, c1, c2, c3, c4);
	}

	if (suitname == "Diamonds")
	{
//void savemorespace(player *, int *, string *);
		savespace(suitname, &x, card1, card2, card3, card4, card5, card6, card7, card8, card9, card10, card11, card12,
			a,b,c,d, firsttime, c1, c2, c3, c4);
	}

	if (suitname == "Spades")
	{
		savespace(suitname, &x, card1, card2, card3, card4, card5, card6, card7, card8, card9, card10, card11, card12,
			a,b,c,d, firsttime, c1, c2, c3, c4);
	}

	if (suitname == "Clubs")
	{
		savespace(suitname, &x, card1, card2, card3, card4, card5, card6, card7, card8, card9, card10, card11, card12,
			a,b,c,d, firsttime, c1, c2, c3, c4);
	}
}

void savespace(string suit, int * x, int card1, int card2, int card3, int card4, int card5, int card6, int card7, int card8, 
int card9, int card10, int card11, int card12, int & a, int & b, int & c, int & d, bool firsttime, string * c1,string * c2, string * c3, string * c4)
{
		passing(x, card1, suit, a, b, c, d, firsttime, c1, c2, c3, c4 );
		passing(x, card2, suit, a, b, c, d , firsttime, c1, c2, c3, c4);
		passing(x, card3, suit, a, b, c, d , firsttime, c1, c2, c3, c4);
		if (*x < 4) {passing(x, card4, suit, a, b, c, d , firsttime, c1, c2, c3, c4 );}
		if (*x < 4) {passing(x, card5, suit, a, b, c, d , firsttime, c1, c2, c3, c4);}
		if (*x < 4) {passing(x, card6, suit, a, b, c, d , firsttime, c1, c2, c3, c4);}
		if (*x < 4) {passing(x, card7, suit, a, b, c, d , firsttime, c1, c2, c3, c4 );}
		if (*x < 4) {passing(x, card8, suit, a, b, c, d , firsttime, c1, c2, c3, c4);}
		if (*x < 4) {passing(x, card9, suit, a, b, c, d , firsttime, c1, c2, c3, c4);}
		if (*x < 4) {passing(x, card10, suit, a, b, c, d , firsttime, c1, c2, c3, c4);}
		if (*x < 4) {passing(x, card11, suit, a, b, c, d , firsttime, c1, c2, c3, c4);}
		if (*x < 4) {passing(x, card12, suit, a, b, c, d , firsttime, c1, c2, c3, c4);}
}

void savemorespace(player * north, int * passed1, string * c1)
{
		 if (*passed1 == (*north).card1)   { *c1 = (*north).name1;}
		 if (*passed1 == (*north).card2)   { *c1 = (*north).name2;}
		 if (*passed1 == (*north).card3)   { *c1 = (*north).name3;}
		 if (*passed1 == (*north).card4)   { *c1 = (*north).name4;}
		 if (*passed1 == (*north).card5)   { *c1 = (*north).name5;}
		 if (*passed1 == (*north).card6)   { *c1 = (*north).name6;}
		 if (*passed1 == (*north).card7)   { *c1 = (*north).name7;}
		 if (*passed1 == (*north).card8)   { *c1 = (*north).name8;}
		 if (*passed1 == (*north).card9)   { *c1 = (*north).name9;}
		 if (*passed1 == (*north).card10)  { *c1 = (*north).name10;}
		 if (*passed1 == (*north).card11)  { *c1 = (*north).name11;}
		 if (*passed1 == (*north).card12)  { *c1 = (*north).name12;}
}

void passing(int * x, int card, string suitname, int & first, int  & second, int & third, int  & fourth, bool firsttime, string * c1, string * c2, string * c3, string * c4)

{	
	if (suitname == "Hearts")
	{
		bool happened = false;
		suit heart("heart"); // & Is this even needed?
		
		if (firsttime == true)
		{
		if (card==1||card ==2||card ==3||card ==4||card==5||card==6||card == 7|| card == 8||card == 9||card==10)
			{
				passingwork(x, card, first, second, third, fourth, &happened, c1, c2, c3, c4);
			}
		
		if (card == 13||card == 14||card == 25 || card == 26 || card== 37 || card == 38 ) 
			{
				passingwork(x, card, first, second, third, fourth, &happened, c1, c2, c3, c4);
			}
		
		if (card == 17 || card == 18 || card == 19 || card == 20 || card == 29 || card == 30 || card == 31 || card == 
			32||card == 41 || card ==42  || card == 43 || card == 44)
			{
				passingwork(x, card, first, second, third, fourth, &happened, c1, c2, c3, c4);
			}
		}

		if (firsttime == false)
		{
			if (card == 11 || card == 12 || card == 23 || card == 24 || card == 35 || card == 36 || card == 47 || 
				card == 48)
			{
				passingwork(x, card , first, second, third, fourth, &happened, c1, c2, c3, c4);
			}
			if (card == 17 || card == 18 || card == 19 || card ==20 || card == 29 || card == 30 || card == 31 || 	
				card == 32|| card == 41 || card == 42 || card == 43 || card == 44)
			{
				passingwork(x, card , first, second , third, fourth, &happened, c1, c2, c3, c4);
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
			passingwork(x, card, first, second, third, fourth, &happened, c1, c2, c3, c4);
		}
	if (card == 1|| card ==2 || card == 25 || card == 26 || card== 37 || card == 38 )
		{
			passingwork(x, card, first, second, third, fourth, &happened, c1, c2, c3, c4);
		}

	if (card == 5 || card == 6 || card == 7 || card == 8 || card == 29 || card == 30 || card == 31 || card == 32||
			card == 41 || card ==42  || card == 43 || card == 44)
		{
			passingwork(x, card, first, second, third, fourth, &happened, c1, c2, c3, c4);
		}
	}

	if (firsttime == false)
	{
			if (card == 11 || card == 12 || card == 23 || card == 24 || card == 35 || card == 36 || card == 47 || 
				card == 48)
			{
				passingwork(x, card , first, second, third, fourth, &happened, c1, c2, c3, c4);
			}
			if (card == 4 || card == 5 || card == 6 || card ==7 || card == 29 || card == 30 || card == 31 || card 
				== 32|| card == 41 || card == 42 || card == 43 || card == 44)
			{
				passingwork(x, card , first, second , third, fourth, &happened, c1, c2, c3, c4);
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
			passingwork(x, card, first, second, third, fourth, &happened, c1, c2, c3, c4);
		}

	if (card == 1|| card ==2 || card == 13 || card == 14 || card== 37 || card == 38 )
		{
			passingwork(x, card, first, second, third, fourth, &happened, c1, c2, c3, c4);
		}

	if (card == 5 || card == 6 || card == 7 || card == 8 || card == 17 || card == 18 || card == 19 || card == 20||
			card == 41 || card ==42  || card == 43 || card == 44)
		{
			passingwork(x, card, first, second, third, fourth, &happened, c1, c2, c3, c4);
		}
	}

	if (firsttime == false)
	{
			if (card == 11 || card == 12 || card == 23 || card == 24 || card == 35 || card == 36 || card == 47 || 
				card == 48)
			{
				passingwork(x, card , first, second, third, fourth, &happened, c1, c2, c3, c4);
			}
			if (card == 4 || card == 5 || card == 6 || card ==7 || card == 17 || card == 18 || card == 19 || card 
				== 20|| card == 41 || card == 42 || card == 43 || card == 44)
			{
				passingwork(x, card , first, second , third, fourth, &happened, c1, c2, c3, c4);
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
			passingwork(x, card, first, second, third, fourth, &happened, c1, c2, c3, c4);
		}
	
	if (card == 1|| card ==2 || card == 13 || card == 14 || card== 25 || card == 26 ) // Aces
		{
			passingwork(x, card, first, second, third, fourth, &happened, c1, c2, c3, c4);
		}

	if (card == 5 || card == 6 || card == 7 || card == 8 || card == 17 || card == 18 || card == 19 || card == 20||
			card == 29 || card ==30  || card == 31 || card == 32)
		{
			passingwork(x, card, first, second, third, fourth, &happened, c1, c2, c3, c4);
		}
	}

	if (firsttime == false)
		{
			if (card == 11 || card == 12 || card == 23 || card == 24 || card == 35 || card == 36 || card == 47 || 
				card == 48)
			{
				passingwork(x, card , first, second, third, fourth, &happened, c1, c2, c3, c4);
			}
			if (card == 4 || card == 5 || card == 6 || card ==7 || card == 17 || card == 18 || card == 19 || card 

				== 20|| card == 29 || card == 30 || card == 31 || card == 32 )
			{
				passingwork(x, card , first, second , third, fourth, &happened, c1, c2, c3, c4);
			}
		}
	}
}

void passingwork(int * x, int card, int & first, int & second, int & third, int &fourth, bool * happened, string * c1, string * 
	c2,string * c3, string * c4)
{
		if (first < 1&&*happened == false){first = card; (*x)++; *happened = true; } 
		
		if (first >0 && second <1 && *happened == false){second = card; (*x)++; *happened = true; } 
		
		if (first >0 && second>0 && third <1&& *happened == false){third = card; (*x)++; *happened = true; } 
		
		if (first >0 && second>0 && third >0&&fourth <1&& *happened == false){fourth = card; (*x)++; *happened = true;} 
}

void test1(player *, player *, player *, player *, int *, int *, int *, int *, string);
int work(int , player *);

void cardschangehands(string winner, int * card1, int * card2, int * card3, int * card4, int *card5, int * card6, int * card7
		, int * card8,  player * playa, player * wplaya, player * nplaya, player * eplaya) // This comes from hand.cpp
{
	int winnersfirst, winnerssecond, winnersthird, winnersfourth ; /// These will be equal to the players passes
	int whichcard; // Should only be 1 to 12
	
	player & play = (*playa); 
	player & wplay = (*wplaya);
	player & nplay = (*nplaya);
	player & eplay = (*eplaya);
	
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

		whichcard  = go(nplay, winnersfirst, *card1); /// What the fuck, why do the arguments change.

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
