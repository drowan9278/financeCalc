// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "menus.h"
#include "structure1.h"
#include <iostream>
using namespace std;
/*This will be the main file, please add initials after all code editing in a comment-DR*/



int main()
{
	structure1 obj;
	vector<structure1::customer> accounts =  vector<structure1::customer>();
	menus menuObj;
	obj.accounts.resize(sizeof(obj.accounts) + 1);
	int x = sizeof(obj.accounts);
	
	
	 menuObj.grabStructDataFirst(x, obj.accounts);
	 cout << obj.accounts[x].detail.history[0] << "it workedddd" << endl;
	return 0;
}

