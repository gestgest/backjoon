#include <iostream>

using namespace std;

#define INF 2147483647

char space[500][500];
int row, col;


class Point {
public:
	int x;
	int y;

	Point(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
	Point operator+(Point& point)
	{
		return Point(this->x + point.x, this->y + point.y);
	}
};

Point getPoint(int index)
{
	if (index == 0) return Point(0, -1);
	if (index == 1) return Point(1, 0);
	if (index == 2) return Point(0, 1);
	if (index == 3) return Point(-1, 0);
}

//  거울 함수 => visited

bool isRange(Point point)
{
	if (point.x < 0 || point.y < 0)
	{
		return false;
	}
	if (row <= point.y || col <= point.x)
	{
		return false;
	}
	return true;
}
char getDP(Point &point)
{
	return space[point.y][point.x];
}

//dfs direction => 위 오른쪽 아래 왼
int dfs(Point start, int direction)
{
	int isVisited[500][500] = { 0 };
	int count = 0;
	int dir = direction;
	Point point = start;
	while (true)
	{
		point = getPoint(dir) + point;
		count++;

		//space over
		if (!isRange(point))
		{
			return count;
		}
		//black hall
		if (getDP(point) == 'C')
		{
			return count;
		}
		//거울이 2번을 넘어선 경우 => 
		if (getDP(point) == '/')
		{
			isVisited[point.y][point.x]++;
			if (isVisited[point.y][point.x] == 3)
			{
				return INF;
			}
			switch (dir)
			{
			case 0:
				dir = 1;
				break;
			case 1:
				dir = 0;
				break;
			case 2:
				dir = 3;
				break;
			case 3:
				dir = 2;
				break;
			}
		}
		else if (getDP(point) == '\\')
		{
			isVisited[point.y][point.x]++;
			if (isVisited[point.y][point.x] == 3)
			{
				return INF;
			}

			switch (dir)
			{
			case 0:
				dir = 3;
				break;
			case 1:
				dir = 2;
				break;
			case 2:
				dir = 1;
				break;
			case 3:
				dir = 0;
				break;
			}
		}
	}
	return count;
}


int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> row >> col;
	int x, y;

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cin >> space[i][j];
		}
	}

	//visited 사용해야함
	cin >> y >> x;
	int max_value = 0;
	int max_index = 0;
	y--; x--;
	for (int i = 0; i < 4; i++)
	{
		int num = dfs(Point(x,y), i);
		if (max_value < num)
		{
			max_value = num;
			max_index = i;
		}
	}

	switch (max_index)
	{
	case 0:
		cout << 'U' << '\n';
		break;
	case 1:
		cout << 'R' << '\n';
		break;
	case 2:
		cout << 'D' << '\n';
		break;
	case 3:
		cout << 'L' << '\n';
		break;
	}
	if (max_value == INF)
	{
		cout << "Voyager" << '\n';
	}
	else {
		cout << max_value << '\n';
	}
}