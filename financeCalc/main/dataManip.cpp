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
		strftime(buffer, 80, "Backup at %F %I.%M.dat", timeinfo);
		string fileName =  buffer;
		ofstream fileBack;
		fileBack.open(testFile.c_str(), ios::in|ios::binary|ios::trunc);
		if(fileBack)
		{
			for(int x = 0;x<data.size();x++)
			{
				fileBack.write((char*)&data[x].detail.pin, data[x].detail.pin.size());
				fileBack.write(reinterpret_cast<const char*>(&data[x].detail.history), data[x].detail.history.size() * sizeof(data[x].detail.history));
			}
			
			cout << "Done" << endl;
			fileBack.close();
		}
		else
		{
			cout << "Backup operation failed" << endl;
		}
		system("pause");
		
			
		
		menu.mainMenu(data);
	}
	else
	{
		cout << "Cancelling operation.../n Done!" << endl;
		menu.mainMenu(data);

	}

}
void dataManip::BackupRead(vector<structure1::customer>& data)
{
	ofstream fileBack;
	fileBack.open("Backup.dat", ios::out | ios::binary | ios::trunc);


}