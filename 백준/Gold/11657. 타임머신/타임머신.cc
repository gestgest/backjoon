#include <iostream>
#include <vector>
#include <algorithm>

#define INF 2147483647
using namespace std;


class Edge {
public:
	int src;
	int dst;
	long long value;
	Edge(){}
	Edge(int src, int dst, long long value)
	{
		this->src = src;
		this->dst = dst;
		this->value = value;
	}
};

bool bf(vector<Edge>& edges, vector<long long> & dis, int v, int e)
{
	for (int i = 1; i < v; i++)
	{
		dis[i] = INF;
	}

	dis[0] = 0;

	//ve 개수만큼 돌리는게 포인트
	//최대 300만 * -만 -300억
	for (int i = 0; i <= v; i++)
	{
		//간선 돌리기
		for (int j = 0; j < e; j++)
		{
			Edge edge = edges[j];
			if (dis[edge.src] != INF)
			{
				long long value = dis[edge.src] + edge.value;

				if (dis[edge.dst] > value) {
					dis[edge.dst] = value;
					if (v == i) {
						return false;
					}
				}

			}
		}
	}

	return true;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	// 1<= city <= 500, 1 <= bus <= 6000
	int city, bus;
	int src, dst, value;

	//벡터 우선순위 큐

	cin >> city >> bus;
	vector<Edge> edges = vector<Edge>(bus);
	vector<long long> dis = vector<long long>(city);

	//하나의 길에는 여러개의 노선이 있을 수도 있다.
	for (int i = 0; i < bus; i++)
	{
		cin >> src >> dst >> value;
		src--; dst--;
		edges[i].src = src;
		edges[i].dst = dst;
		edges[i].value = value;
	}

	if (bf(edges, dis, city, bus)) 
	{
		for (int i = 1; i < city; i++)
		{
			if (dis[i] == INF)
			{
				cout << "-1";
			}
			else {
				cout << dis[i];
			}
			cout << '\n';
		}
	}
	else {
		cout << "-1";
	}
}