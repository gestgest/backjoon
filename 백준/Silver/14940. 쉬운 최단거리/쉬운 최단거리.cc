#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define INF 2147483647

using namespace std;

int s[1000][1000];
int graph[1000][1000];

int width, height;

struct Point {
	int x;
	int y;
};
typedef struct Distance {
	Point point;
	int dis;
};

void bfs(Point start_point)
{
	Point points[4] = { {0, 1} , {0 , -1} ,{1, 0}, {-1, 0} };
	queue<Distance> dis_queue = queue<Distance>();
	
	int dis = 0;
	dis_queue.push(Distance{ start_point, dis });
	graph[start_point.y][start_point.x] = dis;
	while (!dis_queue.empty()) 
	{
		Distance distance = dis_queue.front();
		dis_queue.pop();

		//상하좌우
		for (int i = 0; i < 4; i++)
		{
			Point point = Point{ distance.point.x + points[i].x, distance.point.y + points[i].y };

			if (point.x < 0 || point.x >= width)
			{
				continue;
			}
			if (point.y < 0 || point.y >= height)
			{
				continue;
			}

			dis = graph[point.y][point.x];
			//
			if (dis != -1)
			{
				//graph[point.y][point.x] = 0;
				continue;
			}
			//이후 queue에 포인트 넣기
			dis_queue.push(Distance{ point, distance.dis + 1 });
			graph[point.y][point.x] = distance.dis + 1;
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	Point start_point;

	cin >> height >> width;

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			cin >> s[i][j];
			//if 2면 스타트 포지션 저장
			if (s[i][j] == 2) {
				start_point.y = i;
				start_point.x = j;
			}
			else if (s[i][j] == 0)
			{
				graph[i][j] = 0;
			}
			else {
				graph[i][j] = -1;
			}
		}
	}
	//bfs

	bfs(start_point);

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			cout << graph[i][j] << ' ';
		}
		cout << '\n';
	}
}
