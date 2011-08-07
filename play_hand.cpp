#include "headers.h"

bool choiceisplayed(player &, int);
void playersplay(player &, card &);
void otherplayersplay(player &, card &);
void pickcard(player &, int choice, card &);

void play_hand(string winner, string suit, player & play, player & wplay, player & nplay, player & eplay, alltrick & test, int suitint)
{
	candp();
	cout << "Playing Hand." << endl;

	string playfirst;
	
	play.temporaryhack();
	wplay.temporaryhack();
	nplay.temporaryhack();
	eplay.temporaryhack(); 

	card a,b,c,d;
	
	if (winner == "Player")
	{  playfirst = "Player"; }
	if (winner == "West")
	{  playfirst = "West"; }
	if (winner == "North")
	{  playfirst = "North"; }
	if (winner == "East")
	{  playfirst = "East"; }

	trick got[12];
	int x = 0;
	for (;;)
	{
		int inside = 1, suittofollow = 0, first = 0;
		for(;;)
		{
		if (playfirst == "Player")
		{
			playersplay(play, a);
			playfirst = "West";
			a.orderplayed = inside;
			if (inside == 1) {  suittofollow = a.suitnumber;
			first = 1;}
			inside++;
			cout << "Player played: " << a << endl;
		}
		if (inside ==5){break; } 
		if (playfirst == "West")
		{ 
			otherplayersplay(wplay, b);
			playfirst = "North";		
			b.orderplayed = inside;
			if (inside == 1) {  suittofollow = b.suitnumber;
			first = 2;}
			inside++;
			cout << "West played: " << b << endl;
		}
		if (inside ==5){break; } 
		if (playfirst == "North")
		{
			otherplayersplay(nplay, c);
			playfirst = "East";	
			c.orderplayed = inside;
			if (inside == 1) {  suittofollow = c.suitnumber;
			first = 3;}
			inside++;
			cout << "North played: " << c << endl;
		}
		if (inside ==5){break; } 
		if (playfirst == "East")
		{ 
			otherplayersplay(eplay, d);
			playfirst = "Player";
			d.orderplayed = inside;
			if (inside == 1) {  suittofollow = d.suitnumber;
			first = 4;}
			inside++;
			cout << "East played: " << d << endl;
		}
		if (inside ==5){break;} 
		}
		a.suittofollow = b.suittofollow = c.suittofollow = d.suittofollow = suittofollow;

		trick temp(a,b,c,d);
		a.istrump(suitint);
		b.istrump(suitint);
		c.istrump(suitint);
		d.istrump(suitint);
		
		temp.trickwinner = a.whichwins(a,b,c,d);
		
		std::cout << "The winning card is: " << temp.trickwinner << std::endl;
		if (temp.trickwinner == a){temp.nametrickwinner = playfirst = "Player"; }
		if (temp.trickwinner == b){temp.nametrickwinner = playfirst = "West";}
		if (temp.trickwinner == c){temp.nametrickwinner = playfirst = "North";}
		if (temp.trickwinner == d){temp.nametrickwinner = playfirst = "East";}
		if (!(temp.trickwinner == a || temp.trickwinner == b || temp.trickwinner == c || temp.trickwinner == d))
		{
			playfirst = "Player"; // This will happen to make game continue
		}

		got[x] = temp;
		
		x++;
		if (x == 12){ break;}

		line();
	}

	alltrick test1(got[0], got[1], got[2], got[3], got[4], got[5], got[6], got[7], got[8], got[9], got[10], got[11]);

	test = test1; 
}

	void playersplay(player & play, card & a)
	{
			cout << endl << "Which card do you want to play?" << endl;
			play.saycards();
			int choice;
			for(;;)
			{
			cin >> choice;
			cout << endl;
			if (choice <1 || choice > 12 || choiceisplayed(play, choice))
			{cout << "Please try again." << endl;}
			else {break;}
			}
		pickcard( play,choice,  a);
	}

	void otherplayersplay(player & play, card & c) // & This just picks the next card, not the logical choice -- Needs to be unhacked
	{
	play.choice++;
	
	pickcard( play,play.choice,  c);
	
	}

	bool choiceisplayed(player & p, int choice)
	{
		if (p.first1.played == true)  { if (choice == p.first1.order) {return true;}}
		if (p.second1.played == true)  { if (choice == p.second1.order) {return true;}}
		if (p.third1.played == true)  { if (choice == p.third1.order) {return true;}}
		if (p.fourth1.played == true)  { if (choice == p.fourth1.order) {return true;}}
		if (p.fifth1.played == true)  { if (choice == p.fifth1.order) {return true;}}
		if (p.sixth1.played == true)  { if (choice == p.sixth1.order) {return true;}}
		if (p.seventh1.played == true)  { if (choice == p.seventh1.order) {return true;}}
		if (p.eight1.played == true)  { if (choice == p.eight1.order) {return true;}} 
		if (p.ninth1.played == true)  { if (choice == p.ninth1.order) {return true;}}
		if (p.tenth1.played == true)  { if (choice == p.tenth1.order) {return true;}}
		if (p.eleventh1.played == true)  { if (choice == p.eleventh1.order) {return true;}}
		if (p.twelth1.played == true)  { if (choice == p.twelth1.order) {return true;}}
		
		return false;
	}

	void pickcard(player & play, int choice, card & a){

			if (choice == play.first1.order)
			{ play.first1.played = true;
			a = play.first1;}
			if (choice == play.second1.order)
			{ play.second1.played = true; 
			a = play.second1;}
			if (choice == play.third1.order)
			{ play.third1.played = true; 
			a = play.third1;}
			if (choice == play.fourth1.order)
			{ play.fourth1.played = true; 
			a = play.fourth1;}
			if (choice == play.fifth1.order)
			{ play.fifth1.played = true;
			a = play.fifth1;}
			if (choice == play.sixth1.order)
			{ play.sixth1.played = true;
			a = play.sixth1;}
			if (choice == play.seventh1.order)
			{ play.seventh1.played = true; 
			a = play.seventh1;}
			if (choice == play.eight1.order) 
			{ play.eight1.played = true;
			a = play.eight1;}
			if (choice == play.ninth1.order)
			{ play.ninth1.played = true; 
			a = play.ninth1;}
			if (choice == play.tenth1.order)
			{ play.tenth1.played = true; 
			a = play.tenth1;}
			if (choice == play.eleventh1.order)
			{ play.eleventh1.played = true;
			a = play.eleventh1;}
			if (choice == play.twelth1.order)
			{ play.twelth1.played = true; 
			a = play.twelth1;}
	}

/*
void playinghand::tingting(player & play, playinghand & pla, int & playersplay, int & theplayedcard, int & anotherthing, int x)
{
}*/
