#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int union_list[10001];

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

	const bool operator<(const Edge&edge) const&
	{
		return this->value > edge.value;
	}
};

int union_find(int n)
{
	if (n == union_list[n]) return n;
	return union_list[n] = union_find(union_list[n]);
}

void union_add(int a, int b)
{
	a = union_find(a);
	b = union_find(b);
	if (a < b) {
		union_list[b] = a;
	}
	else {
		union_list[a] = b;
	}
	
}

bool union_check(int a, int b)
{
	a = union_find(a);
	b = union_find(b);
	if (a == b)
		return true;
	else
		return false;
}

long long mst(priority_queue<Edge>& edge_queue, int n)
{
	long long sum = 0;

	while (!edge_queue.empty())
	{
		Edge edge = edge_queue.top();
		edge_queue.pop();

		//여기서 잘못됨, 유니온이랑 합쳐보자
		if (!union_check(edge.src, edge.dst))
		{
			union_add(edge.src, edge.dst);
			sum += edge.value;
		}

	}	

	return sum;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int node, edge_n;
	int src, dst, value; 
	cin >> node >> edge_n;
	priority_queue<Edge> edge_queue;

	for (int i = 0; i < edge_n; i++)
	{
		cin >> src >> dst >> value;

		edge_queue.push(Edge(src - 1, dst - 1, value));
	}
	for (int i = 0; i < node; i++)
	{
		union_list[i] = i;
	}

	cout << mst(edge_queue, edge_n);
}
//96%