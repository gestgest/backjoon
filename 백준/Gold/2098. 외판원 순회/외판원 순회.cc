#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define INF 2147483647

int graph[16][16];
int weight[16][1 << 16]; // before, 상태. => 상태가 아니라 그냥 16이면 1100, 1001의 비교에서 인덱스 1에 들어가려고 할때 1110 1101이된다
int n;

//시간초과 걸리면 무조건 바텀 업 + 지나간 경로 표시 하자
int dfs(int start, int status)
{
	if (status == (1 << n) - 1)
	{
		if (graph[start][0] == 0)
			return INF;
		return weight[start][status] = graph[start][0];
	}

	//만약 한번이라도 지나갔다면
	if (weight[start][status] != -1)
		return weight[start][status];

	weight[start][status] = INF; //지나간 경로라고 표시
	//이거 하는 이유가 가다가 마지막이 막히면 결국 ?임
	//다시 이 거를 마주치면 다시 dfs 돌려야함

	for (int i = 1; i < n; i++)
	{
		//도시를 다녀왔다면 => 무시
		if (status & (1 << i)) {
			continue;
		}
		//경로가 없다면
		if (graph[start][i] == 0) {
			continue;
		}
		
		int num = dfs(i, status | 1 << i);
		if (num == INF) {
			continue;
		}
		//기존의 값이 
		weight[start][status] = min(weight[start][status], num + graph[start][i]);
	}
	return weight[start][status];

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
			//if graph == 0는 못 간다는 뜻
			cin >> graph[i][j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j < (1 << n); j++)
		{
			weight[i][j] = -1;
		}
	}

	//가로 2^16짜리 간선 길이
	cout << dfs(0, 1) << '\n';

}

/*
4
0 7 3 3
7 0 9 2
1 9 0 12
7 7 12 0
*/