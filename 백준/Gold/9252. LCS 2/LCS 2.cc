#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

#define INF 2147483647

using namespace std;

int dp[1001][1001] = { 0 };



//dp 역추적
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s[2];
	int i, j;

	//1차 인풋 가로 1001
	//2차 인풋 세로 1001
	cin >> s[0] >> s[1];

	for (i = 1; i <= s[1].size(); i++)
	{
		for (j = 1; j <= s[0].size(); j++)
		{
			dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			if (s[0][j - 1] == s[1][i - 1])
				dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);

		}
	}
	j = s[0].size();
	i = s[1].size();

	cout << dp[i][j] << '\n';
	stack<char> char_stack;
	while (true)
	{
		if (dp[i][j] == 0)
			break;
		while (true)
		{
			if (dp[i - 1][j] != dp[i][j])
				break;
			i--;
		}
		while (true)
		{
			if (dp[i][j - 1] != dp[i][j])
				break;
			j--;
		}
		char_stack.push(s[0][j - 1]);
		i--; j--;
	}
	while (!char_stack.empty())
	{
		char c = char_stack.top();
		cout << c;
		char_stack.pop();
	}
}
