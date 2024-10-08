#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Point {
public:
	long long x;
	long long y;
	void InputPoint()
	{
		cin >> x >> y;
	}

	int ccw(Point & point) 
	{
		long long num = (this->y * point.x) - (this->x * point.y);

		if (num < 0) {
			return -1;
		}
		else if (num == 0) {
			return 0;
		}
		return 1;
	}

	Point operator-(Point &point){
		Point result;
		result.x = this->x - point.x;
		result.y = this->y - point.y;
		return result;
	}
};

bool isCheck(Point *edges)
{
	//양수 * 양수 또는 음수 * 음수 => 교차하는 선이 없음
	if (edges[0].ccw(edges[1]) * edges[0].ccw(edges[2]) > 0)
		return false;
	if (edges[3].ccw(edges[4]) * edges[3].ccw(edges[5]) > 0)
		return false;
	return true;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	Point p[2][2];

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			p[i][j].InputPoint();
		}
	}

	Point edges[6];
	edges[0] = p[0][0] - p[0][1]; //BA
	edges[1] = p[1][0] - p[0][1]; //BC
	edges[2] = p[1][1] - p[0][1]; //BD

	edges[3] = p[1][0] - p[1][1]; //DC
	edges[4] = p[0][0] - p[1][1]; //DA
	edges[5] = p[0][1] - p[1][1]; //DB

	//기울기 
	//만약 교차한다면 abc abd는 둘개중 무조건 하나는 양수, 음수가 된다
	//c는 무조건 위, d는 무조건 아래 => 외적이 무조건 갈릴 수 밖에 없다 => 시계방향, 반시계 방향

	if (isCheck(edges)) {
		cout << 1 << '\n';
	}
	else {
		cout << 0 << '\n';
	}

	//A - B - C : 시계
	//A - B - D : 시계
	// => 이거 부터가 둘다 같은 타입이라 합치지 않음

}