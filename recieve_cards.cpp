#include "headers.h"

player recieve_cards(int & recieve_cardscounter)
{	
	int card1 = 0, card2 = 0, card3 = 0, card4 = 0,  card5 = 0,  card6 = 0, card7 = 0,  card8 = 0,  card9 = 0, card10 = 0,
		card11 = 0, card12 = 0;
	
	// Gets a random integer for the following loops
	/* initialize random seed: */  // & Found in hand.cpp after deal()
	srand_();

	// New Recieve_cards   // & Created and Finished this on June 10, 2010
	int tempx = 0; 

	if (recieve_cardscounter == 1) // This runs the first time recieve_cards is called and makes the deck.
	{
	int numbersarray[48]; // This has the 48 numbers for the cards thats will be randomized	-- This is only used in if statement
	while(tempx < 48) { numbersarray[tempx] = tempx + 1; tempx++;}  // This loop makes numberarray[] equal to 1 - 48
	
	tempx = 0; 
	while(tempx < 100) // 100 times it "shuffles" the cards -- Actually is doing a simple swap
	{
		int temp; // Holds the number temporarily for the swap
		int x = rand()%48;  // Random number for array 0 - 47
		int y = rand()%48;  // Random number for part of array 0 - 47
		temp = numbersarray[x];
		numbersarray[x] = numbersarray[y];    // These three are the swaps
		numbersarray[y] = temp;
		tempx++; // Increases the variable that keeps the while loop going
	}

	ofstream out("array.txt");	
	tempx = 0;
	while(tempx < 48)
	{
		out << numbersarray[tempx] << endl; tempx++;
	}
	out.close();

	}

	tempx = 0;
	int numberarray[48];
	ifstream in("array.txt");
	while(tempx < 48)	{  in >> numberarray[tempx]; tempx++; }//&This gets the numbers from array.txt into the numberarray[]
	in.close();	

	int temp = 0, max = 12; // These are made for the initializations of card1 - card12
	if (recieve_cardscounter == 1)  // If the player recieving the cards is player -- array starts are [0], ends at [11]
	{
		temp = 0;   max = 12;
	}

	if (recieve_cardscounter == 2) // If westplayer -- array starts at [12], ends at [23]
	{
		temp = 12;  max = 24;
	}

	if (recieve_cardscounter == 3) // If northplayer -- starts at [24], ends at [35]
	{ 
		temp = 24;  max = 36;
	}

	if (recieve_cardscounter == 4) // If eastplayer -- starts at [36], ends at [47]
	{
		temp = 36;  max = 48;
	}
		
	card1 = numberarray[temp]; temp++; 
	card2 = numberarray[temp]; temp++;
	card3 = numberarray[temp]; temp++;
	card4 = numberarray[temp]; temp++;
	card5 = numberarray[temp]; temp++;
	card6 = numberarray[temp]; temp++;
	card7 = numberarray[temp]; temp++;
	card8 = numberarray[temp]; temp++;
	card9 = numberarray[temp]; temp++;
	card10 = numberarray[temp]; temp++;
	card11 = numberarray[temp]; temp++;
	card12 = numberarray[temp]; temp++;

	string whatiscard1(int *); // This is right below the end of this function.

player play(card1, card2, card3, card4, card5, card6, card7, card8, card9, card10, card11, card12); 
		
	play.name1 = whatiscard1(&card1);
	play.name2 = whatiscard1(&card2);
	play.name3 = whatiscard1(&card3);
	play.name4 = whatiscard1(&card4);
	play.name5 = whatiscard1(&card5);
	play.name6 = whatiscard1(&card6);
	play.name7 = whatiscard1(&card7);
	play.name8 = whatiscard1(&card8);
	play.name9 = whatiscard1(&card9);
	play.name10 = whatiscard1(&card10);
	play.name11 = whatiscard1(&card11);
	play.name12 = whatiscard1(&card12);

recieve_cardscounter++;
return play;
}

string whatiscard1(int * card1ptr) ///Make sure to return a string -- This is called in recieve_cards.cpp 
{
	suit heart("heart");
	suit diamond("diamond");
	suit spade("spade");
	suit club("club");
	
	if (*card1ptr == heart.ace1||*card1ptr == heart.ace2){	return "Ace of hearts" ;}
	if (*card1ptr == heart.ten1||*card1ptr == heart.ten2){ return "Ten of hearts" ;}
	if (*card1ptr == heart.king1||*card1ptr == heart.king2){ return "King of hearts" ;}
	if (*card1ptr == heart.queen1||*card1ptr == heart.queen2){ return "Queen of hearts" ;}
	if (*card1ptr == heart.jack1||*card1ptr == heart.jack2){ return "Jack of hearts" ;}
	if (*card1ptr == heart.nine1||*card1ptr == heart.nine2){ return "Nine of hearts" ;}
	if (*card1ptr == diamond.ace1||*card1ptr == diamond.ace2){	return "Ace of diamonds" ;}	
	if (*card1ptr == diamond.ten1||*card1ptr == diamond.ten2){ 	return "Ten of diamonds" ;}
	if (*card1ptr == diamond.king1||*card1ptr == diamond.king2){ 	return "King of diamonds" ;}
	if (*card1ptr == diamond.queen1||*card1ptr == diamond.queen2){ 	return "Queen of diamonds" ;}
	if (*card1ptr == diamond.jack1||*card1ptr == diamond.jack2){ 	return "Jack of diamonds" ;}
	if (*card1ptr == diamond.nine1||*card1ptr == diamond.nine2){ 	return "Nine of diamonds" ;}
	if (*card1ptr == spade.ace1||*card1ptr == spade.ace2){	return "Ace of spades" ;}	
	if (*card1ptr == spade.ten1||*card1ptr == spade.ten2){ 	return "Ten of spades" ;}
	if (*card1ptr == spade.king1||*card1ptr == spade.king2){ return "King of spades" ;}
	if (*card1ptr == spade.queen1||*card1ptr == spade.queen2){ return "Queen of spades" ;}
	if (*card1ptr == spade.jack1||*card1ptr == spade.jack2){ return "Jack of spades" ;}
	if (*card1ptr == spade.nine1||*card1ptr == spade.nine2){ return "Nine of spades" ;}
	if (*card1ptr == club.ace1||*card1ptr == club.ace2){ return "Ace of clubs" ;}
	if (*card1ptr == club.ten1||*card1ptr == club.ten2){ 	return "Ten of clubs" ;}
	if (*card1ptr == club.king1||*card1ptr == club.king2){ 	return "King of clubs" ;}
	if (*card1ptr == club.queen1||*card1ptr == club.queen2){ return "Queen of clubs" ;}
	if (*card1ptr == club.jack1||*card1ptr == club.jack2){ 	return "Jack of clubs" ;}
	if (*card1ptr == club.nine1||*card1ptr == club.nine2){ 	return "Nine of clubs" ;}

	if (*card1ptr > 48 || *card1ptr <1){  return "error";}
	else 
	{	
		return "error";
	}
}
