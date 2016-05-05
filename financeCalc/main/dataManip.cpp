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
	/* only will be able to store previous 100 transactions*/
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
				string bufferArray[100];
				for(int y=0; y<data[x].detail.history.size() || y<100 ;y++)
				{
					bufferArray[y] = data[x].detail.history[y];
				}
				fileBack.write((char*)bufferArray, sizeof(bufferArray));
				fileBack.write((char*)&data[x].detail.balance, sizeof(data[x].detail.balance));
				fileBack.write((char*)&data[x].name, data[x].name.size());
				fileBack.write((char*)&data[x].vectorID, sizeof(data[x].vectorID));
				fileBack.write(&data[x].type, sizeof(data[x].type));

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