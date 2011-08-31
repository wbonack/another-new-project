/// This is my second try at this, simplifying broken code is a waste of time....
/// This will hopefully replace the passing function and all the hacks that went with it...
/// cards_change_hands will also hopefully get replaced....

#include "headers.h"

void new_passing(string & winner, string & suitname, player & play, player & wplay, player & nplay, player & eplay)
{
	cout << "New Passing ---- " << endl;
	
	play.temporaryhack(); /// I would love to get rid of any hacks
	wplay.temporaryhack();
	nplay.temporaryhack();
	eplay.temporaryhack(); 
	
	if (winner == "Player")
	{
		
		play.saycards_in_hand();
		
		
	}
	if (winner == "West")
	{
		
		
		
	}
	
	if (winner == "North")
	{
		
		
		
	}
	
	if (winner == "East")
	{
		
		
		
	}
	
}

int suittonumber(string suit); // In bid.cpp


int pass4(string & winner, string & suitname, player & play, player & nplay)
{
	card card_array[12];
	
	card_array[0] = play.card1;
	card_array[1] = play.card2;
	card_array[2] = play.card3;
	card_array[3] = play.card4;
	card_array[4] = play.card5;
	card_array[5] = play.card6;
	card_array[6] = play.card7;
	card_array[7] = play.card8;
	card_array[8] = play.card9;
	card_array[9] = play.card10;
	card_array[10] = play.card11;
	card_array[11] = play.card12;
	
	int eligible_cards = 0;
	
	bool hit_ace_of_trump = false;
	int hit_ace_of_trump_times = 0;
	int array_counter = 0;
	while (array_counter < 12)
	{
		if (card_array[array_counter].power == 1 && card_array[array_counter].suitnumber == suittonumber(suitname))
		{
			hit_ace_of_trump = true;
			hit_ace_of_trump_times++;
		}
	}
	eligible_cards += hit_ace_of_trump_times;
	
	
	bool hit_ten_of_trump = false;
	int hit_ten_of_trump_times = 0;
	array_counter = 0;
	while (array_counter < 12)
	{
		if (card_array[array_counter].power == 2 && card_array[array_counter].suit == suittonumber(suitname))
		{
			hit_ten_of_trump = true;
			hit_ten_of_trump_times++;
		}
	}
	eligible_cards += hit_ten_of_trump_times;
	
	if (eligible > 3)
	{
		if (eligible > 4)
		{
			// Fix it :)
		}
		return 1;
	}
	
	
	bool hit_king_of_trump = false;
	int hit_king_of_trump_times = 0;
	array_counter = 0;
	while array_counter < 12)
	{
		if (card_array[array_counter].power == 3 && card_array[array_counter].suit == suittonumber(suitname))
		{
			hit_king_of_trump = true;
			hit_king_of_trump_times++;
		}
	}
	eligible_cards += hit_king_of_trump_times;
	
	return 0; // It failed!
}
