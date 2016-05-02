#ifndef MENUS_H
#define MENUS_H
#include <vector>
#include "structure1.h"
/*Here we will add our menus, shouldn't be much but should be able to access have  a menu for
-main menu
 -account select
	-add/subtract balance and add transaction desciption / date
	-search through transaction
	-print all transactions*/
class menus
{
public:
	menus();
	~menus();
	void mainMenu (vector<structure1::customer>& data);
	void modifyExistData(int x, vector<structure1::customer> &data);
	void addAccount(vector<structure1::customer>& data);
	void getInfoAccount(int x, vector<structure1::customer>& data);
	void getTransactions(int x, vector<structure1::customer>& data);
	int grabAccountId(vector<structure1::customer>& data);// Use this to verify accounts and allow user to select account using pin
	
};
#endif
