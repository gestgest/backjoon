#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define INF 2147483647

class Edge {
public:
	int dst;
	int isVisited;
	Edge(int dst, int isVisited)
	{
		this->dst = dst;
		this->isVisited = isVisited;
	}
};

bool bfs(vector<int> & isVisited, vector<vector<int>> &graph, int start)
{
	if (isVisited[start] != 0)
	{
		return true;
	}

	int p = 1;

	queue<Edge> edge_queue;
	edge_queue.push(Edge(start, 1));

	while (!edge_queue.empty())
	{
		Edge edge = edge_queue.front();
		edge_queue.pop();

		//visited가 서로 다르다면
		if (isVisited[edge.dst] == -1 * edge.isVisited)
		{
			return false;
		}
		if (isVisited[edge.dst] != 0)
		{
			continue;
		}
		//아예 방문하지 않았다면

		isVisited[edge.dst] = edge.isVisited;

		for (int i = 0; i < graph[edge.dst].size(); i++)
		{
			edge_queue.push(Edge(graph[edge.dst][i], edge.isVisited * -1));
		}
	}
	return true;
}

//그래프
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t;
	int n, m;
	int a, b;

	cin >> t;
	while (t--)
	{
		//동그라미, 직선
		cin >> n >> m;
		vector<vector<int>> graph;
		vector<int>isVisited = vector<int>(n, 0);

		graph = vector<vector<int>>(n);
		int i = 0;

		for (i = 0; i < m; i++)
		{
			cin >> a >> b;
			a--; b--;

			graph[a].push_back(b);
			graph[b].push_back(a);
		}

		//start 설정, 이미 지나갔다면 무시
		for (i = 0; i < n; i++)
		{
			if (!bfs(isVisited, graph, i))
			{
				cout << "impossible" << '\n';
				break;
			}
		}
		if(i == n)
			cout << "possible" << '\n';

	}
}