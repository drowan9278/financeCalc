

#ifndef DYNINTSTACK_H
#define DYNINTSTACK_H
#include <string>
#include <iostream>
#include "structure1.h"
using namespace std;
class stack
{
private:
	struct node
	{
		string term;
		string acctName;
		node *next;
	};

	node *top;
public:
	stack();
	~stack();

	void push(string &term, string &acctId);
	void pop(string &term, string &acctId);
	void findTerm(string termSearch, vector<structure1::customer>& data);
	bool empty();
};
#endif


