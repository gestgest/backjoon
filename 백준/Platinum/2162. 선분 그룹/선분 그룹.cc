#include <iostream>
#include <vector>
#include <algorithm>

#define INF 2147483647

using namespace std;

vector<int> union_edges;

class Point {
public:
	int x;
	int y;

	Point operator - (Point& point)
	{
		Point result;

		result.x = this->x - point.x;
		result.y = this->y - point.y;
		return result;
	}

	bool operator > (Point& point) {
		if (this->x > point.x) {
			return true;
		}
		else if(this->x < point.x) {
			return false;
		}
		return this->y > point.y;
	}
};

class Edge {
public:
	Point point[2];
	Point value;

	void inputEdge()
	{
		cin >> point[0].x;
		cin >> point[0].y;
		cin >> point[1].x;
		cin >> point[1].y;

		//point 정렬
		if (point[0] > point[1]) {
			Point tmp = point[1];
			point[1] = point[0];
			point[0] = tmp;
		}

		value = point[1] - point[0];
	}
};

int ccw(Point point1, Point point2) 
{
	int num = point1.y * point2.x - point1.x * point2.y;

	if (num > 0) {
		return 1;
	}
	else if (num == 0) {
		return 0;
	}
	return -1;

}

//만난다
bool isMeet(Edge edge1, Edge edge2)
{
	if (ccw(edge1.value, edge1.point[1] - edge2.point[0]) * ccw(edge1.value, edge1.point[1] - edge2.point[1]) > 0) {
		return false;
	}
	if (ccw(edge2.value, edge2.point[1] - edge1.point[0]) * ccw(edge2.value, edge2.point[1] - edge1.point[1]) > 0) {
		return false;
	}
	//같은 기울기지만 만나지 않는 점도 고려
	if (edge2.point[0] > edge1.point[1]) {
		return false;
	}
	if (edge1.point[0] > edge2.point[1]) {
		return false;
	}

	return true;
}

int find_union(int n)
{
	if (union_edges[n] == n) return n;
	return union_edges[n] = find_union(union_edges[n]);
}

void insert_union(int a, int b)
{
	a = find_union(a);
	b = find_union(b);

	if (a > b) {
		union_edges[a] = b;
	}
	else {
		union_edges[b] = a;
	}
}


int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	union_edges = vector<int>(n);
	vector<int> union_count = vector<int>(n, 0);
	vector<Edge> edges = vector<Edge>(n);

	for (int i = 0; i < n; i++)
	{
		union_edges[i] = i;
		edges[i].inputEdge();
		for (int j = 0; j < i; j++)
		{
			// 만약 같은 그룹이라면
			if (find_union(i) == find_union(j)) {
				continue;
			}
			
			if (isMeet(edges[i], edges[j])) {
				//유니온
				insert_union(i, j);
			}

		}
	}

	int max_value = 0;
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		int index = union_edges[i];
		union_count[index]++;
		if (union_count[index] == 1)
		{
			count++;
		}
		if (union_count[index] > max_value) {
			max_value = union_count[index];
		}
	}

	cout << count << '\n';
	cout << max_value << '\n';
}
