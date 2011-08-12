#include "headers.h"

void playersscore(int *, player play);

void sortcards(int *,player play,int *);

void scoring_func(int * pla, int * west,int * north,int * east, int * westpot, int * northpot, int * eastpot, int * playerpot, player * play,  player * wplay, player * nplay, player * eplay) 
{	
	player pc = (*play);
	player wc = (*wplay);
	player nc = (*nplay);
	player ec = (*eplay);

	*pla = 0,*west = 0, *north = 0, *east = 0;

	playersscore(pla, pc);

	playersscore(west, wc);
	
	playersscore(north, nc);
	
	playersscore(east, ec);

	 *westpot = *west;
	 *northpot = *north;
	 *eastpot = *east;
	 *playerpot = *pla;
}

void playersscore(int * west, player play)
{
	int the_score; 
	
	sortcards(west, play, &the_score);
}
// This class is a quick hack I made to assign the boolean values to cards that were in the hand. --- This whole concept is quite messy....
// In simplified language this takes the int value of the card and if it is equal to the card in the suit the boolean for that card is changed to true or ("yes i have it")
// This is easier to read and saved about 10 lines totalll
class trifecta
	{  
		public: 
			int x1; 
			int * heart1; 
			bool * heart1bool; 
			void define_trifecta(int a, int * b , bool * c); 
			void usetrifecta(int);
	};

		void trifecta::define_trifecta(int a, int * b , bool * c) 
		{ 
			x1 = a; 
			heart1 = b; 
			heart1bool = c;
		}

void trifecta::usetrifecta(int card){ 
while ( x1 < 13)
		{
		if (card == *heart1){ *heart1bool = true; }
		x1++;
		heart1++;
		heart1bool++;
		}
}

