// minMaxTemplates.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

template<typename T>
class T
{
public:
	 T(int);
	

	T min(T x,T y)
	{
		if (x < y)
			return x;
		else
			return y;
	}
	T max(T x,T y)
	{
		if (x > y)
			return x;
		else
			return y;
	}
};


ostream operator<<(const ostream& lhs, const T<int>& rhs);

int main()
{
	T<int> obj;
	cout << "Enter two numbers" << endl;
	int x, y;
	cin >> x >> y;
	
		T<int>  value = obj.min(x, y);
		cout << "The small one is:" << value << endl;

	return 0;
}


