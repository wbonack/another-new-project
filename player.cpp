#include "headers.h"

player::player()
{

card1 = 0, card2 = (0), card3 =0, card4=0, card5=0, card6= 0 , card7 = 0, card8 = 0, card9 = 0, card10 = 0, card11 = 0, card12 =0,
	first1 = 1, howmanyhearts = 0, howmanydiamonds = 0, howmanyclubs = 0, howmanyspades = 0;
	order1true = true, order2true = true , order3true = true, order4true = true, order5true =  true , order6true = true,
	order7true = true, order8true = true, order9true = true, order10true = true, order11true = true, order12true = true;
};


player::player(int a,int b,int c, int d,int e,int f,int g,int h,int i,int j ,int k ,int l)
{
	card1 = a, card2 = b, card3 = c, card4 = d, card5 = e, card6 = f, card7 = g, card8 = h, card9 = i, card10 = j, card11 = k, card12 = l;
card da1(card1), da2(card2), da3(card3), da4(card4), da5(card5), da6(card6), da7(card7), da8(card8), da9(card9), da10
		(card10), da11(card11), da12(card12);
	first1 = da1, second1 = da2; third1 = da3; fourth1 = da4; fifth1 = da5; sixth1 = da6; seventh1 = da7; eight1 = da8;
		ninth1 = da9, tenth1 = da10, eleventh1 = da11, twelth1 = da12;
	order1true = true; order2true = true; order3true = true; order4true = (true); order5true = (true); order6true = (true);
	order7true = (true), order8true  = (true), order9true = (true), order10true=(true), order11true =(true), order12true = (true);
	howmanyhearts = 0, howmanydiamonds = 0, howmanyclubs = 0, howmanyspades = 0;
	
	std::string name_card(int); // Found in player.cpp
	
	name1 = name_card(card1);
	name2 = name_card(card2);
	name3 = name_card(card3);
	name4 = name_card(card4);
	name5 = name_card(card5);
	name6 = name_card(card6);
	name7 = name_card(card7);
	name8 = name_card(card8);
	name9 = name_card(card9);
	name10 = name_card(card10);
	name11 = name_card(card11);
	name12 = name_card(card12);
};

void player::order(string a, string b, string c, string d, string e, string f, string g, string h, string i, string j, string k, string l)
{
	order1 = a; order2 = b; order3 = c; order4 = d; order5 = e; order6 = f; order7 = g; order8 = h; order9 = i; order10 = j;
	order11 = k; order12 = l;
}


void player::get_names()
{
	std::string name_card(int); // Found in player.cpp 
	name1 = name_card(card1);
	name2 = name_card(card2);
	name3 = name_card(card3);
	name4 = name_card(card4);
	name5 = name_card(card5);
	name6 = name_card(card6);
	name7 = name_card(card7);
	name8 = name_card(card8);
	name9 = name_card(card9);
	name10 = name_card(card10);
	name11 = name_card(card11);
	name12 = name_card(card12);
}

std::string name_card(int card1) // Call found in player.cpp
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


void player::convert() // & Used in temporaryhack
{
	card da1(card1), da2(card2), da3(card3), da4(card4), da5(card5), da6(card6), da7(card7), da8(card8), da9(card9), da10
		(card10), da11(card11), da12(card12);
	first1 = da1, second1 = da2; third1 = da3; fourth1 = da4; fifth1 = da5; sixth1 = da6; seventh1 = da7; eight1 = da8;
		ninth1 = da9, tenth1 = da10, eleventh1 = da11, twelth1 = da12;
	
}

void player::saycards_in_hand() // Used when player is playing their hand and checks if it is played before showing it
{
	for(int counter = 0 ;counter < 13 ; counter++)
	{
		if (first1.order == counter && first1.played == false)
		{ 
			cout << first1 << endl;  
		}
		if (second1.order == counter && second1.played == false)
		{ 
			cout << second1 << endl; 
		}
		if (third1.order == counter && third1.played == false)
		{ 
			cout << third1 << endl;  
		}
		if (fourth1.order == counter && fourth1.played == false)
		{ 
			cout << fourth1 << endl; 
		}
		if (fifth1.order == counter && fifth1.played == false)
		{ 
			cout << fifth1 << endl;  
		}
		if (sixth1.order == counter && sixth1.played == false)
		{ 
			cout << sixth1 << endl;  
		}
		if (seventh1.order == counter && seventh1.played == false)
		{ 
			cout << seventh1 << endl; 
		}
		if (eight1.order == counter && eight1.played == false)
		{ 
			cout << eight1 << endl;  
		}
		if (ninth1.order == counter && ninth1.played == false)
		{ 
			cout << ninth1 << endl;  
		}
		if (tenth1.order == counter && tenth1.played == false)
		{ 
			cout << tenth1 << endl;  
		}
		if (eleventh1.order == counter && eleventh1.played == false)
		{ 
			cout << player::eleventh1 << endl; 
		}
		if (twelth1.order == counter && twelth1.played == false)
		{ 
			cout << player::twelth1 << endl; 
		}
	}
}
	
	
void player::temporaryhack() // Bullshit -- Is this even needed anymore? .... Yep for play_hand.... :(
{
	convert();
	first1.fixorder(first1, second1, third1, fourth1, fifth1, sixth1, seventh1, eight1, ninth1, tenth1, eleventh1, twelth1);
	
	int howmanyofsuit(player &);

	howmanyofsuit(*this);
	
	choice = 0;
}

