#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
#define INF 2147483647


int waste_times[1000];
int results[1000];
vector<int> graph[1000];
int indegrees[1000];


void bfs(int n)
{
	queue<int> my_queue; //index

	for (int i = 0; i < n; i++)
	{
		//시작노드가 부모 => indegree가 0
		if (indegrees[i] == 0)
		{
			my_queue.push(i);
		}
	}

	while (!my_queue.empty())
	{
		//start
		int start = my_queue.front();
		my_queue.pop();

		for (int i = 0; i < graph[start].size(); i++)
		{
			int end = graph[start][i];

			results[end] = max(results[end], results[start] + waste_times[end]);
			indegrees[end]--;

			if (indegrees[end] == 0)
			{
				my_queue.push(end);
			}
		}
	}
}

//다익으로 해서 제일 큰 값이
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int i, j;
	int n, t, k;
	int a, b;
	int win_building_index;
	cin >> t;

	while (t--)
	{
		cin >> n >> k;

		int max_value = 0;

		for (i = 0; i < n; i++)
		{
			cin >> waste_times[i];
			graph[i].clear();
			indegrees[i] = 0;
			results[i] = waste_times[i];
		}

		for (i = 0; i < k; i++)
		{
			cin >> a >> b;
			a--; b--;

			graph[a].push_back(b);
			indegrees[b]++;
		}


		cin >> win_building_index;
		win_building_index--;

		bfs(n);

		cout << results[win_building_index] << '\n';
	}
}