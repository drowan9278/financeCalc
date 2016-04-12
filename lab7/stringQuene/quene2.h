#ifndef QUENE_2
#define QUENE_2
#include <string>
using namespace std;
class quene2
{
public:
	quene2();
	~quene2();
	struct node
	{
		string value;
		node *next;
	};
	node *front;
	node *rear;
	int numNode;
	void addQue(string);
	void delQue(string &);
	bool empty();

	void clear();
};
#endif