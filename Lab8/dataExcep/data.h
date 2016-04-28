#ifndef	DATA_H
#define DATA_H
class data
{

public:
	data();
	~data();

	class wrongMonth {
		private:
			int value;
		public:
			wrongMonth(int val)
			{
				value = val;
			}
			int getVal() const
			{
				return value;
			}

	};
	class wrongDay
	{
		private:
			int value;
		public:
			wrongDay(int val)
			{
				value = val;
			}
			int getVal() const
			{
				return value;
			}
	};
	
	struct dates
	{
		int day;
		int month;
		int year;
	}date;
	void getDate();

};
#endif

