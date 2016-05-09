#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <vector>
#include "structure1.h"
#include "menus.h"
#pragma once
class linkedList
{
public:
	linkedList();
	~linkedList();
	void insert(int x, vector<structure1::customer>& data);
	void searchTransactions(int x, vector<structure1::customer>& data);


	/*void linkedList::insert(int x, vector<structure1::customer>& data);

	void linkedList::remove(int remove);
	void linkedList::search(int searchNum);

	void linkedList::display();

	void linkedList::reverse();*/
};
#endif
