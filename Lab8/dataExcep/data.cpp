#include "data.h"
#include <iostream>
#include <string.h>
using namespace std;


data::data()
{
}


data::~data()
{
}
void ::data::getDate()
{
	cout << "Please enter the month" << endl;
	int hold;
	cin >> hold;
	if(hold>0 && hold<13)
	{
		date.month = hold;
	}
	else
		throw wrongMonth(hold);
	cout << "Please enter the day " << endl;
	cin >> hold;
	if(hold<1 || hold>31)
	{
		throw wrongDay(hold);
	}
	else 
		date.day = hold;
	cout << "Please enter the year " << endl;
	cin >> date.year;
}
