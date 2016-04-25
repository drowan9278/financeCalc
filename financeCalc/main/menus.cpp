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

void menus::grabStructDataFirst(int x, vector<structure1::customer>& data)/*We would use this to grab account information for either a new account or new customer*/
{
	cout << "Please enter the account type" << endl;
	cin >> data[x].type;
	cout << "Please enter the credit or debit you will be adding" << endl;
	float holder;
	cin >> holder;
	data[x].detail.balance += holder;
	cout << "Please enter a description for the balance" << endl;
	string desc;
	cin >> desc;
	time_t current = time(0);
	char* dt = ctime(&current);
	cout << dt;
	int count = 0;
	string newDesc = desc + " **Cr/Db = " + to_string(holder) + " ** Time of transaction: " + dt;
	data[x].detail.history.push_back(newDesc);/*This will add the description the amount and time current time and then 
													 will be added to the history vector*/
}

void menus::modifyExistData(int x, vector<structure1::customer>& data)/*Use this to modify an existing accout (just removed the type of account)*/
{
	cout << "Please enter the credit or debit you will be adding to "<< data[x].type <<" account"<< endl;
	float holder;
	cin >> holder;
	data[x].detail.balance += holder;
	cout << "Please enter a description for the balance" << endl;
	string desc;
	cin >> desc;
	time_t current = time(0);
	char* dt = ctime(&current);
	cout << dt;
	int count = 0;
	string newDesc = desc + " **Cr/Db = " + to_string(holder) + " ** Time of transaction: " + dt;
	data[x].detail.history.push_back(newDesc);/*This will add the description the amount and time current time and then
											  will be added to the history vector*/
}
int menus::addAccount(vector<structure1::customer>& data)
{
	
	cout << "Would you like to add an account? (Y or N" << endl;
	char answer;
	cin >> answer;
	data.resize((sizeof(data)+1));
	int x = sizeof(data);
	return x;
	
	
}
void menus::getInfoAccount()
{
	
}


