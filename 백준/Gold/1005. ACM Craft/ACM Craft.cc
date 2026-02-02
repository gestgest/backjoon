#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define INF 2147483647

class Edge {
public:
	int src;
	int dst;
	Edge(int src, int dst)
	{
		this->src = src;
		this->dst = dst;
	}
};

int bfs(vector<vector<int>> & graph, vector<int> &building, vector<int> &count, int find_index)
{
	vector<int> v = vector<int>(count.size(), 0);
	queue<Edge> q;
	//전출차수 0인 노드 찾기
	for (int i = 0; i < count.size(); i++)
	{
		if (count[i] == 0)
		{
			q.push(Edge(i, i));
		}
	}

	//
	while (!q.empty())
	{
		Edge edge = q.front();
		q.pop();

		//진행 값 넣기
		count[edge.dst]--;
		
		//제일 큰 값 업그레이드
		if (v[edge.dst] < v[edge.src])
		{
			v[edge.dst] = v[edge.src];
		}

		//-1도 방지, 다 도착했을 경우
		if (count[edge.dst] <= 0)
		{
			v[edge.dst] += building[edge.dst];

			//그래프 탐색
			for (int i = 0; i < graph[edge.dst].size(); i++)
			{
				q.push(Edge(edge.dst, graph[edge.dst][i]));
			}
		}
	}

	return v[find_index];
}

//위상정렬
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t;
	int n, k;
	int a, b;
	cin >> t;

	while (t--)
	{
		cin >> n >> k;

		vector<int> building = vector<int>(n);
		vector<int> count = vector<int>(n, 0);
		vector<vector<int>> graph = vector<vector<int>>(n);
		int find_index;

		//건물 짓는 시간
		for (int i = 0; i < n; i++)
		{
			cin >> building[i];
		}

		//a -> b, 전입이 a, 전출이 b
		for (int i = 0; i < k; i++)
		{
			cin >> a >> b;
			a--; b--;

			graph[a].push_back(b);
			count[b]++;
		}

		cin >> find_index;
		find_index--;

		cout << bfs(graph, building, count, find_index) << '\n';
	}
}