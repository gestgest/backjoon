#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int s[500][500];
int dp[500][500];
int c, r;
int dx[] = { 0,1,0,-1 };
int dy[] = { -1,0,1,0 };

int dfs(int x, int y)
{

	if (dp[y][x] != -1)
	{
		return dp[y][x];
	}
	if (y == c - 1 && x == r - 1)
	{
		return 1;
	}

	int num = s[y][x];
	int result = 0;

	//4등분 dfs
	for (int i = 0; i < 4; i++)
	{
		bool y_check = (0 <= y + dy[i] && y + dy[i] < c);
		bool x_check = (0 <= x + dx[i] && x + dx[i] < r);

		if (y_check && x_check)
		{
			if (s[y + dy[i]][x + dx[i]] < num)
			{
				result += dfs(x + dx[i], y + dy[i]);
			}
		}
	}
	dp[y][x] = result;
	return dp[y][x];
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> c >> r;

	for (int i = 0; i < c; i++)
	{
		for (int j = 0; j < r; j++)
		{
			cin >> s[i][j];
			dp[i][j] = -1;
		}
	}

	cout << dfs(0, 0) << '\n';

	/*
	for (int i = 0; i < c; i++)
	{
		for (int j = 0; j < r; j++)
		{
			cout << dp[i][j];
		}
		cout << '\n';
	}*/
}