#include "headers.h"
#include <fstream>
	card::card(){  };

	card::card(int card)
	{
		trump = false;
		suit heart("heart");
		if (card == heart.ace1) {h.heart.ace1bool = true; name = heart.acename; suitnumber = 1; played = false; power = 1; }
		if (card == heart.ace2) {h.heart.ace2bool = true; name = heart.acename; suitnumber = 1; played = false; power = 1;  }
		if (card == heart.ten1) {h.heart.ten1bool = true; name = heart.tenname; suitnumber = 1; played = false; power = 2;  }
		if (card == heart.ten2) {h.heart.ten2bool = true; name = heart.tenname; suitnumber = 1; played = false; power = 2;  }
		if (card == heart.king1) {h.heart.king1bool = true; name = heart.kingname; suitnumber = 1; played = false; power = 3;}
		if (card == heart.king2) {h.heart.king2bool = true; name = heart.kingname; suitnumber = 1; played = false; power = 3;}
		if (card == heart.queen1){h.heart.queen1bool = true; name = heart.queenname; suitnumber = 1; played = false; power = 4;}
		if (card == heart.queen2){h.heart.queen2bool = true; name = heart.queenname; suitnumber = 1; played = false; power = 4;}
		if (card == heart.jack1) {h.heart.jack1bool = true; name = heart.jackname; suitnumber = 1; played = false; power = 5;}
		if (card == heart.jack2) {h.heart.jack2bool = true; name = heart.jackname; suitnumber = 1; played = false; power = 5;}
		if (card == heart.nine1) {h.heart.nine1bool = true; name = heart.ninename; suitnumber = 1; played = false; power = 6;}
		if (card == heart.nine2) {h.heart.nine2bool = true; name = heart.ninename; suitnumber = 1; played = false; power = 6;}
		suit d("diamond");
		if (card == d.ace1) {h.diamond.ace1bool = true; name = d.acename; suitnumber = 2; played = false; power = 1;}
		if (card == d.ace2) {h.diamond.ace2bool = true; name = d.acename; suitnumber = 2; played = false; power = 1;}
		if (card == d.ten1) {h.diamond.ten1bool = true; name = d.tenname; suitnumber = 2; played = false; power = 2;}
		if (card == d.ten2) {h.diamond.ten2bool = true; name = d.tenname; suitnumber = 2; played = false; power = 2;}
		if (card == d.king1) {h.diamond.king1bool = true; name = d.kingname; suitnumber = 2; played = false; power = 3;}
		if (card == d.king2) {h.diamond.king2bool = true; name = d.kingname; suitnumber = 2; played = false; power = 3;}
		if (card == d.queen1) {h.diamond.queen1bool = true; name = d.queenname; suitnumber = 2; played = false; power = 4;}
		if (card == d.queen2) {h.diamond.queen2bool = true; name = d.queenname; suitnumber = 2; played = false; power = 4;}
		if (card == d.jack1) {h.diamond.jack1bool = true; name = d.jackname; suitnumber = 2; played = false; power = 5;}
		if (card == d.jack2) {h.diamond.jack2bool = true; name = d.jackname; suitnumber = 2; played = false; power = 5;}
		if (card == d.nine1) {h.diamond.nine1bool = true; name = d.ninename; suitnumber = 2; played = false; power = 6;}
		if (card == d.nine2) {h.diamond.nine2bool = true; name = d.ninename; suitnumber = 2; played = false; power = 6;}
		suit s("spades");
		if (card == s.ace1) {h.spade.ace1bool = true; name = s.acename; suitnumber = 3; played = false; power = 1;}
		if (card == s.ace2) {h.spade.ace2bool = true; name = s.acename; suitnumber = 3; played = false; power = 1;}
		if (card == s.ten1) {h.spade.ten1bool = true; name = s.tenname; suitnumber = 3; played = false; power = 2;}
		if (card == s.ten2) {h.spade.ten2bool = true; name = s.tenname; suitnumber = 3; played = false; power = 2;}
		if (card == s.king1) {h.spade.king1bool = true; name = s.kingname; suitnumber = 3;  power = 3;}
		if (card == s.king2) {h.spade.king2bool = true; name = s.kingname; suitnumber = 3;  power = 3;}
		if (card == s.queen1) {h.spade.queen1bool = true; name = s.queenname; suitnumber = 3;  power = 4;}
		if (card == s.queen2) {h.spade.queen2bool = true; name = s.queenname; suitnumber = 3;  power = 4;}
		if (card == s.jack1) {h.spade.jack1bool = true; name = s.jackname; suitnumber = 3;  power = 5;}
		if (card == s.jack2) {h.spade.jack2bool = true; name = s.jackname; suitnumber = 3;  power = 5;}
		if (card == s.nine1) {h.spade.nine1bool = true; name = s.ninename; suitnumber = 3;  power = 6;}
		if (card == s.nine2) {h.spade.nine2bool = true; name = s.ninename; suitnumber = 3;  power = 6;}
		suit c("Club");
		if (card == c.ace1) {h.club.ace1bool = true; name = c.acename; suitnumber = 4; power = 1;}
		if (card == c.ace2) {h.club.ace2bool = true; name = c.acename; suitnumber = 4; power = 1;}
		if (card == c.ten1) {h.club.ten1bool = true; name = c.tenname; suitnumber = 4; power = 2;}
		if (card == c.ten2) {h.club.ten2bool = true; name = c.tenname; suitnumber = 4; power = 2;}
		if (card == c.king1) {h.club.king1bool = true; name = c.kingname; suitnumber = 4; power = 3;}
		if (card == c.king2) {h.club.king2bool = true; name = c.kingname; suitnumber = 4; power = 3;}
		if (card == c.queen1) {h.club.queen1bool = true; name = c.queenname; suitnumber = 4; power = 4;}
		if (card == c.queen2) {h.club.queen2bool = true; name = c.queenname; suitnumber = 4; power = 4;}
		if (card == c.jack1) {h.club.jack1bool = true; name = c.jackname; suitnumber = 4; power = 5;}
		if (card == c.jack2) {h.club.jack2bool = true; name = c.jackname; suitnumber = 4; power = 5;}
		if (card == c.nine1) {h.club.nine1bool = true; name = c.ninename; suitnumber = 4; power = 6;}
		if (card == c.nine2) {h.club.nine2bool = true; name = c.ninename; suitnumber = 4; power = 6;}
		number = card; 
		played = false;
		
	};

	void card::fixorder(card & p1, card & p2, card & p3, card & p4, card & p5, card & p6, card & p7, card & p8, card & p9,
		card & p10, card & p11, card & p12)
	{
		int counter = 1, ordernumber = 1;
		for(;;)
		{
			if (counter == p1.number)
			{
				p1.order = ordernumber;
				ordernumber++;
			}

			if (counter == p2.number)
			{
				p2.order = ordernumber;
				ordernumber++;
			}

			if (counter == p3.number)
			{
				p3.order = ordernumber;
				ordernumber++;
			}

			if (counter == p4.number)
			{
				p4.order = ordernumber;
				ordernumber++;
			}

			if (counter == p5.number)
			{
				p5.order = ordernumber;
				ordernumber++;
			}

			if (counter == p6.number)
			{
				p6.order = ordernumber;
				ordernumber++;
			}

			if (counter == p7.number)
			{
				p7.order = ordernumber;
				ordernumber++;
			}

			if (counter == p8.number)
			{
				p8.order = ordernumber;
				ordernumber++;
			}

			if (counter == p9.number)
			{
				p9.order = ordernumber;
				ordernumber++;
			}

			if (counter == p10.number)
			{
				p10.order = ordernumber;
				ordernumber++;
			}

			if (counter == p11.number)
			{
				p11.order = ordernumber;
				ordernumber++;
			}

			if (counter == p12.number)
			{
				p12.order = ordernumber;
				ordernumber++;
			}

			counter++;
			if (counter >48) { break;}
		}
		
	}
	
	bool card::operator <=(const card &a)
	{
		bool suitisit = false;
		if (suittofollow == suitnumber)
		{	
			suitisit = true;
		}
		//  I finally finished the <= operator!  //& Not sure if this is true June 7th 2010

		if (suitisit && suitnumber != a.suitnumber && a.trump == false){return true;}

		if (power <= a.power && trump == true && a.trump == true && orderplayed < a.orderplayed){return true;}

		if (power <= a.power && suitnumber == a.suitnumber && orderplayed < a.orderplayed) { return true;}

		if (trump == true && a.trump == false) { return true;}

		if (suitnumber != a.suitnumber && trump == false && a.trump == false && suitisit == true) { return true;} 
	
		if (suitnumber == a.suitnumber && power < a.power ){return true;}
 
	return false;
	}  

	card card::whichwins(card & a, card & b, card & c, card & d)
	{
		card winningcard;
		bool aT[3] , bT[3] , cT[3] , dT[3] ;
		for(int x = 0;; )
		{
			aT[x] = false;
			bT[x] = false;
			cT[x] = false;
			dT[x] = false;
			x++;
			if (x>2) { break;}
		}
		
		if (a <= b) {aT[0] = true;}// cout << " A <= B " <<  endl;}
		if(a <= c) {aT[1] = true;}// cout << "A <= C" << endl;}
		if(a <= d) {aT[2] = true;}// cout << "A <= D" << endl;}
		
		if(aT[0] == true && aT[1] == true && aT[2] == true)
		{
			cout << "Winning card is Player!" << endl;
			winningcard = a;
		}
		
		if(b <= a) {bT[0] = true;}// cout << "B <= A" << endl;}
		if(b <= c) {bT[1] = true;}// cout << "B <= C" << endl;}
		if(b <= d) {bT[2] = true;}// cout << "B <= D" << endl;}
		
		if (bT[0] == true && bT[1] == true && bT[2] == true)
		{
			cout << "Winning card is West!" << endl;
			winningcard = b;
		}
		
		if (c <= b) {cT[0] = true;}// cout << "C <= B" << endl;}
		if(c <= a) {cT[1] = true;}// cout << "C <= A" << endl;}
		if(c <= d) {cT[2] = true;}// cout << "C <= D" << endl;}

		if (cT[0] == true && cT[1] == true && cT[2] == true)
		{
			cout << "Winning card is North!" << endl;
			winningcard = c;
		}
		
		if (d <= b) {dT[0] = true;}// cout << "D <= B" << endl;}
		if(d <= a) {dT[1] = true;}// cout << "D <= A" << endl;}
		if(d <= c) {dT[2] = true;}// cout << "D <= C" << endl;}
		

		if (dT[0] == true && dT[1] == true && dT[2] == true)
		{
			cout << "Winning card is East!" << endl;
			winningcard = d;
		}
		return winningcard;
	}

	void card::istrump(int suit) 
	{
		if (this->suitnumber == suit)
		{
		this->trump = true;
		}
	}
