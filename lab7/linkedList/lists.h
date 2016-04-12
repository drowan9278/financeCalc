#ifndef	LISTS_H
#define LISTS_H

class lists
{
public:
	lists()
	{
		head = nullptr;
	};
	~lists();
	struct node
	{
		double value;
		node *next;
	}*head;
	void appendNode(double);
	void insertNode(double);
	void deleteNode(double);
	void destroyList();
	void reverseList();
	void search();
};
#endif


