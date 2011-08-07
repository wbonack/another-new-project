#include "headers.h"
#include "scoreclass.h"
class finalscore : public scoring{ // Sweet way to combine classes into objects
public:
	int to25counter;  // & What is this -- it needs a better name
	int player, west, north, east; // & The four players
	finalscore();
};
	finalscore::finalscore():
	player(0), west(0), north(0), east(0),
	to25counter(0)
		{};

void finalscoring(alltrick & all, scoreclass & scr)
{
	cout << "Finalscoring! " << endl;
	finalscore final;
	void getscores(trick & a, finalscore & final);

	getscores(all.a, final);
	getscores(all.b, final);
	getscores(all.c, final);
	getscores(all.d, final);
	getscores(all.e, final);
	getscores(all.f, final);
	getscores(all.g, final);
	getscores(all.h, final);
	getscores(all.i, final);
	getscores(all.j, final);
	getscores(all.k, final);
	getscores(all.l, final);
	final.to25counter += all.a.points;
	final.to25counter += all.b.points;
	final.to25counter += all.c.points;
	final.to25counter += all.d.points;
	final.to25counter += all.e.points;
	final.to25counter += all.f.points;
	final.to25counter += all.g.points;
	final.to25counter += all.h.points;
	final.to25counter += all.i.points;
	final.to25counter += all.j.points;
	final.to25counter += all.k.points;
	final.to25counter += all.l.points;
	
	cout << "Player got: " << final.player<< endl;
	cout << "West got : " << final.west<< endl;
	cout << "North got : " << final.north<< endl;
	cout << "East got : " << final.east << endl;
	cout << "scr.accessplayer() is: " << scr.accessplayer() << endl;
	//cout << final.to25counter << endl;  //. This used to prove that 25 points were being counded
	scr.accessplayer(final.player + scr.accessplayer());
	cout << "Final.player is: " << final.player << endl;
	cout << "scr.accessplayer() is: " << scr.accessplayer() << endl;
	
	scr.accesswest(final.west + scr.accesswest());
	scr.accessnorth(final.north + scr.accessnorth());
	scr.accesseast(final.east + scr.accesseast());
}

void getscores(trick & a, finalscore & final)
{
	if (a.nametrickwinner == "Player") {final.player += a.points; };
	if (a.nametrickwinner == "West") { final.west += a.points;} ;
	if (a.nametrickwinner == "North") { final.north += a.points;} ;
	if (a.nametrickwinner == "East") { final.east += a.points;} ;
}
