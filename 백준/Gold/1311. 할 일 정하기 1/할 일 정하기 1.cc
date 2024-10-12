#include <iostream>
#include <algorithm>

#define INF 2147483647

using namespace std;


//일단 트리 DP하듯이 한다음 visited는 비트마스크로 
//ㄴ 그냥 bf마냥 for문으로 탐색해도 되지만 그냥 안함

int cost[20][20];
int visited[1 << 20];
//2^20 * 2^20
int n;

//100000  ,=> state => 2^20
int dfs(int index, int state)
{
	//20 배열 => 
	if (index == n) {
		return 0;
	}
	if (visited[state] != 0) {
		return visited[state];
	}
	visited[state] = INF; //지나간 곳은 경로 설정
	for (int i = 0; i < n; i++)
	{
		//방문했다면
		if (state & (1 << i)) 
		{
			continue;
		}

		visited[state] = min(visited[state], dfs(index + 1, state | 1 << i) + cost[index][i]);
	}

	return visited[state];
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> cost[i][j];
		}
	}

	for (int i = 0; i < 1 << n; i++)
	{
		visited[i] = 0;
	}

	cout << dfs(0, 0) << '\n';
}
