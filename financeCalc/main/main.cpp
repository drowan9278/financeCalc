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
	menus accountMenus;
	//int x = accountMenus.addAccount(accounts);
	accountMenus.mainMenu(accounts);
	vector<structure1::customer>* accountPtr = &accounts;
	
	//cout << accounts[x].detail.history[x];
	return 0;
}

