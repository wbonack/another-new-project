#include "headers.h"

void trick::addtotrick(card & first, card & second, card & third, card & fourth)
{
	a = first, b = second, c = third, d = fourth;

}

trick::trick()
{
points = 0;
countpoints();
};

trick::trick(card a, card b, card c, card d)
{
	points = 0;
	trick::addtotrick(a, b, c, d);
	countpoints();

};

void trick::countpoints()
{
	if (a.power == 1 || a.power == 2 || a.power == 3)
	{
		points++;
	}
	if (b.power == 1 || b.power == 2 || b.power == 3)
	{
		points++;
	}
	if (c.power == 1 || c.power == 2 || c.power == 3)
	{
		points++;
	}
	if (d.power == 1 || d.power == 2 || d.power == 3)
	{
		points++;
	}
}

void trick::cards()
{
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
	cout << d << endl;
}
