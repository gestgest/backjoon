#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define INF 2147463647

//dj

class Edge {
public:
	int dst;
	int value;
	Edge(int dst, int value) {
		this->dst = dst;
		this->value = value;
	}

	const bool operator <(const Edge& edge) const&
	{
		return this->value > edge.value;
	}
};

Edge getEdge(priority_queue<Edge> & edge_queue, vector<int> & short_path)
{
	while (true)
	{
		if (edge_queue.empty()) {
			return Edge(-1, -1);
		}
		Edge edge = edge_queue.top();
		edge_queue.pop();

		if (short_path[edge.dst] == INF) {
			short_path[edge.dst] = edge.value;

			return edge;
		}
	}
}


void bfs(vector<Edge> *edges, int v, int start)
{
	vector<int> short_path = vector<int> (v, INF);
	priority_queue<Edge> bfs_queue;

	bfs_queue.push(Edge(start, 0));

	while (true)
	{
		Edge edge = getEdge(bfs_queue, short_path);

		if (edge.dst == -1) {
			break;
		}
		
		for (int i = 0; i < edges[edge.dst].size(); i++)
		{
			bfs_queue.push(Edge(edges[edge.dst][i].dst, edges[edge.dst][i].value + edge.value));
		}
	}

	for (int i = 0; i < v; i++)
	{
		if (INF != short_path[i])
			cout << short_path[i] << '\n';
		else {
			cout << "INF" << '\n';
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int v, e;
	int start;
	int a, b, c;

	vector<Edge> edges[20001];

	cin >> v >> e;

	cin >> start; start--;
	
	for (int i = 0; i < e; i++)
	{
		cin >> a >> b >> c;
		a--; b--;
		edges[a].push_back(Edge (b, c));
	}

	bfs(edges, v, start);
}