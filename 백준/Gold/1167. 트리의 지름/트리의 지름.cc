#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
#define INF 2147483647

class Edge {
public:
	int dst;
	int weight;

	Edge(int dst, int weight)
	{
		this->dst = dst;
		this->weight = weight;
	}
};
vector<Edge> v[100000];


//dj
void bfs(vector<int>& short_list, int n, int& max_index)
{
	queue<int> index_queue;
	index_queue.push(max_index);


	while (!index_queue.empty())
	{
		int index = index_queue.front();
		index_queue.pop();

		for (int i = 0; i < v[index].size(); i++)
		{
			Edge edge = v[index][i];

			if (short_list[edge.dst] > short_list[index] + edge.weight)
			{
				short_list[edge.dst] = short_list[index] + edge.weight;
				if (short_list[max_index] < short_list[edge.dst])
					max_index = edge.dst;

				index_queue.push(edge.dst);
			}
		}
	}
}

int bfs_index(int n, int start)
{

	vector<int> short_list(n, INF);

	short_list[start] = 0;
	int max_index = start;

	bfs(short_list, n, max_index);

	return max_index;
}

int bfs_value(int n, int start)
{
	vector<int> short_list(n, INF);

	short_list[start] = 0;
	int max_index = start;

	bfs(short_list, n, max_index);

	return short_list[max_index];
}


int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	int a, b, c;

	cin >> n;

	//e => n - 1의 두배?
	//임의의 start에 가고
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		a--;
		//set child
		while (true)
		{
			cin >> b;
			if (b == -1)
			{
				break;
			}
			b--;
			cin >> c;
			v[a].push_back(Edge(b, c));
		}
	}

	int start = bfs_index(n, 0);
	int r = bfs_value(n, start);

	cout << r << '\n';

}