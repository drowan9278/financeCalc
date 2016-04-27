// dataExcep.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "data.h"
#include <iostream>




int main()
{
	data obj;
	try
    {
		obj.getDate();
	}
	catch (data::wrongMonth val)
	{
		std::cout << "ERROR: You entered ";
		std::cout << val.getVal()<<" for the month \n";
		return 1;
	}
	catch(data::wrongDay val)
	{
		std::cout << "ERROR: You entered " << val.getVal()<<" for the day\n";
		return 2;
	}
	std::cout << "The date is " << obj.date.month << "/" << obj.date.day << "/" << obj.date.year<<"\n";
	return 0;
}

