#include <iostream>
#include <vector>
#include <queue>
#include <stack>

#define INF 2147483647

using namespace std;

class Edge {
public:
	int src = -1;
	int dst = -1;
	int value = INF;
	Edge() {}
	Edge(int src, int dst, int value) {
		this->src = src;
		this->dst = dst;
		this->value = value;
	}
	bool operator <(const Edge& edge) const {
		return this->value > edge.value;
	}
};


void shortest_path_dp(vector <Edge> edges[], int start, int end, int n)
{
	vector<Edge> dis_list = vector<Edge>(n);

	priority_queue<Edge> edge_pq;
	int index;

	dis_list[start].dst = -1;
	dis_list[start].value = 0;
	edge_pq.push(Edge(start, start, 0));

	while (!edge_pq.empty())
	{
		Edge edge = edge_pq.top();
		edge_pq.pop();

		if (edge.dst == end)
			break;

		for (int i = 0; i < edges[edge.dst].size(); i++)
		{
			int value = edges[edge.dst][i].value + dis_list[edge.dst].value;
			index = edges[edge.dst][i].dst;
			if (dis_list[index].value <= value) {
				continue;
			}

			dis_list[index].value = value;
			dis_list[index].dst = edge.dst; //src는 전 값
			
			edge_pq.push(Edge(edge.dst, index, value));
		}
	}

	//출력
	cout << dis_list[end].value << '\n';

	stack<int> city_stack;
	index = end; 
	while (true)
	{
		if (index == -1)
			break;

		city_stack.push(index);
		index = dis_list[index].dst;
	}
	cout << city_stack.size() << '\n';

	while (!city_stack.empty())
	{
		index = city_stack.top();
		city_stack.pop();
		cout << index + 1 << ' ';
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int city_size, edge_size;
	int a, b, c;

	cin >> city_size >> edge_size;

	vector<Edge> edges[1001];

	for (int i = 0; i < edge_size; i++)
	{
		cin >> a >> b >> c;
		a--; b--;

		edges[a].push_back(Edge(a, b, c));
	}
	
	cin >> a >> b;
	a--; b--;

	shortest_path_dp(edges, a, b, city_size);
}