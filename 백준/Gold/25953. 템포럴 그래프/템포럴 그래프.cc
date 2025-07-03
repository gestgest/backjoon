#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define INF 2000000000

//t(before, current) * n
int dp[1001][10000];

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	//m => edge_count
	int n, t, edge_count;
	int start, end;
	int a, b, c;
	
	//3차원 배열도 힘든데?
	cin >> n >> t >> edge_count;
	cin >> start >> end;

	for (int j = 0; j < n; j++)
	{
		dp[0][j] = INF;
	}
	dp[0][start] = 0;

	//하나는 T로 두고 하나는

	for (int i = 0; i < t; i++)
	{
		for (int j = 0; j < n; j++)
		{
			dp[i + 1][j] = dp[i][j];
		}

		for (int j = 0; j < edge_count; j++)
		{
			cin >> a >> b >> c;
			dp[i + 1][b] = min(dp[i + 1][b], dp[i][a] + c);
			dp[i + 1][a] = min(dp[i + 1][a], dp[i][b] + c);
		}
	}


	//t가 짝수면 홀수번째
	if (dp[t][end] == INF)
		dp[t][end] = -1;
	cout << dp[t][end] << '\n';
}