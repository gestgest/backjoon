#include <iostream>
#include <vector>
#include <algorithm>

#define INF 2147483647
#define POINT_SIZE 4

using namespace std;

class Point {
public:
	double x;
	double y;
	Point operator - (Point& point) {
		Point result;

		result.x = this->x - point.x;
		result.y = this->y - point.y;

		return result;
	}
	bool operator > (Point& point)
	{
		if (this->x > point.x) {
			return true;
		}
		else if (this->x < point.x) return false;
		if (this->y > point.y) return true;
		return false;

	}
	bool operator == (Point& point)
	{
		if (this->x != point.x)
			return false;
		if (this->y != point.y)
			return false;
		return true;
	}
};

int ccw(Point& a, Point& b)
{
	long long num = a.y * b.x - a.x * b.y;
	if (num < 0) {
		return -1;
	}
	else if (num == 0) return 0;
	return 1;
}

int ShowResult(Point points[4])
{
	//B A   B - C B - D
	Point edges[6];
	edges[0] = points[0] - points[1]; //B - A, B - D
	edges[1] = points[2] - points[1];
	edges[2] = points[3] - points[1];

	edges[3] = points[2] - points[3];
	edges[4] = points[0] - points[3];
	edges[5] = points[1] - points[3];
	//ccw
	if (ccw(edges[0], edges[1]) * ccw(edges[1], edges[2]) > 0) {
		return 0;
	}
	//ccw
	if (ccw(edges[3], edges[4]) * ccw(edges[4], edges[5]) > 0) {
		return 0;
	}
	if (points[2] > points[1] || points[0] > points[3]) {
		return 0;
	}

	return 1;
}

void crossDot(Point p[POINT_SIZE])
{
	double dx = (p[0].x * p[1].y - p[0].y * p[1].x) * (p[2].x - p[3].x) - (p[0].x - p[1].x) * (p[2].x * p[3].y - p[2].y * p[3].x);
	double dy = (p[0].x * p[1].y - p[0].y * p[1].x) * (p[2].y - p[3].y) - (p[0].y - p[1].y) * (p[2].x * p[3].y - p[2].y * p[3].x);
	double d = (p[0].x - p[1].x) * (p[2].y - p[3].y) - (p[0].y - p[1].y) * (p[2].x - p[3].x);

	if (d == 0) // 평행할 때
	{
		// 교점이 하나일 때
		if (p[1] == p[2]) cout << p[1].x << " " << p[1].y << '\n';
		else if (p[0] == p[3]) cout << p[0].x << " " << p[0].y << '\n';
	}
	else // 교차할 때
	{
		double x = dx / d;
		double y = dy / d;

		cout << fixed;
		cout.precision(9);
		cout << x << " " << y;
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cout.precision(9); //cout의 소수점 범위를 10자리까지 늘린다. 4은 3.1415

	Point points[POINT_SIZE];

	for (int i = 0; i < POINT_SIZE; i++)
	{
		cin >> points[i].x >> points[i].y;
		if (i % 2 == 1)
		{
			if (points[i - 1] > points[i])
			{
				Point tmp = points[i];
				points[i] = points[i - 1];
				points[i - 1] = tmp;
			}
		}
	}

	int n = ShowResult(points);
	cout << n << '\n';

	if (n != 0)
	{
		crossDot(points);
	}

}