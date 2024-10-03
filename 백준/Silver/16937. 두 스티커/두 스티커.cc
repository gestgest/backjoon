#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Point {
public:
	int pos[2];
	Point(int x, int y) {
		this->pos[0] = x;
		this->pos[1] = y;
	}
	int getArea(Point point)
	{
		return pos[0] * pos[1] + point.pos[0] * point.pos[1];
	}

	int areaCal(Point& range, Point& point) {
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				for (int k = 0; k < 2; k++)
				{
					//아니라면
					//range.x >= x + point.x && range.
					if (range.pos[k] < point.pos[i] + pos[j])
					{
						continue;
					}
					//또 다른 포지션이 범주안에 있다면
					if (range.pos[(k + 1) % 2] >= point.pos[(i + 1) % 2] && range.pos[(k + 1) % 2] >= pos[(j + 1) % 2])
					{
						return getArea(point);
					}
					
				}
			}
		}
		return 0;
	}
};

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	int width, height;
	int x, y;
	int max_value = 0;

	cin >> width >> height;
	Point range(width, height);
	cin >> n;

	vector<Point> points;
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;
		points.push_back(Point(x, y));
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			int num = points[i].areaCal(range, points[j]);
			if (max_value < num) 
			{
				max_value = num;
			}

		}
	}

	cout << max_value << '\n';
	

}