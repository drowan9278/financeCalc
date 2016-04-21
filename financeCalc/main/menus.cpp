#include "menus.h"
#include <string>
#include <iostream>
#include <ctime>
#include "structure1.h"
using namespace std;


menus::menus()
{
}


menus::~menus()
{
}
void grabStructDataFirst(int x)/*We would use this to grab account information for either a new account or new customer*/
{
	structure1 data;
	for (int y = 0; y < x;y++)/*to go the point in the memory where the specified structure is*/
	{
		data.accounts++;
	}
	cout << "Please enter the account type" << endl;
	cin >> data.accounts->type;
	cout << "Please enter the credit or debit you will be adding" << endl;
	float holder;
	cin >> holder;
	data.accounts->detail.balance += holder;
	cout << "Please enter a description for the balance" << endl;
	string desc;
	cin >> desc;
	time_t current = time(0);
	char* dt = ctime(&current);
	cout << dt;
	int count = 0;
	string newDesc = desc + " **Cr/Db = " + to_string(holder) + " ** Time of transaction: " + dt;
	data.accounts->detail.history.push_back(newDesc);/*This will add the description the amount and time current time and then 
													 will be added to the history vector*/
	
}