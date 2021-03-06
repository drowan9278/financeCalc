#include "dataManip.h"
#include <vector>
#include <fstream>
#include "structure1.h"
#include <iostream>
#include <ctime>
#include <algorithm>

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
					if (y < data[x].detail.history.size()) {
						bufferArray[y] = data[x].detail.history[data[x].detail.history.size() - y -1];
					}/* This makes it so most recent transactions are stored*/
					char buff[200];
					strncpy(buff, bufferArray[y].c_str(), bufferArray[y].length());
					fileBack.write(buff, sizeof(buff));
				}
				fileBack.write(reinterpret_cast<char *>(&data[x].detail.balance), sizeof(data[x].detail.balance));
				fileBack.write(reinterpret_cast<char *>(&data[x].vectorID), sizeof(data[x].vectorID));
				fileBack.write(&data[x].type, sizeof(data[x].type));
				char nameChar[30];
				string nameHold = data[x].name;
				nameHold.resize(30, '�');
				strncpy(nameChar, nameHold.c_str(), nameHold.length());

				fileBack.write(nameChar, sizeof(nameChar));

			}
			cout << "Done" << endl;
			fileBack.close();
		}
		else
		{
			cout << "Backup operation failed" << endl;
		}
		system("pause");
		
	}
	else
	{
		cout << "Cancelling operation.../n Done!" << endl;
		

	}

}


void dataManip::BackupRead(string fileName,vector<structure1::customer>& data1)
{
	structure1::customer data;
	ifstream fileBack;
	fileBack.open(fileName, ios::in | ios::binary);
	if (fileBack)
	{
		int x = 0;
		while(!fileBack.fail())
		{
			char pinChar[8];
			if (fileBack.eof())
				break;
			fileBack.read(pinChar, sizeof(pinChar));
			string pin(pinChar);
			pin.erase(remove(pin.begin(), pin.end(), '�'), pin.end());
			if (fileBack.eof())
				break;
			data.detail.pin = pin.substr(0,8);
			
			string bufferArray[100];
			for (int y = 0;  y<100;y++)
			{
				char buff[200];
				fileBack.read(buff, sizeof(buff));
				string charString(buff);
				charString.erase(remove(charString.begin(), charString.end(), '�'), charString.end());
				data.detail.history.push_back(charString);
			}
			fileBack.read(reinterpret_cast<char*>(&data.detail.balance), sizeof(data.detail.balance));
			fileBack.read(reinterpret_cast<char *>(&data.vectorID), sizeof(data.vectorID));
			fileBack.read(&data.type, sizeof(data.type));
			char nameChar[30];
			fileBack.read(nameChar, sizeof(nameChar));
			for(int x = 0; x< sizeof(nameChar); x++)
			{
				if(nameChar[x] == '�')
				{
					nameChar[x] = ' ';
				}
			}
			string name(nameChar);

			name.erase(remove(name.begin(), name.end(), '�'), name.end());
			data.name = name;
			data1.push_back(data);
			if (fileBack.eof())
				break;

		}
		cout << "Done" << endl;
		
		fileBack.close();
	}

}
void dataManip::Backup1(vector<structure1::customer>& data)
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
		strftime(buffer, 80, "Backup at %F %I.%M.dat", timeinfo);
		string fileName = buffer;
		ofstream fileBack;
		fileBack.open(fileName.c_str(), ios::in | ios::binary | ios::trunc);
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
					if (y < data[x].detail.history.size()) {
						bufferArray[y] = data[x].detail.history[data[x].detail.history.size() - y - 1];
					}/* This makes it so most recent transactions are stored*/
					char buff[200];
					strncpy(buff, bufferArray[y].c_str(), bufferArray[y].length());
					fileBack.write(buff, sizeof(buff));
				}
				fileBack.write(reinterpret_cast<char *>(&data[x].detail.balance), sizeof(data[x].detail.balance));
				fileBack.write(reinterpret_cast<char *>(&data[x].vectorID), sizeof(data[x].vectorID));
				fileBack.write(&data[x].type, sizeof(data[x].type));
				char nameChar[30];
				string nameHold = data[x].name;
				nameHold.resize(30, '�');
				strncpy(nameChar, nameHold.c_str(), nameHold.length());

				fileBack.write(nameChar, sizeof(nameChar));

			}
			cout << "Done" << endl;
			fileBack.close();
		}
		else
		{
			cout << "Backup operation failed" << endl;
		}
		system("pause");

	}
	else
	{
		cout << "Cancelling operation.../n Done!" << endl;


	}

}