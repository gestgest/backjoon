#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>

#define MAX_VERTEX_SIZE 20001
#define INF 2147483647

using namespace std;


int score[MAX_VERTEX_SIZE];


class Edge {
public:
	int dst;
	int value;
	Edge() {

	}
	Edge(int dst, int value) {
		this->dst = dst;
		this->value = value;
	}
	//오름차순
	bool operator < (const Edge & edge) const
	{
		//유지가 false, change가 true
		return this->value > edge.value;
	}
};


//우선순위에 나오는 값 출력, 단 이미 score가 고정된 edge는 제외
Edge getMinEdge(priority_queue<Edge> &pq)
{
	while (true)
	{
		if (pq.empty())
		{
			return Edge(-1, -1);
		}
		Edge edge = pq.top();
		pq.pop();

		if (score[edge.dst] == INF)
		{
			score[edge.dst] = edge.value;

			return edge;
		}
	}
}

void dj(vector<vector<Edge>> &graph, int start, int size)
{
	int index = start;
	score[start] = 0;

	priority_queue<Edge> graph_pq;

	while (true)
	{
		//graph 에 있는 edge들 pq에 넣기
		for (int i = 0; i < graph[index].size(); i++)
		{
			Edge tmp = graph[index][i];
			Edge edge(tmp.dst, score[index] + tmp.value);

			//그러고
			graph_pq.push(edge);
		}
		
		Edge edge = getMinEdge(graph_pq);
		
		if (edge.dst == -1) {
			break;
		}
		index = edge.dst;
		
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	
	int v, e;
	int start;


	cin >> v >> e;
	cin >> start;
	start--;

	for (int i = 0; i < v; i++)
	{
		score[i] = INF; //INF라는 뜻
	}

	vector<vector<Edge>> graph = vector<vector<Edge>>(v);
	

	//우선순위 큐
	for (int i = 0; i < e; i++)
	{
		int src, dst, w;
		cin >> src >> dst >> w; //u -> v [w]

		src--; dst--;
		
		graph[src].push_back(Edge(dst, w));
	}

	//맨 처음의 우선순위 큐만 pop, 이후 그 도착 인덱스의 경로를 확장
	// [ 자신의 score + 도착의 w ]
	//우선순위 큐 추가
	// 맨 처음 큐만 제거, isConst 고정
	dj(graph, start,v);

	for (int i = 0; i < v; i++)
	{
		if(score[i] != INF)
			cout << score[i] << '\n';
		else {
			cout << "INF" << '\n';
		}
	}
}