#include "dataManip.h"
#include <vector>
#include <fstream>
#include "structure1.h"
#include <iostream>
#include <ctime>
using namespace std;

menus menu;
dataManip::dataManip()
{
}


dataManip::~dataManip()
{
}

void dataManip::Backup(vector<structure1::customer>& data)
{
	cout << "Would you like to back up?(Explicitly enter YES to continue" << endl;
	string Yn;
	cin >> Yn;
	if(Yn=="YES")
	{
		cout << "Starting Back Up" << endl;
		time_t rawtime;
		struct tm * timeinfo;
		char buffer[80];
		time(&rawtime);
		timeinfo = localtime(&rawtime);
		string testFile = "Backup.dat";
		strftime(buffer, 80, "%c.dat", timeinfo);
		string fileName =  buffer+ testFile;
		ofstream fileBack;
		fileBack.open(testFile.c_str(), ios::in|ios::binary|ios::trunc);
		
			fileBack.write((char*)&data, data.size());
			cout << "File Succefully Backed Up" << endl;
			fileBack.close();
		
		
		
			cout << "Backup operation failed" << endl;
		
		menu.mainMenu(data);
	}
	else
	{
		cout << "Cancelling operation.../n Done!" << endl;
		menu.mainMenu(data);

	}
}
