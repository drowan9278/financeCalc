#ifndef PRODWORKER_H
#define PRODWORKER_H
#include "employee.h"
class prodWorker:public employee
{
public:
	prodWorker();
	~prodWorker();
	string shift;
	string getShift()
	{
		return shift;
	}
	void setShift(string x)
	{
		if(x != "1" && x!="2")
		{
			string error = "ERROR: Wrong shift entered";
			throw error;
		}
		else	
			shift = x;
	}
	double payRate;
	double getRate()
	{
		
		
		
		return payRate;
	}
	void setPay(double x)
	{
		if(x<0)
		{
			string error = "ERROR: Wrong pay rate";
			throw error;
		}
		else
			payRate = x;
	}
};
#endif