void sortcards(int * biddingscore,player play, int * playerscore)
{
	scoring score;
	suit heart("heart");
	suit diamond("diamond");
	suit spade("Spade");
	suit club("club");
	
	int counter = 1, card;
	int totalsofar = 0;
	bool donescoring = false;
	while(donescoring == false)
	{
		if (counter == 1) { card = play.card1;}
		if (counter == 2) { card = play.card2;}
		if (counter == 3) { card = play.card3;}
		if (counter == 4) { card = play.card4;}
		if (counter == 5) { card = play.card5;}
		if (counter == 6) { card = play.card6;}
		if (counter == 7) { card = play.card7;}
		if (counter == 8) { card = play.card8;}
		if (counter == 9) { card = play.card9;}
		if (counter == 10) { card = play.card10;}
		if (counter == 11) { card = play.card11;}
		if (counter == 12) { card = play.card12; donescoring = true;}
		if (counter >= 13)
		{
			cout << "Error in scoring. Counter >= 13." << endl;
		}
		
		int x1 = 1; int * heart1 = &heart.ace1;  bool * heart1bool = &heart.ace1bool;
		
		trifecta t1;
		t1.define_trifecta(x1, heart1, heart1bool);
		t1.usetrifecta(card);
		
		t1.define_trifecta(1, &diamond.ace1, &diamond.ace1bool);
		t1.usetrifecta(card);
		
		t1.define_trifecta(1, &spade.ace1, &spade.ace1bool);
		t1.usetrifecta(card);
	
		t1.define_trifecta(1, &club.ace1, &club.ace1bool);
		t1.usetrifecta(card);
		
	counter++;
	}

		bool doubleacesaround = false;
		bool doublepinochle = false;
		
		if (heart.ace1bool == true && heart.ace2bool == true&&diamond.ace1bool == true&&diamond.ace2bool == true&&
			spade.ace1bool == true && spade.ace2bool == true&&club.ace1bool == true&&club.ace2bool == true)
		{
			totalsofar += score.double_aces_around;
			doubleacesaround = true;
		}

		if ((heart.ace1bool == true || heart.ace2bool == true)&&(diamond.ace1bool == true || diamond.ace2bool == true)&&
			(spade.ace1bool == true || spade.ace2bool == true)&&(club.ace1bool == true || club.ace2bool == true)&& 
			doubleacesaround == false)
		{
			totalsofar += score.aces_around;
		}

		if (spade.queen1bool== true&&spade.queen2bool == true && diamond.jack1bool == true && diamond.jack2bool == true)
		{
			totalsofar += score.double_pinochle;
			doublepinochle = true;
		}

		if ((spade.queen1bool== true||spade.queen2bool == true) && (diamond.jack1bool == true || diamond.jack2bool == 				true)&& doublepinochle == false)
		{
			totalsofar += score.pinochle;
		}

		if ((heart.king1bool == true||heart.king2bool == true)&&(heart.queen1bool == true || heart.queen2bool == true))
		{
			totalsofar += score.marriage;		
		}

		if ((diamond.king1bool == true||diamond.king2bool == true)&&(diamond.queen1bool == true || 
			diamond.queen2bool == true))
		{
			totalsofar += score.marriage;	
		}
		if ((spade.king1bool == true||spade.king2bool == true)&&(spade.queen1bool == true || spade.queen2bool == true))
		{
			totalsofar += score.marriage;	
		}
		if ((club.king1bool == true||club.king2bool == true)&&(club.queen1bool == true || club.queen2bool == true))
		{
			totalsofar += score.marriage;	
		}

		if ((heart.king1bool == true|| heart.king2bool == true)&&(diamond.king1bool == true || 
			diamond.king2bool == true)&&(spade.king1bool == true|| spade.king2bool == true)&&
			(club.king1bool == true || club.king2bool == true))
		{
			totalsofar += score.kings_around;
		}

		if ((heart.queen1bool == true|| heart.queen2bool == true)&&(diamond.queen1bool == true || 
			diamond.queen2bool == true)&&(spade.queen1bool == true|| spade.queen2bool == true)&&
			(club.queen1bool == true || club.queen2bool == true))
		{
			totalsofar += score.queens_around;
		}

		if ((heart.jack1bool == true|| heart.jack2bool == true)&&(diamond.jack1bool == true || 
			diamond.jack2bool == true)&&(spade.jack1bool == true|| spade.jack2bool == true)&&
			(club.jack1bool == true || club.jack2bool == true))
		{
			totalsofar += score.jacks_around;
		}

		if ((heart.ace1bool == true || heart.ace2bool == true)&&(heart.ten1bool == true|| heart.ten2bool == true)&&
			(heart.king1bool == true || heart.king2bool == true)&&(heart.queen1bool == true|| heart.queen2bool == 				
			true)&&(heart.jack1bool == true || heart.jack2bool == true))
		{
			totalsofar += score.book;
		}

		if ((diamond.ace1bool == true || diamond.ace2bool == true)&&(diamond.ten1bool == true|| diamond.ten2bool == 				true)&&(diamond.king1bool == true || diamond.king2bool == true)&&(diamond.queen1bool == true|| 				diamond.queen2bool == true)&&(diamond.jack1bool == true || diamond.jack2bool == true))
		{
			totalsofar += score.book;
		}

		if ((spade.ace1bool == true || spade.ace2bool == true)&&(spade.ten1bool == true|| spade.ten2bool == true)&&
			(spade.king1bool == true || spade.king2bool == true)&&(spade.queen1bool == true|| spade.queen2bool
			 == true)&&(spade.jack1bool == true || spade.jack2bool == true))
		{
			totalsofar += score.book;
		}

		if ((club.ace1bool == true || club.ace2bool == true)&&(club.ten1bool == true|| club.ten2bool == true)&&
			(club.king1bool == true || club.king2bool == true)&&(club.queen1bool == true|| club.queen2bool == true)
			&&(club.jack1bool == true || club.jack2bool == true))
		{
			totalsofar += score.book;
		}

		bool clubbook = false;
		if ((club.ace1bool == true || club.ace2bool == true)&&(club.ten1bool == true|| club.ten2bool == true)&&
			(club.king1bool == true || club.king2bool == true)&&(club.queen1bool != true&&club.queen2bool != true)
			&&(club.jack1bool == true || club.jack2bool == true))
		{
			totalsofar += 10;
			clubbook = true;
		}

		if (((club.ace1bool == true || club.ace2bool == true)&&(club.ten1bool == true|| club.ten2bool == true)&&
			(club.king1bool != true && club.king2bool != true)&&(club.queen1bool == true|| club.queen2bool == true)
			&&(club.jack1bool == true || club.jack2bool == true))&&clubbook == false)
		{
			totalsofar += 10;
			clubbook = true;
		}

		if (((club.ace1bool != true && club.ace2bool != true)&&(club.ten1bool == true|| club.ten2bool == true)&&
			(club.king1bool == true || club.king2bool == true)&&(club.queen1bool == true|| club.queen2bool == true)
			&&(club.jack1bool == true || club.jack2bool == true))&&clubbook == false)
		{
			totalsofar += 10;
			clubbook = true;
		}

		if (((club.ace1bool == true || club.ace2bool == true)&&(club.ten1bool != true&& club.ten2bool != true)&&
			(club.king1bool == true || club.king2bool == true)&&(club.queen1bool == true|| club.queen2bool == true)
			&&(club.jack1bool == true || club.jack2bool == true))&&clubbook == false)
		{
			totalsofar += 10;
			clubbook = true;
		}

		if (((club.ace1bool == true || club.ace2bool == true)&&(club.ten1bool == true|| club.ten2bool == true)&&
			(club.king1bool == true || club.king2bool == true)&&(club.queen1bool == true|| club.queen2bool == true)
			&&(club.jack1bool != true && club.jack2bool != true))&&clubbook == false)
		{
			totalsofar += 10;
			clubbook = true;
		}

		bool spadebook = false;
		if ((spade.ace1bool == true || spade.ace2bool == true)&&(spade.ten1bool == true|| spade.ten2bool == true)&&
			(spade.king1bool == true || spade.king2bool == true)&&(spade.queen1bool != true&&spade.queen2bool != 				
			true)&&(spade.jack1bool == true || spade.jack2bool == true))
		{
			totalsofar += 10;
			spadebook = true;
		}

		if (((spade.ace1bool == true || spade.ace2bool == true)&&(spade.ten1bool == true|| spade.ten2bool == true)&&
			(spade.king1bool != true && spade.king2bool != true)&&(spade.queen1bool == true|| spade.queen2bool == 				
			true)&&(spade.jack1bool == true || spade.jack2bool == true))&&spadebook == false)
		{
			totalsofar += 10;
			spadebook = true;
		}

		if (((spade.ace1bool != true && spade.ace2bool != true)&&(spade.ten1bool == true|| spade.ten2bool == true)&&
			(spade.king1bool == true || spade.king2bool == true)&&(spade.queen1bool == true|| spade.queen2bool == 				
			true)&&(spade.jack1bool == true || spade.jack2bool == true))&&spadebook == false)
		{
			totalsofar += 10;
			spadebook = true;
		}

		if (((spade.ace1bool == true || spade.ace2bool == true)&&(spade.ten1bool != true&& spade.ten2bool != true)&&
			(spade.king1bool == true || spade.king2bool == true)&&(spade.queen1bool == true|| spade.queen2bool == 				
			true)&&(spade.jack1bool == true || spade.jack2bool == true))&&spadebook == false)
		{
			totalsofar += 10;
			spadebook = true;
		}

		if (((spade.ace1bool == true || spade.ace2bool == true)&&(spade.ten1bool == true|| spade.ten2bool == true)&&
			(spade.king1bool == true || spade.king2bool == true)&&(spade.queen1bool == true|| spade.queen2bool == 				
			true)&&(spade.jack1bool != true && spade.jack2bool != true))&&spadebook == false)
		{
			totalsofar += 10;
			spadebook = true;
		}

		bool heartbook = false;
		if ((heart.ace1bool == true || heart.ace2bool == true)&&(heart.ten1bool == true|| heart.ten2bool == true)&&
			(heart.king1bool == true || heart.king2bool == true)&&(heart.queen1bool != true&&heart.queen2bool != 				
			true)&&(heart.jack1bool == true || heart.jack2bool == true))
		{
			totalsofar += 10;
			heartbook = true;
		}

		if (((heart.ace1bool == true || heart.ace2bool == true)&&(heart.ten1bool == true|| heart.ten2bool == true)&&
			(heart.king1bool != true && heart.king2bool != true)&&(heart.queen1bool == true|| heart.queen2bool == 				
			true)&&(heart.jack1bool == true || heart.jack2bool == true))&&heartbook == false)
		{
			totalsofar += 10;
			heartbook = true;
		}

		if (((heart.ace1bool != true && heart.ace2bool != true)&&(heart.ten1bool == true|| heart.ten2bool == true)&&
			(heart.king1bool == true || heart.king2bool == true)&&(heart.queen1bool == true|| heart.queen2bool == 				
			true)&&(heart.jack1bool == true || heart.jack2bool == true))&&heartbook == false)
		{
			totalsofar += 10;
			heartbook = true;
		}

		if (((heart.ace1bool == true || heart.ace2bool == true)&&(heart.ten1bool != true&& heart.ten2bool != true)&&
			(heart.king1bool == true || heart.king2bool == true)&&(heart.queen1bool == true|| heart.queen2bool == 				
			true)&&(heart.jack1bool == true || heart.jack2bool == true))&&heartbook == false)
		{
			totalsofar += 10;
			heartbook = true;
		}

		if (((heart.ace1bool == true || heart.ace2bool == true)&&(heart.ten1bool == true|| heart.ten2bool == true)&&
			(heart.king1bool == true || heart.king2bool == true)&&(heart.queen1bool == true|| heart.queen2bool == 				
			true)&&(heart.jack1bool != true && heart.jack2bool != true))&&heartbook == false)
		{
			totalsofar += 10;
			heartbook = true;
		}

		bool diamondbook = false;
		if ((diamond.ace1bool == true || diamond.ace2bool == true)&&(diamond.ten1bool == true|| diamond.ten2bool == 				true)&&(diamond.king1bool == true || diamond.king2bool == true)&&(diamond.queen1bool != true&&
			diamond.queen2bool != true)&&(diamond.jack1bool == true || diamond.jack2bool == true))
		{
			totalsofar += 10;
			diamondbook = true;
		}

		if (((diamond.ace1bool == true || diamond.ace2bool == true)&&(diamond.ten1bool == true|| diamond.ten2bool == 				true)&&(diamond.king1bool != true && diamond.king2bool != true)&&(diamond.queen1bool == true|| 				diamond.queen2bool == true)&&(diamond.jack1bool == true || diamond.jack2bool == true))&&diamondbook == 				false)
		{
			totalsofar += 10;
			diamondbook = true;
		}

		if (((diamond.ace1bool != true && diamond.ace2bool != true)&&(diamond.ten1bool == true|| diamond.ten2bool == 				true)&&(diamond.king1bool == true || diamond.king2bool == true)&&(diamond.queen1bool == true|| 				diamond.queen2bool == true)&&(diamond.jack1bool == true || diamond.jack2bool == true))&&diamondbook == 				false)
		{
			totalsofar += 10;
			diamondbook = true;
		}

		if (((diamond.ace1bool == true || diamond.ace2bool == true)&&(diamond.ten1bool != true&& diamond.ten2bool != 				true)&&(diamond.king1bool == true || diamond.king2bool == true)&&(diamond.queen1bool == true|| 				diamond.queen2bool == true)&&(diamond.jack1bool == true || diamond.jack2bool == true))&&diamondbook == 				false)
		{
			totalsofar += 10;
			diamondbook = true;
		}

		if (((diamond.ace1bool == true || diamond.ace2bool == true)&&(diamond.ten1bool == true|| 
			diamond.ten2bool == true)&&(diamond.king1bool == true || diamond.king2bool == true)&&
			(diamond.queen1bool == true|| diamond.queen2bool == true)&&(diamond.jack1bool != true && 		
			diamond.jack2bool != true))&&diamondbook == false)
		{
			totalsofar += 10;
			diamondbook = true;
		}

		*biddingscore = totalsofar;
	
	*playerscore = totalsofar;
}


scoring::scoring():

aces_around(10), double_aces_around(100), kings_around(8), double_kings_around(40), queens_around(6), double_queens_around(30), 
jacks_around(4), double_jacks_around(20), marriage(2), marriage_in_trump(4), marriages_around(80), double_marriage(30), book(15), 
double_book(150), pinochle(4), double_pinochle(30), score(0)

{};
