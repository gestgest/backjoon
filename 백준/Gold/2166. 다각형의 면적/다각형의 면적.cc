#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Point {
public:
	double x;
	double y;
	Point(double x, double y)
	{
		this->x = x;
		this->y = y;
	}
};

//ccw
double getArea(Point a, Point b, Point c)
{
	Point v1(b.x - a.x, b.y - a.y);
	Point v2(c.x - a.x, c.y - a.y);

	double result = (v1.y * v2.x) - (v1.x * v2.y);
	return result / 2;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cout.setf(ios::fixed); //정수도 소수점 아래 처리
	cout.precision(1); //cout의 소수점 범위를 10자리까지 늘린다. 4은 3.1415

	int n;
	double x, y;
	cin >> n;
	vector<Point> points;
	double sum = 0;

	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;
		points.push_back(Point(x, y));
	}

	for (int i = 1; i < n - 1; i++)
	{
		sum += getArea(points[0], points[i], points[i + 1]);
	}

	if (sum < 0)
		sum *= -1;

	cout << sum << '\n';
	
	//ccw


}