#include <iostream>
#include <vector>
#include <map>
#include <iterator>

using namespace std;

int main()
{
	int n;

	map<int, int> map_line;
	vector<int> dp;
	map<int, int>::iterator it;
	bool isCheck = false;
		
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int left, right;
		cin >> left >> right;

		map_line.insert(pair<int, int>(left, right));
	}

	it = map_line.begin();

	dp.push_back(it->second);
	it++;

	for (; it != map_line.end(); it++)
	{
		isCheck = false;
		for (int i = 0; i < dp.size(); i++)
		{
			if (dp[i] > it->second) {
				dp[i] = it->second;
				isCheck = true;
				break;
			}
		}
		if (isCheck == false) {
			dp.push_back(it->second);
		}
	}

	cout << n - dp.size();
}