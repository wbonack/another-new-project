#include "scoreclass.h"

#include "headers.h"
#include <iostream>

scoreclass::scoreclass()
{
	player = 0, west = 0, north = 0, east = 0;
	combinescores();
};

void scoreclass::combinescores()
{
	team1 = player + north;
	team2 = west + east;
	oldteam1(counter, player + north); 
	oldteam2(counter, west + east);
}

int scoreclass::oldteam1(int a)
{
	return team1old[a-1];
}
int scoreclass::oldteam2(int b)
{
	return team2old[b-1];
}

void scoreclass::oldteam1(int a, int b)
{
	if (a < 1 || a > 10) {}
	else {  team1old[a-1] = b;}
}

void scoreclass::oldteam2(int a, int b)
{   
	if (a < 1 || a > 10) {}
	else {  team2old[a-1] = b;}
}

void scoreclass::scoreboard()
{
	line();
	combinescores();
	std::cout << "Scores " << std::endl << std::endl;
	std::cout << "Team1 : " << scoreteam1() << std::endl;
	std::cout << "Team2 : " << scoreteam2() << std::endl;
}

