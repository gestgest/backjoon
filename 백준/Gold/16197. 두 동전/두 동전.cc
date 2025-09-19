#include <iostream>
#include <vector>

using namespace std;

#define INF 2147483647
int row, col, min_value = INF;
int graph[21][21];


class Point
{
public:
	int x, y;
	Point() { }
	Point(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
	Point operator +(Point& point)
	{
		Point result(this->x + point.x, this->y + point.y);

		return result;
	}
	bool operator ==(Point& point)
	{
		return this->x == point.x && this->y == point.y;
	}
};


Point getDf(int index)
{
	if (index == 0)
		return Point(1, 0);
	else if (index == 1)
		return Point(-1, 0);
	else if (index == 2)
		return Point(0, 1);
	else
		return Point(0, -1);
}

// -1 바깥, 0 빈칸, 1 : 벽
int getDP(Point &point)
{
	if (point.x < 0 || point.y < 0) //밖
	{
		return -1;
	}
	if (col <= point.x || row <= point.y) //밖
	{
		return -1;
	}
	return graph[point.y][point.x];
}

//dfs?
//다 떨어지거나 11회 이상이거나 동전 겹치면
// back

void dfs(Point point1, Point point2, int count) //point1 => coin1
{
	if (count == 10)
	{
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		Point p1 = getDf(i) + point1;
		Point p2 = getDf(i) + point2;
		int num1 = getDP(p1);
		int num2 = getDP(p2);
		
		// 동시에 밖으로 나감
		if (num1 == -1 && num2 == -1)
		{
			continue; //나가
		}
		if (num1 == -1 || num2 == -1) //성공적
		{
			if (count + 1 < min_value)
				min_value = count + 1;
			continue;
		}
		if (num1 == 1) //벽이면 이동 x
		{
			p1 = point1;
		}
		if (num2 == 1) //벽이면 이동 x
		{
			p2 = point2;
		}
		if (p1 == p2) //코인겹쳐서 안됨
		{
			continue;
		}

		dfs(p1, p2, count + 1);
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);


	cin >> row >> col;
	vector<Point> points;
	string s;

	//무조건 동전은 두 개
	for (int i = 0; i < row; i++)
	{
		cin >> s;

		for (int j = 0; j < s.size(); j++)
		{
			switch (s[j])
			{
			case '#':
				graph[i][j] = 1;
				break;
			case 'o':
				graph[i][j] = 0;
				points.push_back(Point(j, i));
				break;
			case '.':
				graph[i][j] = 0;
				break;
			}
		}
	}
	dfs(points[0], points[1], 0);

	if (min_value == INF) {
		cout << -1 << '\n';
	}
	else {
		cout << min_value << '\n';
	}
}

