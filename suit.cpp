#include "headers.h"

suit::suit()
{};

int suit::howmanyofsuit(int card1, int card2, int card3, int card4, int card5, int card6, int card7, int card8, int card9,
int card10,int card11, int card12)
{
	int boundary1, boundary2;
	int a = card1, b = card2, c = card3, d = card4, e = card5, f = card6, g = card7, h = card8, i = card9, j = card10, 
		k = card11, l = card12, x = 0;
	if (nameofsuit == "Hearts" || nameofsuit == "Heart" || nameofsuit == "hearts" || nameofsuit == "heart")
	{	boundary1 = 0, boundary2 = 13;}
	if (nameofsuit == "Diamonds" || nameofsuit == "Diamond" || nameofsuit == "diamonds" || nameofsuit == "diamond" )
	{	boundary1 = 12, boundary2 = 25;}
	if (nameofsuit == "Spades" || nameofsuit == "Spade" || nameofsuit == "spades" || nameofsuit == "spade")
	{       boundary1 = 24, boundary2 = 37;}
	if (nameofsuit == "Clubs" || nameofsuit == "Club" || nameofsuit == "clubs" || nameofsuit == "club")
	{	boundary1 = 36, boundary2 = 49;}
	return x = number(a, b, c, d, e, f, g, h, i , j , k, l, boundary1, boundary2);
}

suit::suit(std::string suitname)
{
nameofsuit = suitname;
if (suitname == "Hearts" || suitname == "Heart" || suitname == "hearts" || suitname == "heart")
{
ace1 = 1, ace2 = 2, ten1 = 3, ten2 = 4, king1 = 5, king2 = 6, 
queen1 = 7, queen2 = 8, jack1 = 9, jack2 = 10, nine1 = 11, nine2 = 12;
ace1bool = false, ace2bool = false, ten1bool = false, ten2bool = false, king1bool = false, king2bool = false, queen1bool = false;
queen2bool = false, jack1bool = false, jack2bool = false, nine1bool = false, nine2bool = false, acename = "Ace of Hearts", 
tenname = "Ten of Hearts", kingname = "King of Hearts", queenname = "Queen of Hearts", jackname = "Jack of Hearts", 
ninename = "Nine of Hearts";
}

if (suitname == "Diamonds" || suitname == "Diamond" || suitname == "diamonds" || suitname == "diamond" )
{
ace1 = 13, ace2 = 14, ten1 = 15, ten2 = 16, king1 = 17, king2 = 18, queen1 = 19, queen2 = 20, jack1 = 21, jack2 = 22, nine1 = 23, nine2 = 24,
ace1bool = false, ace2bool = false, ten1bool = false, ten2bool = false, king1bool = false, king2bool = false, queen1bool = false,
queen2bool = false, jack1bool = false, jack2bool = false, nine1bool = false, nine2bool = false, acename = "Ace of Diamonds", 
tenname = "Ten of Diamonds", kingname = "King of Diamonds", queenname = "Queen of Diamonds", jackname = "Jack of Diamonds", 
ninename = "Nine of Diamonds";
}

if (suitname == "Spades" || suitname == "Spade" || suitname == "spades" || suitname == "spade")
{
ace1 = 25, ace2 = 26, ten1 = 27, ten2 = 28, king1 = 29, king2 = 30, queen1 = 31, queen2 = 32, jack1 = 33, jack2 = 34, nine1 = 35, nine2 = 36,ace1bool = false, ace2bool = false, ten1bool = false, ten2bool = false, king1bool = false, king2bool = false, queen1bool = false,queen2bool = false, jack1bool = false, jack2bool = false, nine1bool = false, nine2bool = false, acename = "Ace of Spades", tenname = "Ten of Spades", kingname = "King of Spades", queenname = "Queen of Spades", jackname = "Jack of Spades", ninename = "Nine of Spades";
}

if (suitname == "Clubs" || suitname == "Club" || suitname == "clubs" || suitname == "club")
{
ace1 = 37 , ace2 = 38 , ten1 = 39 , ten2 = 40 , king1 = 41 , king2 = 42 , queen1 = 43 , queen2 = 44 , jack1 = 45 , jack2 = 46 , nine1 = 47 , nine2 = 48 ,
ace1bool = false , ace2bool = false , ten1bool = false , ten2bool = false , king1bool = false , king2bool = false , queen1bool = false ,queen2bool = false , jack1bool = false , jack2bool = false , nine1bool = false , nine2bool = false , acename = "Ace of Clubs" , tenname = "Ten of Clubs" , kingname = "King of Clubs" , queenname = "Queen of Clubs" , jackname = "Jack of Clubs" , ninename = "Nine of Clubs" ;
}

};
