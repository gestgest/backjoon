#include <iostream>
#include <map>
#include <iterator>
using namespace std;


bool isCheater() 
{
	map<string, int> hs = map<string, int>();
	string s;

	int index;
	bool isCheck = true;

	cin >> index;
	for (int i = 0; i < index; i++)
	{
		cin >> s;
		if (hs.count(s)) {
			int count = hs.at(s);
			hs.at(s) = ++count;
		}
		else {
			hs.insert(pair<string, int>(s, 1));
		}

	}

	for (int i = 0; i < index; i++)
	{
		cin >> s;
		if (hs.count(s)) {
			int count = hs.at(s);
			hs.at(s) = --count;
		}
		else
			isCheck = false;

	}

	map<string,int>::iterator it;
	for (it = hs.begin(); it != hs.end(); it++)
	{
		if (it->second != 0)
		{
			return false;
		}
	}

	return isCheck;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	//입력

	int n;
	cin >> n;

	while (n--)
	{
		if (isCheater())
		{
			cout << "NOT CHEATER" << '\n';
		}
		else
			cout << "CHEATER" << '\n';
	}
}