// linkedList.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "lists.h"

int main()
{
	lists obj;
	obj.appendNode(10);
	obj.appendNode(13.4);
	obj.appendNode(23.5);
	obj.insertNode(13.7);
	obj.deleteNode(23.5);
	obj.reverseList();
	obj.search();
	obj.destroyList();
	
	
	return 0;
}

