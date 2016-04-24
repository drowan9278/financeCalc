#pragma once
#include <string>
#include <vector>
using namespace std;
class structure1
{
public:
	structure1();
	~structure1();
	struct details
	{
		float balance;
		vector<string> history;/*This is where I figured we could add the history of the balance and create a easy way to print it*/
	};
	struct customer
	{
		
		string type; /*This is where we could specify the type of account it is-DR*/
		details detail;
	};/*Have to create a pointer so we could create an array later on after specifing amount of account, or mabye we could do a linked list of accounts? unsure-DR*/
	vector<customer> accounts;
};

