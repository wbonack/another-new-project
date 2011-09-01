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


int pass4(string & winner, string & suitname, player & play, player & nplay) // This does the work of passing four cards across the table
{
	card card_array[12];
	
	card_array[0] = nplay.card1;
	card_array[1] = nplay.card2;
	card_array[2] = nplay.card3;
	card_array[3] = nplay.card4;
	card_array[4] = nplay.card5;
	card_array[5] = nplay.card6;
	card_array[6] = nplay.card7;
	card_array[7] = nplay.card8;
	card_array[8] = nplay.card9;
	card_array[9] = nplay.card10;
	card_array[10] = nplay.card11;
	card_array[11] = nplay.card12;
	
	int eligible_cards = 0;
	
	card card_array_eligible[12];
	
	bool hit_ace_of_trump = false;
	int hit_ace_of_trump_times = 0;
	int array_counter = 0;
	while (array_counter < 12)
	{
		if (card_array[array_counter].power == 1 && card_array[array_counter].suitnumber == suittonumber(suitname))
		{
			card_array_eligible[eligible_cards + hit_ace_of_trump_times] = card_array[array_counter];
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
		if (card_array[array_counter].power == 2 && card_array[array_counter].suitnumber == suittonumber(suitname))
		{
			card_array_eligible[eligible_cards + hit_ten_of_trump_times] = card_array[array_counter];
			hit_ten_of_trump = true;
			hit_ten_of_trump_times++;
		}
	}
	eligible_cards += hit_ten_of_trump_times;
	
	if (eligible_cards > 3)
	{
		if (eligible_cards > 4) /// This is technically error checking
		{
			// Fix it :)
		}
	
		play.pass_possibility1 = card_array_eligible[0].number;
		play.pass_possibility2 = card_array_eligible[1].number;
		play.pass_possibility3 = card_array_eligible[2].number;
		play.pass_possibility4 = card_array_eligible[3].number;
		
		play.pass_possibility_name1 = card_array_eligible[0].name;
		play.pass_possibility_name2 = card_array_eligible[1].name;
		play.pass_possibility_name3 = card_array_eligible[2].name;
		play.pass_possibility_name4 = card_array_eligible[3].name;
	
	
		return 1;
	}
	
	
	bool hit_king_of_trump = false;
	int hit_king_of_trump_times = 0;
	array_counter = 0;
	while (array_counter < 12)
	{
		if (card_array[array_counter].power == 3 && card_array[array_counter].suitnumber == suittonumber(suitname))
		{
			hit_king_of_trump = true;
			hit_king_of_trump_times++;
		}
	}
	eligible_cards += hit_king_of_trump_times;
	
	return 0; // It failed!
}
