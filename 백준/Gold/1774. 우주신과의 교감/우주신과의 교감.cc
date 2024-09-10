#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

#define INF 2147483647

using namespace std;

class Point {
public:
	int x;
	int y;
	int union_index;
	Point(int x, int y, int union_index) {
		this->x = x;
		this->y = y;
		this->union_index = union_index;
	}
};

class Edge {
public:
	double dis;
	int index1;
	int index2;
	Edge(double dis, int index1, int index2)
	{
		this->dis = dis;
		this->index1 = index1;
		this->index2 = index2;
	}
	const bool operator < (const Edge& edge) const {
		return this->dis > edge.dis;
	}
};

double getDis(Point& p1, Point& p2) {
	return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

int find_union(vector<Point> & points, int n)
{
	if (points[n].union_index == n) return n;
	return points[n].union_index = find_union(points, points[n].union_index);
}

//
void add_union(vector<Point>& points, int a, int b)
{
	a = find_union(points, a);
	b = find_union(points, b);

	if (a < b) {
		points[b].union_index = a;
	}
	else {
		points[a].union_index = b;
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cout.setf(ios::fixed); //정수도 소수점 아래 처리
	cout.precision(2); //cout의 소수점 범위를 10자리까지 늘린다. 4은 3.1415

	int n, continue_edge;
	int x, y;
	int index1, index2;
	double sum = 0;
	vector<Point> points;
	priority_queue<Edge> edge_pq;

	cin >> n >> continue_edge;

	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;
		points.push_back(Point(x, y, i));

		for (int j = 0; j < i; j++)
		{
			edge_pq.push(Edge(getDis(points[i], points[j]), i, j));
		}
	}
	for (int i = 0; i < continue_edge; i++)
	{
		cin >> index1 >> index2;
		index1--; index2--;

		add_union(points, index1, index2);
		//sum += getDis(points[index1], points[index2]);
	}

	while (true)
	{
		if (edge_pq.empty()) {
			break;
		}
		Edge edge = edge_pq.top();
		edge_pq.pop();

		if (find_union(points, edge.index1) != find_union(points, edge.index2)) {
			add_union(points, edge.index1, edge.index2);
			sum += edge.dis;
		}
	}

	cout << sum << '\n';
}
