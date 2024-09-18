#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

class Edge {
public:
	int index_a;
	int index_b;
	int dis;

	Edge(int index_a, int index_b, int dis)
	{
		this->index_a = index_a;
		this->index_b = index_b;
		this->dis = dis;
	}

	bool operator<(const Edge & edge) const {
		return this->dis > edge.dis;
	}
};

class Point {
public:
	int x;
	int y;
	Point(){}
	Point(int x, int y) {
		this->x = x;
		this->y = y;
	}
	Point operator + (Point point){
		Point result;

		result.x = this->x + point.x;
		result.y = this->y + point.y;

		return result;
	}
	bool isRange(Point range)
	{
		if (this->x < 0 || range.x <= this->x)
			return false;
		if (this->y < 0 || range.y <= this->y)
			return false;
		return true;
	}
	Point *operator += (Point point)
	{
		this->x += point.x;
		this->y += point.y;
		return this;
	}

};

void debug_land(int** s, int r, int c)
{
	//둥둥섬 연결
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cout << s[i][j] << ' ';
		}
		cout << '\n';
	}

}

int combine_land(int **s, int r, int c, int x, int y, int n)
{
	if (y >= r || x >= c || x < 0 || y < 0)
	{
		return -1;
	}
	if (s[y][x] != -1) {
		return -1;
	}
	s[y][x] = n;
	combine_land(s, r, c, x + 1, y, n); //아래로
	combine_land(s, r, c, x - 1, y, n); //왼쪽
	combine_land(s, r, c, x, y + 1, n); //오른쪽
	combine_land(s, r, c, x, y - 1, n); //위쪽
	return n;
}

void measure_dis_element(priority_queue<Edge>& pq, int** s, Point max_range, Point start, Point d_point, int land_num)
{
	//2. 최소한 다리의 길이는 2 이상
	int dis = 0;

	//y
	for (Point point = start + d_point; point.isRange(max_range); point += d_point)
	{
		if (land_num == s[point.y][point.x])
		{
			break;
		}
		if (s[point.y][point.x] != 0)
		{
			if (dis > 1) {
				pq.push(Edge(land_num - 1, s[point.y][point.x] - 1, dis));
			}
			return;
		}
		dis++;
	}
	//dis가 1 이하면 컷
}

void measure_dis(priority_queue<Edge>& pq, int** s, int r, int c, int x, int y)
{
	//2. 최소한 다리의 길이는 2 이상
	int land_num = s[y][x];
	int dis = 0;
	int num;
	Point start = Point(x, y);
	Point max_range = Point(c, r);

	// 왼쪽 오른쪽 북쪽 남쪽
	Point points[4] = { Point(-1,0), Point(1,0), Point(0,-1), Point(0, 1)};

	for (int i = 0; i < 4; i++)
	{
		measure_dis_element(pq, s, max_range, start, points[i], land_num);
	}
}


//유니온
int find_union(vector<int>& union_arr, int n)
{
	if (union_arr[n] == n) return n;
	return union_arr[n] = find_union(union_arr, union_arr[n]);
}

void insert_union(vector<int>& union_arr, int a, int b)
{
	a = find_union(union_arr, a);
	b = find_union(union_arr, b);

	if (a < b) {
		union_arr[b] = a;
	}
	else {
		union_arr[a] = b;
	}
}

bool isUnion(vector<int>& union_arr, int n)
{
	for (int i = 1; i < n; i++)
	{
		if (union_arr[0] != find_union(union_arr, union_arr[i])) {
			return false;
		}
	}
	return true;
}


int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	//다리 조건
	//1. 일직선
	// ㄴ 만약 일직선인데 결국 마지막에 꺾어서 섬으로 도착해도 안된다.
	// ㅇㅁㅁㅁㅁㅁ
	//           ㅇ
	// ㅇ 는 섬, ㅁ는 다리 => 이거 안됨
	
	//2. 최소한 다리의 길이는 2 이상
	
	//겉 좌표

	int r, c;
	int **s;
	int n = 1, tmp;
	int sum = 0;
	int index_a, index_b;
	priority_queue<Edge> pq;
	cin >> r >> c;

	s = new int* [r];
	for (int i = 0; i < r; i++)
	{
		s[i] = new int [c];
		for (int j = 0; j < c; j++)
		{
			cin >> s[i][j];
			if (s[i][j] == 1) {
				s[i][j] = -1;
			}
		}
	}
	
	//둥둥섬 연결
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			tmp = combine_land(s, r, c, j, i, n);
			if (n <= tmp) {
				n = tmp + 1;
			}
		}
	}
	
	//동서남북 확인
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (s[i][j] != 0) {
				measure_dis(pq, s, r, c, j, i);
			}
		}
	}

	n--;
	vector<int> union_arr = vector<int>(n);
	for (int i = 0; i < n; i++)
	{
		union_arr[i] = i;
	}

	//debug_land(s, r, c);

	//유니온
	while (true)
	{
		if (pq.empty())
		{
			break;
		}

		Edge edge = pq.top();
		pq.pop();

		index_a = find_union(union_arr, edge.index_a);
		index_b = find_union(union_arr, edge.index_b);
		if (index_a != index_b)
		{
			insert_union(union_arr, index_a, index_b);
			sum += edge.dis;
		}
	}

	if(isUnion(union_arr, n))
		cout << sum << '\n';
	else {
		cout << -1 << '\n';
	}


	for (int i = 0; i < r; i++)
	{
		delete s[i];
	}
	delete [] s;

}