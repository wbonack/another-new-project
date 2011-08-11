#include <string>
using namespace std;
#include <iostream>
class player;
class suit // This replaced 4 classes I made earlier!!
{
	string nameofsuit;
	public:
	int ace1;
	int ace2;
	int ten1;
	int ten2;
	int king1;
	int king2;
	int queen1;
	int queen2;
	int jack1;
	int jack2;
	int nine1;
	int nine2;

	bool ace1bool;
	bool ace2bool;
	bool ten1bool;
	bool ten2bool;
	bool king1bool;
	bool king2bool;
	bool queen1bool;
	bool queen2bool;
	bool jack1bool;
	bool jack2bool;
	bool nine1bool;
	bool nine2bool;

	std::string acename;
	std::string tenname;
	std::string kingname;
	std::string queenname;
	std::string jackname;
	std::string ninename;

	int howmanyofsuit(player & play);

	suit();
	suit(string suitname);

};

class scoring
{
public:
	int aces_around;
	int double_aces_around;
	int kings_around;
	int double_kings_around;
	int queens_around;
	int double_queens_around;
	int jacks_around;
	int double_jacks_around;
	int marriage;
	int marriage_in_trump;
	int marriages_around;
	int double_marriage;
	int book;
	int double_book;
	int pinochle;
	int double_pinochle;
	bool acesaround;
	bool doubleacesaround;
	bool kingsaround;
	bool doublekingsaround;
	bool queensaround;
	bool doublequeensaround;
	bool jacksaround;
	bool doublejacksaround;
	bool marriagebool;
	bool marriageintrump;
	bool marriagesaround;
	bool doublemarriage;
	bool bookbool;
	bool doublebook;
	bool pinochlebool;
	bool doublepinochle;
	int score;
	
	scoring();

};
class hand: public suit// Most useless class ever -- Used however in a class -- This is also the name of a cpp file....
{
public:
	suit heart;
	suit diamond;
	suit club;
	suit spade;
	hand();
};

class card
{
public:
	hand h;
	std::string name;
	int suitnumber, order, secondsuit;
	int orderplayed;
	int power, number;
	bool played, trump;
	int suittofollow;
	card whichwins(card &, card &, card &, card &); // Check this-- It might be broken
	card(int);
	card();
	void istrump(int); 
	void fixorder(card &, card &, card &, card &, card &, card &, card &, card &, card &, card &, card &, card &);
	friend ostream &operator<<(ostream &os, card & c); //This makes me able to print it out to the screen 
	bool operator ==(const card a){ return(a.number == number);}
	bool operator <=(const card &a);
};

class player // & This should be documented so that the programmer understands all the functions of it 
	// & This looks a bit lazy in that their are mostly public declarations and not many private/protected
{
public:
	int card1, card2, card3, card4, card5,card6,card7,card8, card9,card10,card11,card12;
	
	int * card1ptr; int * card2ptr; int * card3ptr; int * card4ptr;
	int * card5ptr; int * card6ptr; int * card7ptr; int * card8ptr;
	int * card9ptr; int * card10ptr; int * card11ptr; int * card12ptr;

	int ord1,ord2,ord3,ord4,ord5,ord6,ord7,ord8,ord9,ord10,ord11,ord12;
	string order1, order2, order3, order4, order5, order6, order7, order8, order9, order10, order11, order12;

	int * c1;
	int * c2;

	void cardnames();

	card first1, second1, third1, fourth1, fifth1, sixth1, seventh1, eight1, ninth1, tenth1, eleventh1, twelth1;

	int howmanyhearts;
	int howmanydiamonds;
	int howmanyspades;
	int howmanyclubs;

	int choice;

	std::string name1,name2,name3,name4,name5,name6,name7,name8,name9,name10,name11,name12;

	string * name1ptr; string * name2ptr; string * name3ptr; string * name4ptr; string * name5ptr; string * name6ptr; 
	string * name7ptr; string * name8ptr; string * name9ptr; string * name10ptr; string * name11ptr; string * name12ptr;

	player();
	player(int, int, int, int, int,int, int, int, int, int ,int, int);
	void change(); // Used in passing.cpp in function cards_change_hands
	void order(string, string, string, string, string, string, string, string, string, string, string, string);
	void convert();
	void saycards();
	void cardpersuit();
	void temporaryhack(); 
	void getorder();

private:
	bool order1true, order2true, order3true, order4true, order5true, order6true, order7true, order8true, order9true, order10true,order11true, order12true;
};

class trick
{
public:
	bool istopbidder;
	int points;
	card trickwinner;
	string nametrickwinner;
	card a, b, c, d;
	trick();
	trick(card, card, card, card);  // This declaration makes everything work.
	void cards();
		
private:
void countpoints();
void addtotrick(card & a, card &, card &, card &);

};

class alltrick
{
public:
	trick a, b, c, d, e, f, g, h, i, j, k, l;
	
	alltrick();
	alltrick(trick, trick, trick, trick, trick, trick, trick, trick, trick, trick, trick, trick);
};



