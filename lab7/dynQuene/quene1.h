#ifndef QUENE_1
#define QUENE_1
#include <string>
using namespace std;
class quene1
{
public:
	quene1();
	~quene1();
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


