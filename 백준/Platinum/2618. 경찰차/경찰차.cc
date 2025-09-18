#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

#define INF 2147483647

class Point {
public:
	int x;
	int y;

	Point(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
	//point => before
	int cal_dis(Point& point)
	{
		return abs(this->x - point.x) + abs(this->y - point.y);
	}
};


vector<Point> input;
int dp[1001][1001];
int n, e;

int search_dp(int index1, int index2)
{
	//끝까지 간다면
	if (index1 == e || index2 == e)
	{
		return 0;
	}

	//만약 dp[5][3]이면 1번 경찰차는 5번째 2번 경찰차는 3번째에 있으니 그 아래부턴 중첩된다
	if (dp[index1][index2] != INF)
	{
		return dp[index1][index2];
	}
	int a, b, c;
	if (index1 < index2)
	{
		c = index2;
	}
	else {
		c = index1;
	}

	//index1++
	//경찰차1이 처음으로 움직인 경우
	if (index1 == 0)
	{
		Point left_point(0, 0);
		//인풋때문에 이렇게 if문으로 나눔
		a = search_dp(c + 1, index2) + input[c].cal_dis(left_point);
	}
	else 
	{
		a = search_dp(c + 1, index2) + input[c].cal_dis(input[index1 - 1]);
	}

	// index2++
	if (index2 == 0)
	{
		Point right_point(n - 1, n - 1);
		b = search_dp(index1, c + 1) + input[c].cal_dis(right_point);
	}
	else
	{
		b = search_dp(index1, c + 1) + input[c].cal_dis(input[index2 - 1]);
	}

	return dp[index1][index2] = min(a, b);
}

void reverse_dp(int index1, int index2)
{
	//끝까지 간다면
	if (index1 == e || index2 == e)
	{
		return;
	}
	int a, b, c;

	if (index1 < index2)
	{
		c = index2;
	}
	else {
		c = index1;
	}

	//index1++
	//경찰차1이 처음으로 움직인 경우
	if (index1 == 0)
	{
		Point left_point(0, 0);
		//인풋때문에 이렇게 if문으로 나눔
		a = dp[c + 1][index2] + input[c].cal_dis(left_point);
	}
	else
	{
		a = dp[c + 1][index2] + input[c].cal_dis(input[index1 - 1]);
	}

	// index2++
	if (index2 == 0)
	{
		Point right_point(n - 1, n - 1);
		b = dp[index1][c + 1] + input[c].cal_dis(right_point);
	}
	else
	{
		b = dp[index1][c + 1] + input[c].cal_dis(input[index2 - 1]);
	}

	if (a < b)
	{
		cout << 1 << '\n';
		reverse_dp(c + 1, index2);
	}
	else {
		cout << 2 << '\n';
		reverse_dp(index1, c + 1);
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int x,y;
	cin >> n;
	cin >> e;

	for (int i = 0; i < e; i++)
	{
		cin >> x >> y;

		x--; y--;
		input.push_back(Point(y,x));
		for (int j = 0; j < e; j++)
		{
			dp[i][j] = INF;
		}
	}

	cout << search_dp(0, 0) << '\n';

	//역추적
	reverse_dp(0, 0);
	
}

//2,3