#include "lists.h"
#include <iostream>
using namespace std;


lists::~lists()
{
}
void lists::appendNode(double num)
{
	node *newNode;
	node *nodePtr;

	newNode = new node;
	newNode->value = num;
	newNode->next = nullptr;

	if(!head)
	{
		head = newNode;
	}
	else
	{
		nodePtr = head;
		while(nodePtr->next)
		{
			nodePtr = nodePtr->next;
		}
		 nodePtr->next = newNode;
	}
}
void lists::insertNode(double num)
{
	node *newNode;
	node *nodePTr;
	node *prevNode = nullptr;
	newNode = new node;
	newNode->value = num;

	if(!head)
	{
		head = newNode;
		newNode->next = nullptr;
	}
	else
	{
		nodePTr = head;
		prevNode = nullptr;
		while (nodePTr != nullptr && nodePTr->value < num)
		{
			prevNode = nodePTr;
			nodePTr = nodePTr->next;
		}
		if(prevNode == nullptr)
		{
			head = newNode;
			newNode->next = nodePTr;
		}
		else
		{
			prevNode->next = newNode;
			newNode->next = nodePTr;
		}
	}
}
void lists::deleteNode(double num)
{
	node *nodePtr;
	node *prevNode;
	nodePtr = head;
	if(!head)
	{
		return;
	}
	if(head->value == num)
	{
		nodePtr = head->next;
		delete head;
		head = nodePtr;
	}
	else
	{
		nodePtr = head;
		while(nodePtr != nullptr&& nodePtr->value !=num)
		{
			prevNode = nodePtr;
			nodePtr = nodePtr->next;
		}
		if(nodePtr)
		{
			prevNode->next = nodePtr->next;
			delete nodePtr;
		}
	}
}

void lists::destroyList()
{
	node *nodePtr;
	node *nextNode;

	nodePtr = head;
	while(nodePtr != nullptr)
	{
		nextNode = nodePtr->next;
		delete nodePtr;
		nodePtr = nextNode;
	}

}
void lists::reverseList()
{
	node *nodePtr;
	node *prevNode=nullptr;
	node *nextNode;
	nodePtr = head;
	while(nodePtr!=nullptr)
	{
		nextNode = nodePtr->next;
		nodePtr->next = prevNode;
		prevNode = nodePtr;
		nodePtr = nextNode;
	}
	head = prevNode;
}
void lists::search()
{
	cout << "Please enter the number you are looking for." << endl;
	double num;
	cin >> num;
	node *nodePtr;
	node *nextNode;
	int nodeNum = 0;
	nodePtr = head;
	while (nodePtr != nullptr)
	{
		if(nodePtr->value == num)
		{
			cout << "The node with your value is:" << nodeNum << endl;
		}
		nodePtr = nodePtr->next;
		nodeNum++;
	}
}



