#include <iostream>                                                 
#include <string>                                                   
#include <fstream>                                                  
#ifndef MENUS_H
#define MENUS_H

#include"linkedList.h"
#include <ctime>
#include "structure1.h"
#include "dataManip.h"
#include <stdlib.h>
#include <assert.h>


using namespace std;

int main()
{

	linkedList menu;
	cout << "\n\n\t\t" << data[x].name << endl;
	cout << "Type: ";
	if (data[x].type == 'c' || data[x].type == 'C')
		cout << "Checking" << endl;
	else
		cout << "Savings" << endl;
	cout << "Current balance: " << data[x].detail.balance << endl;
	cout << "Would you like to view transaction history? (Y or N)" << endl;
	string yn;
	menu.search(2);//static search
	system("pause");
};


linkedList::linkedList()
{
	head = NULL;
	current = NULL;
	temp = NULL;
};


linkedList::~linkedList()
{

};


void linkedList::insert(int x, vector<structure1::customer>& data)                                    //insert function, data is stored in add from f
{
	Node* newnode = new Node;                                       //definition of add node, make new node and make node* point to it
	newnode->next = NULL;                                           //point and set up to last node in the list (nothing)
	newnode->number = x;                                          //adds data to list

	if (head != NULL)                                               //if head is pointing to object then we have list
	{
		current = head;                                             //make current pointer point to head
		while (current->next != NULL)                               //check to see if end at list, is it the last node?
		{
			current = current->next;                                //advances current pointer to end of list
		}
		current->next = newnode;                                    //adds new node next to value already stored
	}
	else
	{
		head = newnode;                                             //if we don't have element in list
	}
};


void linkedList::remove(int remove)                                 //remove function, data is stored in remove from function body
{
	Node* remove1 = NULL;                                           //searches through for same value in remove and deletes
	temp = head;
	current = head;
	while (current != NULL && current->number != remove)            //check if current node is one we want to delete...if not advance current pointer to next one
	{
		temp = current;                                             //keep temp pointer one step behind
		current = current->next;                                    //advance to next node, traverse list till at the end
	}
	if (current == NULL)                                            //pass through whole list and value not found
	{
		std::cout << "N/A\n";
		delete remove1;                                             //removes spare number floating around in memory
	}
	else
	{
		remove1 = current;                                          //pointing to value we want to delete
		current = current->next;                                    //advances current pointer to next node
		temp->next = current;                                       //stops hole that occurs in list, patches this up
		if (remove1 == head)                                        //if pointer is pointing to front of list
		{
			head = head->next;                                      //advance the head to next
			temp = NULL;
		}

		delete remove1;
	}
};


void linkedList::search(int searchNum)
{
	Node* searchnumber = nullptr;
	temp = head;
	current = head;

	while (current != NULL && current->number != searchNum)
	{
		temp = current;
		current = current->next;
	}
	if (current != NULL)
	{
		searchnumber = current;
		current = current->next;
		std::cout << "-" << searchnumber << " Found";
	}
	else
	{
		std::cout << "N/A";
	}
};


void linkedList::display()
{
	current = head;                                                 //point to start of list

	while (current != NULL)                                         //while it points to something in list
	{
		std::cout << current->number;                               //display list starting from start
		current = current->next;                                    //advance to next pointer
	}
};


void linkedList::reverse()
{
	Node *new_head = nullptr;                                       //create new head as we want it to start from last element

	for (current = head; current;)                                  //same as display, ask it to go through list from head then outside loop assign to new head and switch sides
	{
		temp = current;                                             //keep temp pointer one step behind
		current = current->next;                                    //goes through each element in the list
		temp->next = new_head;                                      //scrolls through backwards from new head
		new_head = temp;
	}

	head = new_head;                                                //assign head to new head
};
#endif

