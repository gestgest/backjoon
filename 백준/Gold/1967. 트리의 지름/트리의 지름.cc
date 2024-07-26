#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
#define INF 2147483647

class Edge {
public:
	int dst;
	int value;
	Edge(int dst, int value)
	{
		this->dst = dst;
		this->value = value;
	}
};

//10000개
vector<Edge> graph[10000];

Edge bfs(int start, int node)
{
	vector<int> dis = vector<int>(node, INF);
	int maxIndex = start;
	queue<Edge> q;
	
	q.push(Edge(start, 0));

	while (!q.empty())
	{
		Edge edge = q.front();
		q.pop();

		if (dis[edge.dst] <= edge.value)
			continue;

		dis[edge.dst] = edge.value;

		if (dis[maxIndex] < dis[edge.dst])
			maxIndex = edge.dst;

		for (int i = 0; i < graph[edge.dst].size(); i++)
		{
			q.push(Edge(graph[edge.dst][i].dst, graph[edge.dst][i].value + edge.value));
		}
	}

	return Edge(maxIndex, dis[maxIndex]);
}


int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int node;
	int src, dst, value;
	cin >> node;
	

	for (int i = 0; i < node - 1; i++)
	{
		cin >> src >> dst >> value;
		src--; dst--;
		graph[src].push_back(Edge(dst, value));
		graph[dst].push_back(Edge(src, value));
	}

	Edge edge = bfs(0, node);
	edge = bfs(edge.dst, node);
	cout << edge.value << '\n';
	
}