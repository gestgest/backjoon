#include <iostream>
#include <cmath>
#include <queue>

#define INF 2147483647

using namespace std;


class Point {
public:
	float x;
	float y;
	int index;
	Point(float x, float y, int index) {
		this->x = x;
		this->y = y;
		this->index = index;
	}
};


float getDis(Point& p1, Point& p2) {
	return sqrtf((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

class Edge {
public:
	float dis;
	int index1;
	int index2;

	Edge(float dis, int index1, int index2) {
		this->dis = dis;
		this->index1 = index1;
		this->index2 = index2;
	}

	const bool operator< (const Edge& edge) const {
		return this->dis > edge.dis;
	}
};


int find_union(vector<Point>& points, int n)
{
	if (points[n].index == n) return n;
	return points[n].index = find_union(points, points[n].index);
}

void insert_union(vector<Point>& points, int a, int b)
{
	a = find_union(points, a);
	b = find_union(points, b);

	if (a < b) {
		points[b].index = a;
	}
	else {
		points[a].index = b;
	}
}


int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cout.setf(ios::fixed); //정수도 소수점 아래 처리
	cout.precision(2); //cout의 소수점 범위를 10자리까지 늘린다. 4은 3.1415

	int n;
	float x, y;
	float sum = 0;
	cin >> n;

	priority_queue<Edge> pq_edge;
	vector<Point> points;

	//n^2 짜리 우선순위 큐
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;
		points.push_back(Point(x, y, i));

		//우선순위에 넣어 버리기
		for (int j = 0; j < i; j++)
		{
			pq_edge.push(Edge(getDis(points[i], points[j]), i, j));
		}
	}

	while (true)
	{
		if (pq_edge.empty())
		{
			break;
		}
		Edge edge = pq_edge.top();
		pq_edge.pop();

		//유니온 탐색 (만약 다르다면)
		if (find_union(points, edge.index1) != find_union(points, edge.index2))
		{
			insert_union(points, edge.index1, edge.index2);
			sum += edge.dis;
		}
	}

	cout << sum << '\n';
}
