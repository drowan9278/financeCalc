// employProd.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "prodWorker.h"
#include <iostream>
using namespace std;

int main()
{
	prodWorker worker;
	cout << "Please enter the name" << endl;
	string hold;
	cin >> hold;
	worker.setName(hold);

	cout << "Please enter the ID" << endl;

	int holdInt;

	cin >> holdInt;
	try {
		worker.setID(holdInt);
	}
	catch(string x)
	{
		cout << x<<endl;
	}
	double holdDouble;

	cout << "Please enter the pay rate" << endl;
	cin >> holdDouble;
	try {
		worker.setPay(holdDouble);
	}
	catch(string x)
	{
		cout << x << endl;
	}

	cout << "Please enter the date" << endl;
	cin >> hold;
	worker.setDate(hold);

	cout << "Please enter 1 for Day and 2 for Night" << endl;
	cin >> hold;
	try {
		worker.setShift(hold);
	}
	catch(string x)
	{
		cout << x << endl;
	}

	string x = worker.getName();
	return 0;
}

