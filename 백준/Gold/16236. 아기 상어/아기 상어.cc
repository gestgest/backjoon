#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 2147483647

using namespace std;

class Point {
public:
	int x;
	int y;
	int dis = 0;
	Point() {}
	Point(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
	Point(int x, int y, int dis)
	{
		this->x = x;
		this->y = y;
		this->dis = dis;
	}
	Point operator + (Point &point)
	{
		Point result;
		result.x = this->x + point.x;
		result.y = this->y + point.y;
		result.dis = this->dis + point.dis;
		return result;
	}
	bool isBoundry(int n)
	{
		if (this->x >= n || 0 > this->x)
		{
			return false;
		}
		if (this->y >= n || 0 > this->y)
		{
			return false;
		}
		return true;
	}
	bool operator < (const Point & point) const & 
	{
		if (this->dis > point.dis)
		{
			return true;
		}
		else if (this->dis < point.dis)
		{
			return false;
		}
		if (this->y > point.y) //y
		{
			return true;
		}
		else if (this->y < point.y)
		{
			return false;
		}
		if (this->x > point.x) //x
		{
			return true;
		}
		return false;
	}
};

Point dir[4] = { Point(0,-1), Point(-1,0) , Point(1, 0) , Point(0, 1) };

class Player
{
	Point point;
	int food = 0;
public:
	int size = 2;
	void setPoint(int x, int y)
	{
		point.x = x;
		point.y = y;
	}
	void setPoint(int x, int y, int dis)
	{
		point.x = x;
		point.y = y;
		point.dis = dis;
	}
	Point getPoint()
	{
		Point result(point.x, point.y, point.dis);
		return result;
	}
	void addDis(int dis)
	{
		point.dis += dis;
	}
	void addFood()
	{
		food++;

		//꽉 찼다면
		if (food >= size)
		{
			food -= size;
			size++;
		}
	}
};

//
int bfs(int n, vector<vector<int>> & map, Player &player)
{
	int graph[20][20];
	priority_queue<Point> point_queue;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			graph[i][j] = -1;
		}
	}
	
	Point startPos(player.getPoint().x, player.getPoint().y);
	point_queue.push(startPos);
	
	while (!point_queue.empty())
	{
		Point point = point_queue.top();
		point_queue.pop();

		if (graph[point.y][point.x] != -1)
		{
			continue;
		}

		graph[point.y][point.x] = point.dis;

		//물고기 먹으면
		if (map[point.y][point.x] < player.size && 0 < map[point.y][point.x] != 0)
		{
			map[point.y][point.x] = 0; //냠냠
			player.addFood();
			player.setPoint(point.x, point.y, point.dis + player.getPoint().dis);
			return point.dis;
		}

		for (int i = 0; i < 4; i++)
		{
			Point tmp_point = point + dir[i];


			//크기 비교도. 크거나 작은 거
			if (tmp_point.isBoundry(n) && map[tmp_point.y][tmp_point.x] <= player.size)
			{

				//입력
				tmp_point.dis++;
				point_queue.push(tmp_point);
				
			}
		}
	}
	return 0;
}

void debugMap(int i, vector<vector<int>>& map, Point point)
{

	cout << "--------"<< i <<"번째 : " << point.dis << "--------" << '\n';
	for (int i = 0; i < map.size(); i++)
	{
		for (int j = 0; j < map[i].size(); j++)
		{
			if (point.x == j && point.y == i)
			{
				cout << "*" << ' ';
			}
			else {
				cout << map[i][j] << ' ';
			}
		}
		cout << '\n';
	}
	cout << "--------끝------------------" << '\n';
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, num;
	cin >> n;
	vector<vector<int>> map = vector<vector<int>>(n);
	//vector<Point> fishes[6];
	Player player;
	
	//for (int i = 0; i < 6; i++)
	//{
		//fishes[i] = vector<Point>();
	//}

	//map setting
	for (int i = 0; i < n; i++)
	{
		map[i] = vector<int>(n);
		for (int j = 0; j < n; j++)
		{
			cin >> num;
			map[i][j] = num;
			if (num == 9)
			{
				player.setPoint(j, i);
				map[i][j] = 0;
			}
		}
	}

	int i = 0;
	while (true)
	{
		i++;
		//1식사
		if (bfs(n, map, player) == 0)
		{
			break;
		}
		//debugMap(i, map, player.getPoint());
	}
	cout << player.getPoint().dis << '\n';

	//크기보다 크거나 같으면 못 먹음
	// 대신 크기가 같으면 지나갈 수 있음
	// 먹으면 먹이 스택이 쌓이고 size만큼 쌓이면 size++
	//가까운애 > 위 > 왼쪽
	//못 먹는애만 있다면 종료
	//처음 아기 상어 크기는 2

	//0은 빈칸
	//1~6 먹이의 크기
	//9는 아기상어(자신)
}