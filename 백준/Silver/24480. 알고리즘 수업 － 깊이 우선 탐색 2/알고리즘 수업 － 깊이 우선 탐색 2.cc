//https://www.acmicpc.net/problem/24480
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> graph[100001];
int index_list[100001] = {0};

void _dfs(int node, int edge, int start, int & count)
{
	index_list[start] = count;

	for (int i = 0; i < graph[start].size(); i++)
	{
		if (index_list[graph[start][i]] == 0)
		{
			count++;
			_dfs(node, edge, graph[start][i], count);
		}
	}

}

bool sort_func(int a, int b)
{
	//true면 가만히 있어라
	if (a > b)
		return true;
	else
		return false;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m, start;
	int src, dst;
	cin >> n >> m >> start;

	for (int i = 0; i < m; i++)
	{
		cin >> src >> dst;
		graph[src].push_back(dst);
		graph[dst].push_back(src);
	}

	//정렬
	for (int i = 1; i <= n; i++)
	{
		sort(graph[i].begin(), graph[i].end(), sort_func);
	}
	int count = 1;
	_dfs(n, m, start, count);

	for (int i = 1; i <= n; i++)
	{
		cout << index_list[i] << '\n';
	}

	/*
	//디버깅 출력
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j < graph[i].size(); j++)
		{
			cout << graph[i][j] << ' ';
		}
		cout << '\n';
	}
	*/
}