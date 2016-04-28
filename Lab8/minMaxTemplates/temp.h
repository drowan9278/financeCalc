#pragma once
class temp
{
public:
	temp();
	~temp();
	template<class T>
	T max(T x, T y)
	{
		if (x > y)
			return x;
		else
			return y;
	}
	template<class T2>
	T2 min(T2 x,T2 y)
	{
		if (x < y)
			return x;
		else
			return y;
	}
};

