#include "quene.h"
#include <iostream>
using namespace std;


quene::quene()
{
	front = nullptr;
	rear = nullptr;
	numNode = 0;
}


quene::~quene()
{
	clear();
}
void quene::addQue(int x)
{
	node *newNode = nullptr;

	newNode = new node;
	newNode->value = x;
	newNode->next = nullptr;

	if(empty())
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
void quene::delQue(int &x)
{
	node *nodePtr=nullptr;
	if(empty())
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
bool quene::empty()
{
	bool tf;
	if(numNode>0)
	{
		tf = false;
	}
	else
	{
		tf = true;
	}
	return tf;
}
void quene::clear()
{
	int value;
	while(!empty())
	{
		delQue(value);
	}
}





