#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp[1001][1001] = { 0 };

int max_value(int a, int b)
{
	if (a < b) {
		return b;
	}
	return a;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s[2];

	//0은 가로, 1은 세로
	cin >> s[0] >> s[1];

	for (int i = 1; i <= s[1].size(); i++)
	{
		for (int j = 1; j <= s[0].size(); j++)
		{
			dp[i][j] = max_value(dp[i][j - 1], dp[i - 1][j]);

			if (s[1][i - 1] == s[0][j - 1])
			{
				dp[i][j] = max_value(dp[i][j], dp[i - 1][j - 1] + 1);
			}
		}
	}
	cout << dp[s[1].size()][s[0].size()] << '\n';

	int y = s[1].size();
	int x = s[0].size();
	string v = "";
	
	//디버깅
	/*
	for (int i = 0; i <= y; i++)
	{
		for (int j = 0; j <= x; j++)
		{
			cout << dp[i][j] << ' ';
		}
		cout << '\n';
	}
	*/

	//역추적 <- 위
	while (true)
	{
		if (y == 0 || x == 0)
			break;

		//왼쪽으로 쭉
		if (dp[y][x] == dp[y][x - 1])
		{
			x--;
		}
		//위쪽으로 쭉
		else if (dp[y][x] == dp[y - 1][x])
		{
			y--;
		}
		else {
			x--;
			y--;
			v += s[0][x];
		}
	}

	for (int i = v.length() - 1; i >= 0; i--)
	{
		cout << v[i];
	}

}