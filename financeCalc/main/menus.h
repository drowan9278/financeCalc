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
	void grabStructDataFirst(int x, vector<structure1::customer> &data);
};
#endif
