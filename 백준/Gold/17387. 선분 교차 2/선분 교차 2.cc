#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Point {
public:
	long long x, y;

	Point operator - (Point &point) {
		Point result;

		result.x = this->x - point.x;
		result.y = this->y - point.y;
		return result;
	}

	bool operator > (Point& point) {
		if (this->x > point.x)
			return true;
		if (this->x < point.x)
			return false;
		return this->y > point.y;
	}
};

int ccw(Point p1, Point p2) {
	long long num = p1.y * p2.x - p1.x * p2.y;
	if (num < 0) {
		return -1;
	}
	else if (num == 0) {
		return 0;
	}
	return 1;
}

bool ccw_check(Point edge1, Point edge2, Point edge3)
{
	if (ccw(edge1, edge2) * ccw(edge1, edge3) > 0)
	{
		return false;
	}
	return true;
}

int isCheck(Point points[2][2])
{
	Point edge[3];
	edge[0] = points[0][0] - points[0][1];
	edge[1] = points[1][0] - points[0][1];
	edge[2] = points[1][1] - points[0][1];


	if (!ccw_check(edge[0], edge[1], edge[2])) {
		return 0;
	}

	edge[0] = points[1][0] - points[1][1];
	edge[1] = points[0][0] - points[1][1];
	edge[2] = points[0][1] - points[1][1];
	if (!ccw_check(edge[0], edge[1], edge[2])) {
		return 0;
	}

	if (points[0][0] > points[1][1])
		return 0;
	if (points[1][0] > points[0][1])
		return 0;

	return 1;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	Point point[2][2];

	for (int i = 0; i < 2; i++) 
	{
		for (int j = 0; j < 2; j++)
		{
			cin >> point[i][j].x >> point[i][j].y;
		}

		//무조건 a가 작은 값
		if (point[i][0] > point[i][1]) {
			Point tmp = point[i][1];
			point[i][1] = point[i][0];
			point[i][0] = tmp;
		}
		
	}

	cout << isCheck(point) << '\n';



	//A - B - C
	//A - B - D
	//C - D - A
	//C - D - B

	//A - B - C
}
