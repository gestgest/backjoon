#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
#define INF 2147483647


vector<int> graph[32000];
int graph_count[32000] = {0};

//위상정렬 topological sorting
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	int a, b;
	queue<int> index_queue;


	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		a--; b--;

		graph[a].push_back(b);
		graph_count[b]++;
	}

	for (int i = 0; i < n; i++)
	{
		if (graph_count[i] == 0)
			index_queue.push(i);
	}

	while (!index_queue.empty())
	{
		int index = index_queue.front();
		index_queue.pop();
		cout << index + 1 << ' ';
		for (int i = 0; i < graph[index].size(); i++)
		{
			graph_count[graph[index][i]]--;

			if (graph_count[graph[index][i]] == 0)
				index_queue.push(graph[index][i]);
		}
	}
}