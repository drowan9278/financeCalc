#include "stack.h"
#include <iostream>
#include "structure1.h"
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
void stack::pop(string &term, string &acctId)
{
	node *ptr;
	if (empty())
	{
		cout << "The stack does not have any values stored" << endl;
		return;
	}
	else
	{
		acctId = top->acctName;
		term = top->term;
		ptr = top->next;
		delete top;
		top = ptr;
	}
}
void stack::findTerm( string termSearch, vector<structure1::customer> &data)
{
	for(int x = 0; x< data.size();x++)
	{
		for(int y = 0; y<data[x].detail.history.size();y++)
		{
			if (data[x].detail.history[y].find(termSearch) != std::string::npos) {
				push(data[x].detail.history[y], data[x].name);
			}
		}

	}



}


