class scoreclass
{
	int player, west, north, east, team1, team2, team1old[50], team2old[50];
	void combinescores();

public:
	int accessplayer(){return player;}
	int accesswest(){return west;}
	int accessnorth(){return north;}
	int accesseast(){return east;}
	void accessplayer(int a){player = a;}
	void accesswest(int a){west = a;}
	void accessnorth(int a){north = a;}
	void accesseast(int a){east = a;}
	int scoreteam1(){return team1;}
	int scoreteam2(){return team2;}
	int oldteam1(int a);
	int oldteam2(int a);
	void oldteam1(int a, int b);
	void oldteam2(int b, int a);
	int counter;
	void scoreboard();

	scoreclass();
};

/*  Explanation of how to use this class.
	scoreclass:
		The access without arguments return the value of the player.
		Access with arguments changes the value to that of the argument
		Scoreteam returns the value of team1 or 2
		oldteam with one argument accesses the team from the hand specified in the argument 
		oldteam with two arguments
*/
