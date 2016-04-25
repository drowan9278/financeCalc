// timeFormat.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;


string timeSet();

int main()
{
	try {
		string  time = timeSet();
		cout << "The time is: " << time << endl;
	}
	catch(string Wrong){
		cout << Wrong;
	}
	
	return 0;
}

string timeSet()
{
	int x, y;
	cout << "Enter the hour in the military time" << endl;
	int hold;
	cin >> hold;
	if(hold>-1 && hold<2359)
	{
		x = hold;
	}
	else
	{
		string wrongHour = "You entered the wrong hour";
		throw wrongHour;
	}
	cout << "Now enter the seconds military time" << endl;
	cin >> hold;
	if (hold < 0 || hold>60)
	{
		string secWrong = "You enter the wrong amount of seconds";
		throw secWrong;
	}
	else
		y = hold;
	string time = to_string(x) + "Hour  and seconds are: " + to_string(y);

	return time;
}

