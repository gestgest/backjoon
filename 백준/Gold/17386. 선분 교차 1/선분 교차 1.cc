#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define INF 2147483647

class Point {
public:
	long long x;
	long long y;
	Point()
	{

	}
	Point(long long x, long long y)
	{
		this->x = x;
		this->y = y;
	}
	Point operator - (Point &point)
	{
		Point p(this->x - point.x, this->y - point.y);
		return p;
	}
	//음수면 
	int productDot(Point& point)
	{
		//대충 음수면 
		long long result = this->x * point.y - this->y * point.x;
		if (result == 0)
		{
			return 0;
		}
		else if (result > 0)
		{
			return 1;
		}
		else {
			return -1;
		}
		
	}
};

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	vector<Point> inputs;
	vector<Point> edges;

	for (int i = 0; i < 4; i++)
	{
		long long x, y;
		cin >> x >> y;

		inputs.push_back(Point(x, y));

	}

	edges.push_back(Point(inputs[1] - inputs[0]));
	edges.push_back(Point(inputs[2] - inputs[1]));
	edges.push_back(Point(inputs[3] - inputs[1]));

	edges.push_back(Point(inputs[3] - inputs[2]));
	edges.push_back(Point(inputs[0] - inputs[3]));
	edges.push_back(Point(inputs[1] - inputs[3]));

	int num1 = edges[0].productDot(edges[1]) * edges[0].productDot(edges[2]);
	int num2 = edges[3].productDot(edges[4]) * edges[3].productDot(edges[5]);

	//음수 양수 => 시계 반시계
	if (num1 > 0 || num2 > 0)
	{
		cout << 0 << '\n';
	}
	//둘다 -1
	else {
		cout << 1 << '\n';
	}

	
	//v[0] -> v[1] 
	//v[1] -> v[2] 
	//v[1] -> v[3] 

	//v[2] -> v[3] 
	//v[3] -> v[0] 
	//v[3] -> v[1] 
}