void player::cardnames()
{
	cout << order1<< " , " << order2<< " , "  << order3 << " , " << order4   << endl  ;
	cout  << order5 << " , " << order6 << " , " <<  order7 << " , " << order8  <<  endl;
	cout << order9 << " , " << order10 << " , " << order11 << " , " << order12  << endl << endl;
}

void player::getorder() // This gets the cards in order.
{
	int tempx = 1, tempy = 0; 
	std::string name_array[12];  // These temporarily hold the names of the cards when putting them in order.
	int number[12];        // These hold the numbers of the cards.

	while (tempx < 49)// Sees what numbers the cards have and puts into a number and the number with the corresponding number.
	{
		if (card1 == tempx) 
		{ 
			name_array[tempy] = name1; 
			number[tempy] = tempx;	
			tempy++;  
		}
		if (card2 == tempx) 
		{ 
			name_array[tempy] = name2; 
			number[tempy] = tempx;	
			tempy++;  
		}
		if (card3 == tempx) 
		{ 
			name_array[tempy] = name3; 
			number[tempy] = tempx;	
			tempy++;  
		}
		if (card4 == tempx) 
		{ 
			name_array[tempy] = name4; 
			number[tempy] = tempx;	
			tempy++;  
		}
		if (card5 == tempx) 
		{ 
			name_array[tempy] = name5; 
			number[tempy] = tempx;	
			tempy++;  
		}
		if (card6 == tempx) 
		{ 
			name_array[tempy] = name6; 
			number[tempy] = tempx;	
			tempy++;  
		}
		if (card7 == tempx) 
		{ 
			name_array[tempy] = name7; 
			number[tempy] = tempx;	
			tempy++;  
		}
		if (card8 == tempx) 
		{ 
			name_array[tempy] = name8; 
			number[tempy] = tempx;	
			tempy++;  
		}
		if (card9 == tempx) 
		{ 
			name_array[tempy] = name9; 
			number[tempy] = tempx;	
			tempy++;  
		}
		if (card10 == tempx) 
		{ 
			name_array[tempy] = name10; 
			number[tempy] = tempx;	
			tempy++;  
		}
		if (card11 == tempx) 
		{ 
			name_array[tempy] = name11; 
			number[tempy] = tempx;	
			tempy++;  
		}
		if (card12 == tempx) 
		{ 
			name_array[tempy] = name12; 
			number[tempy] = tempx;	
			tempy++;  
		}
		
		tempx++;
	}

	int tempint = 0;

	while(tempint < 12)
	{
	tempx = 0;

	while (tempx < 10)
	{
		if (number[tempx] > number[tempx + 1])
		{
			//cout << "Entered the if statement on line 315 of player.cpp " << endl; p();
			/// THIS IS CONFUSING
			std::string tempname;
			int tempnumber;
			tempname = name_array[tempx];
			name_array[tempx] = name_array[tempx + 1];
			name_array[tempx + 1] = tempname;
			tempnumber = number[tempx];
			number[tempx] = number[tempx + 1];
			number[tempx + 1]  = tempnumber;
		}
		tempx++;
	}
	tempint++;
	}

	ord1 = number[0]; ord2 = number[1]; ord3 = number[2]; ord4 = number[3]; ord5 = number[4]; ord6 = number[5];
	ord7 = number[6]; ord8 = number[7]; ord9 = number[8]; ord10 = number[9]; ord11 = number[10]; ord12 = number[11];

	order1 = name_array[0]; order2 = name_array[1]; order3 = name_array[2]; order4 = name_array[3]; order5 = name_array[4]; order6 = name_array[5];
	order7 = name_array[6]; order8 = name_array[7]; order9 = name_array[8]; order10 = name_array[9]; order11 = name_array[10]; order12 = name_array[11];
}
