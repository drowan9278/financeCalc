#pragma once
class quene
{
public:
	quene();
	~quene();
	struct node
	{
		int value;
		node *next;
	};
	node *front;
	node *rear;
	int numNode;
	void addQue(int);
	void delQue(int &);
	bool empty();
	
	void clear();
};

