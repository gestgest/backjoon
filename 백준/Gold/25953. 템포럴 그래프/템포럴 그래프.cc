#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define INF 2000000000

//t(before, current) * n
long long dp[2][10000];

void add_edge(int t, int a, int b, int c)
{
	//start -> a가 없음
	if (dp[t % 2][a] == INF)
	{
		return;
	}

	//a -> b , if (start -> a + c < start -> b)
	if (dp[t % 2][a] + c < dp[(t + 1) % 2][b])
	{
		dp[(t + 1) % 2][b] = dp[t % 2][a] + c;
	}
	else {
	}
}

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

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < n; j++)
		{
			dp[i][j] = INF;
		}
		dp[i][start] = 0;
	}

	//하나는 T로 두고 하나는

	for (int i = 0; i < t; i++)
	{

		for (int j = 0; j < n; j++)
		{
			dp[(i + 1) % 2][j] = dp[i % 2][j];
		}

		for (int j = 0; j < edge_count; j++)
		{
			cin >> a >> b >> c;
			add_edge(i, a, b, c);
			add_edge(i, b, a, c);
		}
	}


	//t가 짝수면 홀수번째
	if (dp[t % 2][end] == INF)
		dp[t % 2][end] = -1;
	cout << dp[t % 2][end] << '\n';
}