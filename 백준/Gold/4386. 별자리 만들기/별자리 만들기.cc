#include <iostream>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

#define INF 2147483647

//그래프?를 가장한 유니온
class Point {
public:
	double x;
	double y;
	int union_index;
	Point(int union_index) 
	{
		this->union_index = union_index;
	}
	Point() {}

};

vector<Point> points;

int find_union(int index)
{
	if (points[index].union_index == index) return index;
	return points[index].union_index = find_union(points[index].union_index);
}

void add_union(int a, int b)
{
	a = find_union(a);
	b = find_union(b);

	if (a > b)
		points[a].union_index = b;
	else
		points[b].union_index = a;
}

//add
//

class Edge {
public:
	int start_index;
	int end_index;
	double dis;

	Edge(int start_index, int end_index, Point & a, Point & b)
	{
		this->start_index = start_index;
		this->end_index = end_index;

		dis = sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
	}
	bool operator < (const Edge& edge) const & 
	{
		return this->dis > edge.dis;
	}
};

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	double sum = 0;
	cin >> n;
	priority_queue<Edge> pq;

	//모든 edge를 만들자, 시작 인덱스, 도착 인덱스, dis
	//그리고 우선순위 큐?
	for (int i = 0; i < n; i++)
	{
		Point p(i);
		cin >> p.x >> p.y;
		points.push_back(p);
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			Edge edge(i, j, points[i], points[j]);
			pq.push(edge);
		}
	}

	while (!pq.empty())
	{
		Edge edge = pq.top();
		pq.pop();

		//다른 범주
		points[edge.start_index].union_index = find_union(points[edge.start_index].union_index);
		points[edge.end_index].union_index = find_union(points[edge.end_index].union_index);

		if (points[edge.start_index].union_index != points[edge.end_index].union_index)
		{
			add_union(edge.start_index, edge.end_index);
			sum += edge.dis;
		}
	}
	cout << sum << '\n';

	//지나간 길(isstart, isend
}