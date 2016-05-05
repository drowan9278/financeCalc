#include "menus.h"
#include <string>
#include <iostream>
#include <ctime>
#include "structure1.h"
#include "dataManip.h"
#include <stdlib.h>

using namespace std;

dataManip backup;
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
	system("CLS");//windows only control, don't run on mac/unix
	cout <<flush<< "\t\t\tPERSONAL FINANCE CALCULATOR\n\n\t\t\t\tMAIN MENU\n\nPlease make a choice:\n" << endl;
	cout << "0 - Add a new account\n1 - Modify an existing account\n2 - View account summary\n3 - View historical transactions\n4 - Search for transactions\n5 - Save & Exit\n6 - Restore from Backup\n" << endl;
	
	while (true) //loop "infinitely" until break statement is reached
	{
		int id = -1;
		int answer;
		cin.exceptions(istream::failbit);
		try {
			cin >> answer;
			}
		catch(ios_base::failure &fail){
			cout << "ERROR:Bad Value, numbers only, Enter a integer" << endl;
			cin.clear();
			string tmp;
			getline(cin, tmp);
		}
		
		switch (answer)
		{
			case 0:
				addAccount(data);
				break;
			case 1:
				 id=grabAccountId(data);
				if(id==-1)
				{
					cout << "ERROR:Account Not Found" << endl;
				}
				else {
					modifyExistData(id, data);
				}
				break;
			case 2:
				id = grabAccountId(data);
				if (id == -1)
				{
					cout << "ERROR: Account Not Found" << endl;
				}
				else
				{
					getInfoAccount(id, data);
				}
				break;
			case 3:
				id = grabAccountId(data);
				if(id==-1)
				{
					cout << "ERROR: Account Not Found" << endl;
					continue;
				}
				else
				{
					getTransactions(id, data);
				}
				break;
			case 4:
				break;
			case 5:
				backup.Backup(data);
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

void menus::modifyExistData(int x, vector<structure1::customer>& data)/*Use this to modify an existing account (just removed the type of account)*/
{
	system("CLS");//windows only control, don't run on mac/unix
	string yn;
	int count = 0;
	while (true)
	{
		cout << "\nPlease enter the credit or debit (positive or negative numbers only)\n that you will be adding to " << data[x].name << ":" << endl;
		float holder;
		while (true)
		{
			try {
				cin >> holder;
				break;
			}
			catch (ios_base::failure &fail) {
				cout << "ERROR: Bad Value, numbers only, Enter a integer" << endl;
				cin.clear();
				string tmp;
				getline(cin, tmp);
			}
			count++;
			if (count == 3)
			{
				mainMenu(data);
				break;
			}
		}
		data[x].detail.balance += holder;
		cout << "Please add a description for this entry: " << endl;
		string desc;
		cin.ignore(1000, '\n');
		getline(cin, desc);
		time_t current = time(0);
		char* dt = ctime(&current);
		int count = 0;
		string newDesc = desc + " **Cr/Db = " + to_string(holder) + " ** Time of transaction: " + dt;
		data[x].detail.history.push_back(newDesc);/*This will add the description the amount and time current time and then
											  will be added to the history vector*/
		while (true)
		{
			cout << "\nWould you like to add another entry?(Y or N) " << endl;
			cin >> yn;
			if (yn == "Y" || yn == "y")//changed this to string so no need to add a try catch block -DR
			{
				modifyExistData(x, data);
			}
			else if (yn == "N" || yn == "n")
			{
				cout << "Now exiting to Main Menu...\n" << endl;
				mainMenu(data);
			}
			else
				continue;

		}
	}
}
void menus::addAccount(vector<structure1::customer>& data1)
{
	system("CLS");//windows only control, don't run on mac/unix
	structure1::customer data;
	
	string tempPIN;
	bool matchedPIN = false;
	int x = sizeof(data);
	cout << "\nWould you like to add an account? (Y or N)" << endl;
	while (true) //loops until break statement reached
	{
		string yn;
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
				cout << "Please enter a unique password for this account: " << endl;
				cin.ignore(1000, '\n');
				getline(cin, tempPIN);
				for (int i = 0; i < sizeof(data); i++)
				{
					if (data.detail.pin == tempPIN)
						matchedPIN = true;
				}
				if (!matchedPIN)
					data.detail.pin = tempPIN;
			} while (matchedPIN);
			cout << "\nYour password is : " << data.detail.pin << "\n\tDO NOT FORGET YOUR PASSWORD!\n\t\tIT IS THE ONLY WAY TO ACCESS YOUR ACCOUNT!\n" << endl;
			
			data.vectorID=size(data1);
			data1.push_back(data);
			while (true)
			{
				cout << "Would you like to add any transactions to this account? (Y or N)" << endl;

				cin >> yn;
				if (yn == "Y" || yn == "y")
				{
					modifyExistData(data.vectorID, data1);
					break;
				}
				else if (yn == "N" || yn == "n")
					break;
			}
			//intentional fallthrough
		case 'N':
		case 'n':
			cout << "Now exiting to Main Menu...\n" << endl;
			mainMenu(data1);
			
			break;

		default:
			cout << "\nYou have entered an invalid response!" << endl;;
			cout << "\nWould you like to add an account? (Y or N)" <<endl;
			continue; //jumps to top of loop
		}
		break; //breaks out of loop only when valid response is recieved
	}


	
}
void menus::getInfoAccount(int x, vector<structure1::customer>& data)
{
	system("CLS");//windows only control, don't run on mac/unix
	cout << "\n\n\t\t" << data[x].name << endl;
	cout << "Type: ";
	if (data[x].type == 'c' || data[x].type == 'C')
		cout << "Checking" << endl;
	else
		cout << "Savings" << endl;
	cout << "Current balance: " << data[x].detail.balance << endl;
	cout << "Would you like to view transaction history? (Y or N)" << endl;
	string yn;
	cin >> yn;
	if (yn == "Y" || yn == "y")
		getTransactions(x, data);
	mainMenu(data);
}

