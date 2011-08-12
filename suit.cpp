#include "headers.h"

suit::suit() // Shouldn't be used -- useless?
{};

int howmanyofsuit(player & play)
{
	string suitname[4];
	suitname[0] = "hearts";
	suitname[1] = "diamonds";
	suitname[2] = "spades";
	suitname[3] = "clubs";
	
	int cardspersuit[4];
	
	int thecounter = 0;
	while (thecounter < 4)
{	
	int number_lower_limit = -1, number_upper_limit = -1;
		
	if (suitname[thecounter] == "hearts")
	{	
		number_lower_limit = 0, number_lower_limit = 13;
	}
	if (suitname[thecounter] == "diamonds" )
	{	
		number_lower_limit = 12, number_lower_limit = 25;
	}
	if (suitname[thecounter] == "spades" )
	{       
		number_lower_limit = 24, number_lower_limit = 37;
	}
	if (suitname[thecounter] == "clubs" )
	{	
		number_lower_limit = 36, number_lower_limit = 49;
	}
	if (number_lower_limit == -1) /// Error check
	{
			ofstream out("error.txt");
			out << "Suit.cpp line 29 error: 'Number lower limit not defined by any case'" << endl;
			out.close();
	}
	
	int x = 0, counter = 0;
	int * card_pointer =  &play.card1; 
	while (counter < 12)
	{
		if (*card_pointer > number_lower_limit && *card_pointer < number_upper_limit)
		{
			x++;
		}
		card_pointer++;
		counter++;
	} 
	cardspersuit[thecounter] = x;
	thecounter++;
}

play.howmanyhearts = cardspersuit[0];
play.howmanydiamonds = cardspersuit[1];
play.howmanyspades = cardspersuit[2];
play.howmanyclubs = cardspersuit[3];

return 0;
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
ace1 = 25, ace2 = 26, ten1 = 27, ten2 = 28, king1 = 29, king2 = 30, queen1 = 31, queen2 = 32, jack1 = 33, jack2 = 34, nine1 = 35, nine2 = 36,ace1bool = false,
 ace2bool = false, ten1bool = false, ten2bool = false, king1bool = false, king2bool = false, queen1bool = false,queen2bool = false, jack1bool = false, jack2bool = false, 
 nine1bool = false, nine2bool = false, acename = "Ace of Spades", tenname = "Ten of Spades", kingname = "King of Spades", queenname = "Queen of Spades", 
 jackname = "Jack of Spades", ninename = "Nine of Spades";
}

if (suitname == "Clubs" || suitname == "Club" || suitname == "clubs" || suitname == "club")
{
ace1 = 37 , ace2 = 38 , ten1 = 39 , ten2 = 40 , king1 = 41 , king2 = 42 , queen1 = 43 , queen2 = 44 , jack1 = 45 , jack2 = 46 , nine1 = 47 , nine2 = 48 ,
ace1bool = false , ace2bool = false , ten1bool = false , ten2bool = false , king1bool = false , king2bool = false , queen1bool = false ,queen2bool = false , 
jack1bool = false , jack2bool = false , nine1bool = false , nine2bool = false , acename = "Ace of Clubs" , tenname = "Ten of Clubs" , kingname = "King of Clubs" , 
queenname = "Queen of Clubs" , jackname = "Jack of Clubs" , ninename = "Nine of Clubs" ;
}

};


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
