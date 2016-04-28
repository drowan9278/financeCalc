// minMaxTemplates.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "temp.h"
#include <iostream>

using namespace std;





int main()
{
	
	cout << "Enter two numbers" << endl;
	int x, y;
	cin >> x >> y;
	temp obj;
		
		cout << "The small one is:" << obj.min(x,y) << endl;
		cout << "And the large one is" << obj.max(x, y) << endl;
	return 0;
}