void menus::getTransactions(int x, vector<structure1::customer>& data)
{
	system("CLS");//windows only control, don't run on mac/unix
	cout << "History of all transactions are below for " << data[x].name << endl;
	cout << "***************************************" << endl;
	for (int index = 0; index<data[x].detail.history.size(); index++)
	{
		cout << data[x].detail.history[index] << endl;
	}
	cout << "*****************************************" << endl;
	cout << "END OF HISTORY" << endl;
	//system("pause");
	cout << "Press ENTER to continue...";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin.get();
	//better way to do this than making a system call
	mainMenu(data);
}

void menus::searchTransactions(int x, vector<structure1::customer>& data)
{

	system("CLS");
	cout << "Here is all search transcations details..... " << data[x].name << endl;
	cout << "***************************************" << endl;
	for (int index = 0; index<data[x].detail.history.size(); index++)
	{
		cout << data[x].detail.history[index] << endl;
	}
	cout << "*****************************************" << endl;
	cout << "END OF TRANSACTIONS" << endl;
	//system("pause");
	cout << "Press ENTER to continue...";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin.get();
	//better way to do this than making a system call
	mainMenu(data);
}



int menus::grabAccountId(vector<structure1::customer>& data)
{
	system("CLS");//windows only control, don't run on mac/unix
	cout << "Please enter your password to access your account" << endl;
	string pin;
	cin.ignore(1000, '\n');
	getline(cin, pin);
	int vectId=-1;//This makes it so if wrong pin is entered it loops to back menu
	for(int x = 0;x<data.size();x++)
	{
		if(pin==data[x].detail.pin)
		{
			vectId = data[x].vectorID;//This allow to grab the user vector id
		}
	}
	
	return vectId;
}

