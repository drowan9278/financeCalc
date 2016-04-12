// stringQuene.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "quene2.h"
using namespace std;


int main()
{
	quene2 obj;
	bool cont = true;
	do
	{
		cout << "Please enter your values to add to the quene or x to quit" << endl;
		string hold;
		cin >> hold;
		if (hold == "x")
		{
			cont = false;
		}
		else
			obj.addQue(hold);
	} while (cont);
	cout << "The quene consists of: " << endl;
	while (!obj.empty())
	{
		string value;
		obj.delQue(value);
		cout << value << " ";
	}
	obj.clear();
	return 0;
}







