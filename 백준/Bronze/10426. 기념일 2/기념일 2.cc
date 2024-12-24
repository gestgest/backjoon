#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


//string => day
class Day {
public:
	string str;
	int year = 0;
	int month = 0;
	int day = 0;

	Day(string str)
	{
		this->str = str;
		for (int i = 0; i < 4; i++)
		{
			year *= 10;
			year += str[i] - '0';
		}
		for (int i = 5; i <= 6; i++)
		{
			month *= 10;
			month += str[i] - '0';
		}
		for (int i = 8; i <= 9; i++)
		{
			day *= 10;
			day += str[i] - '0';
		}
	}

	void DayToString()
	{
		for (int i = 3; i >= 0; i--)
		{
			str[i] = year % 10 + '0';
			year /= 10;
		}
		for (int i = 6; i >= 5; i--)
		{
			str[i] = month % 10 + '0';
			month /= 10;
		}
		for (int i = 9; i >= 8; i--)
		{
			str[i] = day % 10 + '0';
			day /= 10;
		}
	}
};

int year_year(int year, int month)
{
	//2월 전이면 year, 3월 이상이면 year++
	if (3 <= month) {
		year++;
	}
	if (year % 400 == 0) {
		return 366;
	}
	else if (year % 100 == 0) {
		return 365;
	}
	else if (year % 4 == 0) {
		return 366;
	}
	return 365;
}

//day => string

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int month[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

	string tmp;
	int plus;
	cin >> tmp >> plus;
	Day day(tmp);
	//day : 2024-01-20

	plus--;
	//윤년과 m가 2면 

	while (true)
	{
		int year_day = year_year(day.year, day.month);

		//365일보다 큰 경우
		if (year_day <= plus)
		{
			plus -= year_day;
			day.year++;
		}
		else {
			break;
		}
	}
	day.day += plus;
	while (true)
	{
		int m_day = month[day.month - 1];
		//2월이고 윤년
		if (year_year(day.year, day.month) == 366 && m_day == 28)
		{
			m_day++;
		}
		if (m_day < day.day)
		{
			day.day -= m_day;
			day.month++;
			if (day.month > 12) {
				day.year++;
				day.month -= 12;
			}
		}
		else {
			break;
		}
	}
	day.DayToString();
	cout << day.str;


}