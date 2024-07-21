#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp[101][10001] = { 0, };

int max(int a, int b) {
	if (a < b) {
		return b;
	}
	return a;
}

// n + n + (n * cost) + cost
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m, num, sum = 0;
	int i, j;
	cin >> n >> m;

	vector<int> memory(n + 1);
	vector<int> cost(n + 1);


	for (i = 1; i <= n; i++) //n개
	{
		cin >> memory[i];
	}
	for (i = 1; i <= n; i++) //n개
	{
		cin >> cost[i];
		sum += cost[i];
	}

	//i는 n개수, j는 cost, 배열 내용은 memory
	for (i = 1; i < memory.size(); i++)
	{
		for (j = 0; j <= sum; j++)
		{
			if (cost[i] <= j) {
				dp[i][j] = max(memory[i] + dp[i - 1][j - cost[i]], dp[i - 1][j]);
			}
			else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}

	i--;
	for (j = 0; j <= sum; j++)
	{
		if (m <= dp[i][j]) {
			cout << j << '\n';
			break;
		}
	}
}
