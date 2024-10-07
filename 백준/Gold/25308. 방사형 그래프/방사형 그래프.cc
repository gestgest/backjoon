#include <iostream>
#include <cmath>
#define MAX_SIZE 8

#define INF 2147483647

using namespace std;

class Point {
public:
	double x;
	double y;
	Point() {}

	//index = 1. y
	//index = 2. 루트x 루트y
	//index = 3. x
	Point(int index, int n) {
		switch (index) {
		case 1:
			this->x = 0;
			this->y = n;
			break;
		case 2:
			this->x = n * sqrt(2) / 2;
			this->y = n * sqrt(2) / 2;
			break;
		case 3:
			this->x = n;
			this->y = 0;
			break;
		}
	}
	
	int ccw(Point edge) {
		double num = this->y * edge.x - this->x * edge.y;
		if (num < 0) {
			return 1;
		}
		//직선이라면?
		return -1;
	}

	Point operator-(Point &point) {
		Point result;
		result.x = this->x - point.x;
		result.y = this->y - point.y;
		return result;
	}
};

int search_value(int n, int is_check[], int parent)
{
	//ischeck 탐색
	for (int i = 0; i < n; i++)
	{
		//is_check에 i가 없다면
		if (is_check[i] == parent) {
			return -1;
		}
	}
	return parent;
}

//재귀함수로 풀면 되지 않을까 list는 
int bf(int n, const int list[], int is_check[])
{
	if (n == MAX_SIZE) {
		//벡터 외적 계산 => child로

		for (int i = 0; i < MAX_SIZE; i++)
		{
			Point p1(1, list[is_check[i % MAX_SIZE]]);
			Point p2(2, list[is_check[(i + 1) % MAX_SIZE]]);
			Point p3(3, list[is_check[(i + 2) % MAX_SIZE]]);

			Point edge1 = p1 - p2;
			Point edge2 = p3 - p2;

			int num = edge1.ccw(edge2);
			if (num == -1) {
				return 0;
			}
		}
		return 1;
	}

	int result = 0;
	for (int i = 0; i < MAX_SIZE; i++)
	{
		int num = search_value(n, is_check, i);
		if (num == -1) {
			continue;
		}
		is_check[n] = num;
		result += bf(n + 1, list, is_check);
		//parent[]
		//bf
		//parent[]


		/*
		int child[MAX_SIZE];
		//얇은 복사
		for (int j = 0; j < n; j++)
		{
			child[j] = parent[j];
		}
		child[n] = list[i];
		
		result += bf(n + 1, list, child);
		list[i] = child[n];
		*/
	}
	return result;
}

//순열 알고리즘이 문제
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	//p2 p1, p2 p3의 내적이든 외적이 하나라도 방향이 이상하면 컷
	//ccw로 해결해보자
	int values[MAX_SIZE];
	int is_check[MAX_SIZE];
	int n;

	for (int i = 0; i < MAX_SIZE; i++)
	{
		cin >> values[i];
	}

	cout << bf(0, values, is_check) << '\n';

}
