// fileHead.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <string>
#include <iostream>
using namespace std;

int main()
{
	fstream file;
	string input;
	string fileName;
	cout << "Please enter file name: ";
	cin >> fileName;
	file.open(fileName, ios::in);
	int count = 0;
	if(file)
	{
		cout << "File loaded succefully, it will be displayed below." << endl;
		getline(file, input);
		while(file && count<9)
		{
			cout << input << endl;
			getline(file, input);
			count++;
		}
		if(count<9)
		{
			cout << "Whole file was displayed." << endl;
		}
	}
	else
	{
		cout << "ERROR: File was not opened." << endl;
	}
	
	
	
	return 0;
}

