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

void menus::mainMenu(vector<structure1::customer>& data) //Main menu to access all other menus
{
	/*switch
	0-add an account
	1-modify account
	2-view historical transactions
	3-view account summary
	4-search for transactions
	5-save and exit
	6-restore from backup
	*//**/
	cout << "\t\t\tPERSONAL FINANCE CALCULATOR\n\n\t\t\t\tMAIN MENU\n\nPlease make a choice:\n" << endl;
	cout << "0 - Add a new account\n1 - Modify an existing account\n2 - View historical transactions\n3 - View account summary\n4 - Search for transactions\n5 - Backup & Restore Data\n6 - Save & Exit\n" << endl;
	
	while (true) //loop "infinitely" until break statement is reached
	{
		int answer;
		cin >> answer;
		
		switch (answer)
		{
			case 0:
				addAccount(data);
				break;
			case 1:
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
				break;
			case 6:
				break;
			default:
				cout << "\n\tINVALID RESPONSE RECIEVED\n\n";
				cout << "\t\t\tPERSONAL FINANCE CALCULATOR\n\n\t\t\t\tMAIN MENU\n\nPlease make a choice:\n" << endl;
				cout << "0 - Add a new account\n1 - Modify an existing account\n2 - View historical transactions\n3 - View account summary\n4 - Search for transactions\n5 - Backup & Restore Data\n6 - Save & Exit\n" << endl;
				continue; //skips rest of loop and returns to beginning
		}
		break;//breaks out of loop once valid response recieved
	}

}

void menus::modifyExistData(int x, vector<structure1::customer>& data)/*Use this to modify an existing accout (just removed the type of account)*/
{
	bool whilBrk = true;
	char yn;
	while (whilBrk)
	{
		cout << "Please enter the credit or debit you will be adding to " << data[x].name << ":" << endl;
		float holder;
		cin >> holder;
		data[x].detail.balance += holder;
		cout << "Please add a description for this entry: " << endl;
		string desc;
		cin.ignore(1000, '\n');
		getline(cin, desc);
		time_t current = time(0);
		char* dt = ctime(&current);
		cout << dt;
		int count = 0;
		string newDesc = desc + " **Cr/Db = " + to_string(holder) + " ** Time of transaction: " + dt;
		data[x].detail.history.push_back(newDesc);/*This will add the description the amount and time current time and then
											  will be added to the history vector*/
		cout << "Would you like to add another entry?(Y or N) " << endl;
		cin >> yn;
		if(yn=='Y'||yn=='y')
		{
			modifyExistData(x, data);
		}
		else
		{
			cout << "Now exiting to Main Menu" << endl;
			whilBrk = false;
		}


	}
}
void menus::addAccount(vector<structure1::customer>& data1)
{
	structure1::customer data;
	
	string tempPIN;
	bool matchedPIN = false;
	int x = sizeof(data);
	cout << "\nWould you like to add an account? (Y or N)" << endl;
	while (true) //loops until break statement reached
	{
		char answer;
		cin.ignore(1000, '\n');
		cin >> answer;
		switch (answer)
		{
		case 'Y':
		case 'y':
			
			x = sizeof(data);
			cout << "Please enter the account name: " << endl;
			cin.ignore(1000, '\n');
			getline(cin, data.name);
			char cs;
			do {
				cout << "Please enter the account type (C for checking, S for savings: )" << endl;
				cin >> cs;
			} while (!(cs == 'C' || cs == 'c') && !(cs == 'S' || cs == 's'));
			data.type = cs;
			do
			{
				cout << "Please enter a unique PIN for this account: " << endl;
				cin >> tempPIN;
				for (int i = 0; i < sizeof(data); i++)
				{
					if (data.detail.pin == tempPIN)
						matchedPIN = true;
				}
				if (!matchedPIN)
					data.detail.pin = tempPIN;
			} while (matchedPIN);
			cout << "\nYour PIN is : " << data.detail.pin << "\n\tDO NOT FORGET YOUR PIN!\n\t\tIT IS THE ONLY WAY TO ACCESS YOUR ACCOUNT!\n" << endl;
			
			data.vectorID=size(data1);
			data1.push_back(data);
			modifyExistData(data.vectorID, data1);
			break;
		case 'N':
		case 'n':
			/*mainMenu(data1);*/
			return;
			break;

		default:
			cout << "\nYou have entered an invalid response!:" << endl;;
			cout << "\nWould you like to add an account? (Y or N)";
			continue; //jumps to top of loop
		}
		break; //breaks out of loop only when valid response is recieved
	}


	
}
void menus::getInfoAccount(int x, vector<structure1::customer>& data)
{
	cout << "\n\n\t\t" << data[x].name << endl;
	cout << "Type: ";
	if (data[x].type == 'c' || data[x].type == 'C')
		cout << "Checking" << endl;
	else
		cout << "Savings" << endl;
	cout << "Current balance: " << data[x].detail.balance << endl;

}


