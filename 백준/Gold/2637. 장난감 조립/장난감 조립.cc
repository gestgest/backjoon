#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
#define INF 2147483647


class Edge {
public:
	int src;
	int dst;
	int value;

	Edge(int src, int dst, int value)
	{
		this->src = src;
		this->dst = dst;
		this->value = value;
	}
};

//왼쪽이 index, 위쪽이 갯수
int dp[100][100] = {0};
int ref_count[100] = { 0 };
vector<Edge> v[100];

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	int a, b, c;
	queue<int> index_queue;

	//n - 1 해야함
	cin >> n >> m;
	
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> c;
		a--; b--;

		ref_count[a]++;
		v[b].push_back(Edge(b, a, c));
	}

	for (int i = 0; i < n; i++)
	{
		if (ref_count[i] == 0)
		{
			index_queue.push(i);
			dp[i][i] = 1;
		}
	}

	while (!index_queue.empty())
	{
		//start
		int index = index_queue.front();
		index_queue.pop();

		for (int i = 0; i < v[index].size(); i++)
		{
			for (int j = 0; j < n; j++)
			{
				//
				dp[v[index][i].dst][j] += dp[index][j] * v[index][i].value;
			}
			ref_count[v[index][i].dst]--;
			if (ref_count[v[index][i].dst] == 0)
			{
				index_queue.push(v[index][i].dst);
			}
		}
	}
	
	for (int i = 0; i < n; i++)
	{
		if (dp[n - 1][i] != 0)
		{
			cout << i + 1 << ' ' << dp[n - 1][i] << '\n';
		}
	}
	//참조 카운터가 0이면 queue에 넣기
	//미리 참조 카운터 0인건 배열에 1씩 넣기
	//참조 위치로 가고 가는데 카운터가 감소, 배열 저장? => 0이면 queue 넣기

}