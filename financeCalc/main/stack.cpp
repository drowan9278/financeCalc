#include "stack.h"
#include <iostream>
#include "structure1.h"
#include "menus.h"
using namespace std;


stack::stack()
{
}


stack::~stack()
{

}
bool stack::empty()
{
	bool value;
	if (!top)
	{
		value = true;
	}
	else
	{
		value = false;
	}
	return value;

}

void stack::push(string &term, string &acctId)
{
	node *newNode = nullptr;
	newNode = new node;
	newNode->acctName = acctId;
	newNode->term = term;

	if (empty())
	{
		top = newNode;
		newNode->next = nullptr;
	}
	else
	{
		newNode->next = top;
		top = newNode;
	}
}



void stack::pop()
{
	node *ptr;
	if (empty())
	{
		cout << "The stack does not have any values stored" << endl;
		return;
	}
	else
	{
		string acctId = top->acctName;
		string term = top->term;
		cout << " The value was found in " << acctId << "and the transaction was " << term;
		ptr = top->next;
		delete top;
		top = ptr;
	}
}
void stack::findTerm( string termSearch, vector<structure1::customer> &data)// Here is the search function it searches through all all accounts and finds
{                                                                           // all transactions that contains the string the user entered
	for(int x = 0; x< data.size();x++)
	{
		for(int y = 0; y<data[x].detail.history.size();y++)
		{
			if (data[x].detail.history[y].find(termSearch) != std::string::npos) {
				push(data[x].detail.history[y], data[x].name);
			}
		}

	}
	while(!empty())
	{
		pop();
	}
	menus main;
	main.mainMenu(data);
}


