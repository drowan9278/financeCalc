// dynQuene.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "quene.h"
#include <iostream>
using namespace std;

int main()
{
	quene obj;
	bool cont = true;
	do
	{
		cout << "Please enter your values to add to the quene or -1 to quit" << endl;
		int hold;
		cin >> hold;
		if(hold == -1)
		{
			cont = false;
		}
		else 
			obj.addQue(hold);
	} while (cont);
	cout << "The quene consists of: " << endl;
	while(!obj.empty())
	{
		int value;
		obj.delQue(value);
		cout << value << " ";
	}
	obj.clear();
	return 0;
}

