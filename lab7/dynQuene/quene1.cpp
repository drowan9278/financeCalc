#include "quene1.h"




#include <iostream>
#include <string>
using namespace std;


quene1::quene1()
{
	front = nullptr;
	rear = nullptr;
	numNode = 0;
}


quene1::~quene1()
{
	clear();
}
void quene1::addQue(string x)
{
	node *newNode = nullptr;

	newNode = new node;
	newNode->value = x;
	newNode->next = nullptr;

	if (empty())
	{
		front = newNode;
		rear = newNode;
	}
	else
	{
		rear->next = newNode;
		rear = newNode;
	}
	numNode++;
}
void quene1::delQue(string &x)
{
	node *nodePtr = nullptr;
	if (empty())
	{
		cout << "The quene does not have any values" << endl;
	}
	else
	{
		x = front->value;
		nodePtr = front;
		front = front->next;
		delete nodePtr;
		numNode--;

	}
}
bool quene1::empty()
{
	bool tf;
	if (numNode>0)
	{
		tf = false;
	}
	else
	{
		tf = true;
	}
	return tf;
}
void quene1::clear()
{
	string value;
	while (!empty())
	{
		delQue(value);
	}
}





