#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>
using namespace std;
class employee
{
public:
	employee();
	~employee();
	string name;
	string getName()
	{
		return name;
	}
	void setName(string x)
	{
		name = x;
	}
	int ID;
	int getID()
	{
		return ID;
	}
	void setID(int x)
	{
		
		if(x>0 && x<9999)
			ID = x;
		else
		{
			string error = "ERROR: Wrong ID value entered";
			throw error;
		}
	}
	string date;
	string getDate()
	{
		return date;
	}
	void setDate(string x)
	{
		date = x;
	}


};
#endif

