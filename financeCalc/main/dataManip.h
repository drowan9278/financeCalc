#ifndef  DATAMANIP_H
#define DATAMANIP_H
#include <vector>
#include "structure1.h"
#include "menus.h"
using namespace std;
/*Here is where we could do all data manipulation and as well as file back up, this is I am assumiing will be the hardest part-DR*/
class dataManip
{
public:
	dataManip();
	~dataManip();
	void Backup(vector<structure1::customer>& data);
	void BackupRead(vector<structure1::customer>& data);
};
#endif
