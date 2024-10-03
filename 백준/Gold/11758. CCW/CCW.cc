#include <iostream>
#include <vector>

#define INF 2147483647

using namespace std;

class Point {
public:
	int x;
	int y;

	Point(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
	Point operator-(Point& point) {
		return Point(this->x - point.x, this->y - point.y);
	}
	int crossProduct(Point edge) {
		int num = this->y* edge.x - this->x * edge.y;
		if (num == 0) {
			return 0;
		}
		else if (num > 0) {
			return -1;
		}
		return 1;
	}
};



int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int x, y;
	vector<Point> points;
	vector<Point> edges;

	for (int i = 0; i < 3; i++)
	{
		cin >> x >> y;
		points.push_back(Point(x, y));
	}
	edges.push_back(points[0] - points[1]);
	edges.push_back(points[1] - points[2]);

	int num = edges[0].crossProduct(edges[1]);
	cout << num << '\n';
	
}
