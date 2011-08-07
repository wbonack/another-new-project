int finddealer(int * whoptr, string *);

player recieve_cards(int &);
//located in recieve_cards

void saythecards(string,string,string,string,string,string,string, string,string,string,string,string,string *, string *,
	string * , string * , string * , string * , string *,string * , string *, string *, string *, string * , bool, player * ); 

	void cardnumbers(int card1, int card2, int card3, int card4, int card5, int card6, int card7, int, int, int, int, int);

	void scoring_func(int *, int * , int *, int *, int*, int*, int *, int *,player *, player *, player *, player *);

	void bid(string, string, string,int *,int *,bool *,int * ,int,int,int,bool*,bool*,bool*,bool*, bool*,bool * , bool *, bool *,
		int *, string *, int*, player); 
	//This is located in .cpp

	void playersuits(string *, string *, string *, int, int, int, int, int, int, int,int, int,int,int, int);

	void passing(string winner, string * c1, string * c2, string * c3, string * c4, int* passed1, int* passed2,int* passed3,int* 		passed4, int* pass1, int* pass2, int* pass3, int* pass4, player * nplay, player * wplay, player * eplay, string suitname, bool * firsttime, player * play);

	void cardschangehands(string, int *, int *, int *, int *, int *, int *, int *, int *,  player *, player *, player *, player *);

	void play_hand(string, string, player &, player &, player &, player &, alltrick &, int);

	void error();
	void finalscoring(alltrick &, scoreclass & scr);
