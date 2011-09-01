/// This is my second try at this, simplifying broken code is a waste of time....
/// This will hopefully replace the passing function and all the hacks that went with it...
/// cards_change_hands will also hopefully get replaced....

#include "headers.h"

int pass4(string & winner, string & suitname, player & play, player & nplay);


void new_passing(string & winner, string & suitname, player & play, player & wplay, player & nplay, player & eplay)
{
	cout << "New Passing ---- " << endl;
	
	play.temporaryhack(); /// I would love to get rid of any hacks
	wplay.temporaryhack();
	nplay.temporaryhack();
	eplay.temporaryhack(); 
	
	if (winner == "Player")
	{
		if (!pass4(winner, suitname, play, nplay))
		{
			cout << "Error in new_passing, in winner == player loop." << endl;
		}
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
	
	cout << "This is a check to make sure everything has values: " << endl;
	
	int quickcheck1 = 0;
	cout << "Suitnumber is: " << suittonumber(suitname) << endl;
	while (quickcheck1 < 12)
	{
		
	cout << card_array[quickcheck1].number << card_array[quickcheck1].name << card_array[quickcheck1].suitnumber << " power: " << card_array[quickcheck1].power << endl;
	quickcheck1++;
	}
	
	int eligible_cards = 0;
	
	card card_array_eligible[12];
	
	int hit_array[5];
	
	int zero_array_int = 0;
	while (zero_array_int < 5)
	{
		hit_array[zero_array_int] = 0;
		zero_array_int++;
	}
	
	
	int hit_ace_of_trump_times = 0;
	int hit_ten_of_trump_times = 0;
	int hit_king_of_trump_times = 0;
	int hit_queen_of_trump_times = 0;
	int hit_jack_of_trump_times = 0;
	
	
	int array_counter = 0;
	int card_checking = 0;
	
	while (card_checking < 5)
	{
		array_counter = 0;
		
		while (array_counter < 12)
		{
			if (card_array[array_counter].power == card_checking && card_array[array_counter].suitnumber == suittonumber(suitname))
			{
				
				if (eligible_cards + hit_array[card_checking] <4)
				{
				
				card_array_eligible[eligible_cards + hit_ace_of_trump_times] = card_array[array_counter];
				
				hit_array[card_checking]++;
				
				}
			}
			
			array_counter++;
		}
		
		eligible_cards += hit_array[card_checking];
		cout << "Eligible cards after card " << card_checking << " is " << eligible_cards << endl;
		card_checking++;
	}
	
	
	if (eligible_cards > 3)
	{
		int quick_check_number = 0;
		
		while (quick_check_number < 4)
		{
			cout << card_array_eligible[quick_check_number].name << endl;
			quick_check_number++;
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
	
	cout << "Eligible1 : " << card_array_eligible[0].name << endl;
	cout << "Eligible2 : " << card_array_eligible[1].name << endl;
	cout << "Eligible3 : " << card_array_eligible[2].name << endl;
	cout << "Eligible4 : " << card_array_eligible[3].name << endl;
	
	return 0; // It failed!
}
