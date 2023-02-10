#include <iostream>
#include <string>
using namespace std;

string div2(string s)
{
	bool ten = false;
	int count = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '0')
		{
			count++;
		}
		else if ((s[i] - '0') % 2 == 0)
		{
			s[i] = ((s[i] - '0') / 2) + '0';
		}
		// 홀수
		else
		{
			s[i] = ((s[i] - '0') / 2) + '0';
			if (i != s.size() - 1)
			{
				s[i + 1] += 10;
			}
		}
		
	}
	if (count == s.size())
		return "X";
	else
		return s;
}

string log2(string s)
{
	string ss = "";
	int count = 0;
	while (true)
	{
		s = div2(s);
		if (s == "X")
			break;
		count++;
	}
	//설마 2^100까지 하겠어~ ppap
	while (true)
	{
		if (count / 10 == 0)
		{
			ss += count + '0';
			return ss;
		}
		int num = count / 10;
		ss += num + '0';
		count -= num * 10;
	}
}

string add(string s1, string s2)
{
	int i, j;
	bool isPlus = false;
	bool isSize = false;
	string ss;
	if (s1.size() <= s2.size())	{
		ss = s2;
		isSize = true;
	}
	else {
		ss = s1;
		isSize = false;
	}
	for (i = s1.size() - 1, j = s2.size() - 1; 0 <= i && 0 <= j; i--, j--)
	{
		int num = s1[i] - 2 * '0' + s2[j];
		if (isPlus)
		{
			num++;
			isPlus = false;
		}
		if (10 <= num)
		{
			isPlus = true;
			num -= 10;
		}
		if(isSize)
			ss[j] = num + '0';
		else
			ss[i] = num + '0';
	}
	while (true)
	{
		if (i == -1)
			break;
		else if (isPlus)
		{
			isPlus = false;
			ss[i]++;
			if (10 <= ss[i] - '0')
			{
				ss[i] -= 10;
				isPlus = true;
			}
			i--;
		}
		else
			break;
	}

	while (true)
	{
		if (j == -1)
			break;
		else if (isPlus)
		{
			isPlus = false;
			ss[j]++;
			if (10 <= ss[j] - '0')
			{
				ss[j] -= 10;
				isPlus = true;
			}
			j--;
		}
		else
			break;
	}
	if (isPlus)
		cout << "1";
	return ss;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int count;
	string n, m;

	cin >> count;
	while (count--)
	{
		cin >> n >> m;
		cout << add(log2(n), m) << '\n';

	}
}