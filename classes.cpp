#include "headers.h"

//& Right now this seems to hold random class functions that belong in the classes seperate file -- They are not the most useful classes I have ever seen

scoring::scoring():

aces_around(10), double_aces_around(100), kings_around(8), double_kings_around(40), queens_around(6), double_queens_around(30), 
jacks_around(4), double_jacks_around(20), marriage(2), marriage_in_trump(4), marriages_around(80), double_marriage(30), book(15), 
double_book(150), pinochle(4), double_pinochle(30), score(0)

{};

int number (int a, int b, int c, int d, int e, int f, int g, int h, int i , int j , int k , int l, int ab, int ba ) // Used in howmanyclubs.. howmanydiamonds...
	{
		int x = 0;
	if (a > ab && a <ba)
	{
		x++;
	}
	if (b > ab && b <ba)
	{
		x++;
	}
	if (c > ab && c <ba)
	{
		x++;
	}
	if (d > ab && d <ba)
	{
		x++;
	}
	if (e > ab && e <ba)
	{
		x++;
	}
	if (f > ab && f <ba)
	{
		x++;
	}
	if (g > ab && g <ba)
	{
		x++;
	}
	if (h > ab && h <ba)
	{
		x++;
	}
	if (i > ab && i <ba)
	{
		x++;
	}
	if (j > ab && j <ba)
	{
		x++;
	}
	if (k > ab && k <ba)
	{
		x++;
	}
	if (l > ab && l <ba)
	{
		x++;
	}
	
	return x;
	}


std::string dog(int card1) // Call found in player.cpp
{
	suit heart("Heart");
	suit diamond("diamond");
	suit spade("Spade");
	suit club("club");
	if (card1 == heart.ace1 || card1 == heart.ace2)
	{
		return heart.acename;
	}
	if (card1 == heart.ten1 || card1 == heart.ten2)
	{
		return heart.tenname;
	}
	if (card1 == heart.king1 || card1 == heart.king2)
	{
		return heart.kingname;
	}
	if (card1 == heart.queen1 || card1 == heart.queen2)
	{
		return heart.queenname;
	}
	if (card1 == heart.jack1 || card1 == heart.jack2)
	{
		return heart.jackname;
	}
	if (card1 == heart.nine1 || card1 == heart.nine2)
	{
		return heart.ninename;
	}

	if (card1 == diamond.ace1 || card1 == diamond.ace2)
	{
		return diamond.acename;
	}
	if (card1 == diamond.ten1 || card1 == diamond.ten2)
	{
		return diamond.tenname;
	}
	if (card1 == diamond.king1 || card1 == diamond.king2)
	{
		return diamond.kingname;
	}
	if (card1 == diamond.queen1 || card1 == diamond.queen2)
	{
		return diamond.queenname;
	}
	if (card1 == diamond.jack1 || card1 == diamond.jack2)
	{
		return diamond.jackname;
	}
	if (card1 == diamond.nine1 || card1 == diamond.nine2)
	{
		return diamond.ninename;
	}

	if (card1 == spade.ace1 || card1 == spade.ace2)
	{
		return spade.acename;
	}
	if (card1 == spade.ten1 || card1 == spade.ten2)
	{
		return spade.tenname;
	}
	if (card1 == spade.king1 || card1 == spade.king2)
	{
		return spade.kingname;
	}
	if (card1 == spade.queen1 || card1 == spade.queen2)
	{
		return spade.queenname;
	}
	if (card1 == spade.jack1 || card1 == spade.jack2)
	{
		return spade.jackname;
	}
	if (card1 == spade.nine1 || card1 == spade.nine2)
	{
		return spade.ninename;
	}
	if (card1 == club.ace1 || card1 == club.ace2)
	{
		return club.acename;
	}
	if (card1 == club.ten1 || card1 == club.ten2)
	{
		return club.tenname;
	}
	if (card1 == club.king1 || card1 == club.king2)
	{
		return club.kingname;
	}
	if (card1 == club.queen1 || card1 == club.queen2)
	{
		return club.queenname;
	}
	if (card1 == club.jack1 || card1 == club.jack2)
	{
		return club.jackname;
	}
	if (card1 == club.nine1 || card1 == club.nine2)
	{
		return club.ninename;
	}
	return "Error!";
}


hand::hand()
{
	suit hearts("heart");
	heart = hearts;
	suit diamonds("diamond");
	diamond = diamonds;
	suit spades("spades");
	spade = spades;
	suit clubs("club");
	club = clubs;
}


