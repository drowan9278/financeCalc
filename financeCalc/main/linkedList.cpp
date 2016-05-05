#include"linkedList.h"
#include "menus.h"
#include <string>
#include <iostream>
#include <ctime>
#include "structure1.h"
#include "dataManip.h"
#include <stdlib.h>
#include <assert.h>

linkedList::linkedList()
{
}

linkedList::~linkedList()
{
}

using namespace std;

dataManip backup;

typedef struct Info
{
	char name[100];
} Info;


typedef struct ListNode
{
	Info info;
	ListNode *next;
};
void print_comparisons(ListNode* ln)
{
	assert(ln);

	ListNode* cur = ln;
	ListNode* next = cur->next;
	for (; next; cur = next, next = next->next) {
		if (strcmp(cur->info.name, next->info.name) == 0)
			printf("Same name\n");
		else
			printf("Diff name\n");
	}
}
void linkedList::searchTransactions(int x, vector<structure1::customer>& data)
{

};





