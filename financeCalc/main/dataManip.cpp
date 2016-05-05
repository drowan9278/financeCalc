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
	if (Yn == "YES")
	{
		cout << "Starting Back Up" << endl;
		time_t rawtime;
		struct tm * timeinfo;
		char buffer[80];
		time(&rawtime);
		timeinfo = localtime(&rawtime);
		string testFile = "Backup.dat";
		strftime(buffer, 80, "Backup at %F %I.%M.dat", timeinfo);
		string fileName = buffer;
		ofstream fileBack;
		fileBack.open(testFile.c_str(), ios::in | ios::binary | ios::trunc);
		if (fileBack)
		{
			for (int x = 0;x < data.size();x++)
			{
				string bufferArray[100];
				char pinChar[8];
				strncpy(pinChar, data[x].detail.pin.c_str(), data[x].detail.pin.length());
				fileBack.write(pinChar, sizeof(pinChar));
				for (int y = 0; y < 100;y++)
				{
					if (y < data[x].detail.history[y].size())
						bufferArray[y] = data[x].detail.history[data[x].detail.history.size() - y];/* This makes it so most recent transactions are stored*/
					char buff[200];
					strncpy(buff, bufferArray[y].c_str(), bufferArray[y].length());
					fileBack.write(buff, sizeof(buff));
				}
				fileBack.write(reinterpret_cast<char *>(&data[x].detail.balance), sizeof(data[x].detail.balance));
				fileBack.write(reinterpret_cast<char *>(&data[x].vectorID), sizeof(data[x].vectorID));
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


void dataManip::BackupRead(vector<structure1::customer>& data1)
{
	structure1::customer data;
	ifstream fileBack;
	fileBack.open("Backup.dat", ios::in | ios::binary);
	if (fileBack)
	{
		int x = 0;
		while(!fileBack.eof())
		{
			//fileBack >> data.detail.pin;
			string bufferArray[100];
			for (int y = 0;  y<100;y++)
			{
				char buff[1000];
				fileBack.read(buff, sizeof(buff));
				string charString(buff);
				data.detail.history.push_back(charString);
				
			}
			/*
			
			fileBack.read((char*)&data.detail.balance, sizeof(data.detail.balance));
			fileBack.read((char*)&data.name, data.name.size());
			fileBack.read((char*)&data.vectorID, sizeof(data.vectorID));
			fileBack.read(&data.type, sizeof(data.type));*/
			//for (int y = 0; y<data.detail.history.size() || y<100;y++)
			//{
			//	 data.detail.history.push_back(bufferArray[y]);/* Pushes contents of previous array into file*/
			//}


		}
		cout << "Done" << endl;
		fileBack.close();
	}

}
