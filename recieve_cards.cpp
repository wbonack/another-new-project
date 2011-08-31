#include "headers.h"

// New Recieve_cards   // & Created and Finished this on June 10, 2010
player recieve_cards(int recieve_cardscounter)
{	
	int card1 = 0, card2 = 0, card3 = 0, card4 = 0,  card5 = 0,  card6 = 0, card7 = 0,  card8 = 0,  card9 = 0, card10 = 0,
		card11 = 0, card12 = 0;
	
	string player_name;
	
	/* initialize random seed: */ ///Found in hand.cpp after deal()
	srand_();
	
	int number = 0; 

	if (recieve_cardscounter == 1) // This runs the first time recieve_cards is called and makes the deck.
	{
		player_name = "Player";
		int card_numbers_array[48]; // This has the 48 numbers for the cards thats will be randomized	-- This is only used in if statement
		while(number < 48) // This loop makes card_numbers_array[] equal to 1 - 48
		{ 
			card_numbers_array[number] = number + 1; 
			number++;
		}  
		
		number = 0; 
		while(number < 100) // 100 times it "shuffles" the cards -- Actually is doing a simple swap
		{
			int temp_number; // Holds the number temporarily for the swap
			int x = rand()%48;  // Random number for array 0 - 47
			int y = rand()%48;  // Random number for part of array 0 - 47
			temp_number = card_numbers_array[x];
			card_numbers_array[x] = card_numbers_array[y];    // These three are the swaps
			card_numbers_array[y] = temp_number;
			number++; // Increases the variable that keeps the while loop going
		}

		// Writes numbers to file to check functionality
		ofstream out("array.txt");	
		number = 0;
		while(number < 48)
		{
			out << card_numbers_array[number] << endl; number++;
		}
		out.close();
	
	}
	if (recieve_cardscounter == 2)
	{
		player_name = "West";
	}
	if (recieve_cardscounter == 3)
	{
		player_name = "North";
	}
	if (recieve_cardscounter == 4)
	{
		player_name = "East";
	}

	number = 0;
	int card_numbers_array[48];
	ifstream in("array.txt");
	while(number < 48)	//&This gets the numbers from array.txt into the card_numbers_array[]
	{  
		in >> card_numbers_array[number]; 
		number++; 
	}
	in.close();	

	int min = 0, max = 12; // These are made for the initializations of card1 - card12
	if (recieve_cardscounter == 1)  // If the player recieving the cards is player -- array starts are [0], ends at [11]
	{
		min = 0;   max = 12;
	}

	if (recieve_cardscounter == 2) // If westplayer -- array starts at [12], ends at [23]
	{
		min = 12;  max = 24;
	}

	if (recieve_cardscounter == 3) // If northplayer -- starts at [24], ends at [35]
	{ 
		min = 24;  max = 36;
	}

	if (recieve_cardscounter == 4) // If eastplayer -- starts at [36], ends at [47]
	{
		min = 36;  max = 48;
	}
		
	card1 = card_numbers_array[min]; min++; 
	card2 = card_numbers_array[min]; min++;
	card3 = card_numbers_array[min]; min++;
	card4 = card_numbers_array[min]; min++;
	card5 = card_numbers_array[min]; min++;
	card6 = card_numbers_array[min]; min++;
	card7 = card_numbers_array[min]; min++;
	card8 = card_numbers_array[min]; min++;
	card9 = card_numbers_array[min]; min++;
	card10 = card_numbers_array[min]; min++;
	card11 = card_numbers_array[min]; min++;
	card12 = card_numbers_array[min]; min++;

	player play(card1, card2, card3, card4, card5, card6, card7, card8, card9, card10, card11, card12); 

	play.player_name = player_name;

	return play;
}
