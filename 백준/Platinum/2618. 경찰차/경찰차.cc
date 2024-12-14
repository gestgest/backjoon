#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Point {
public:
	int x;
	int y;
	Point(int x, int y) {
		this->x = x;
		this->y = y;
	}
};

//dp는 [경찰차1_k_index][경찰차2_k_index]
int dp[1001][1001];

int n, w;
vector<Point> points;
vector<int> index_result;

int cal_dis(int old_x, int old_y, int new_x, int new_y)
{
	int x = abs(new_x - old_x);
	int y = abs(new_y - old_y);
	return x + y;
}

int dp_buttom_up(int index1, int index2)
{
	//다 했다면
	if (index1 == w || index2 == w)
	{
		return 0;
	}

	if (dp[index1][index2] != -1)
		return dp[index1][index2];

	dp[index1][index2] = 0;

	int next = max(index1, index2) + 1; //다음 사건
	int dis[2];

	if (index1 == 0) { //(1,1)
		dis[0] = cal_dis(1, 1, points[next].x, points[next].y);
	}
	else {
		dis[0] = cal_dis(points[index1].x, points[index1].y, points[next].x, points[next].y);
	}

	if (index2 == 0) { //(n,n)
		dis[1] = cal_dis(n, n, points[next].x, points[next].y);
	}
	else {
		dis[1] = cal_dis(points[index2].x, points[index2].y, points[next].x, points[next].y);
	}

	//min
	dp[index1][index2] = min(dp_buttom_up(next, index2) + dis[0], dp_buttom_up(index1, next) + dis[1]);
	return dp[index1][index2];
}


//역추적
void back_tracking(int index1, int index2)
{

	//다 했다면
	if (index1 == w || index2 == w)
	{
		return;
	}

	int next = max(index1, index2) + 1; //다음 사건
	int dis[2];

	if (index1 == 0) { //(1,1)
		dis[0] = cal_dis(1, 1, points[next].x, points[next].y);
	}
	else {
		dis[0] = cal_dis(points[index1].x, points[index1].y, points[next].x, points[next].y);
	}

	if (index2 == 0) { //(n,n)
		dis[1] = cal_dis(n, n, points[next].x, points[next].y);
	}
	else {
		dis[1] = cal_dis(points[index2].x, points[index2].y, points[next].x, points[next].y);
	}
	
	if (dp[next][index2] + dis[0] < dp[index1][next] + dis[1])
	{
		cout << 1 << '\n';
		back_tracking(next, index2);
	}
	else {
		cout << 2 << '\n';
		back_tracking(index1, next);
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	//경찰차 하나는 (1,1) 하나는 (n,n)
	int y, x;
	cin >> n >> w;

	//나중에 -1, 0으로 들어갔는지 아닌지 확인용도
	for (int i = 0; i < w; i++)
	{
		for (int j = 0; j < w; j++)
		{
			dp[i][j] = -1;
		}
	}

	points.push_back(Point(0, 0)); //간편한 계산을 위해 [0]은 쓰레기값
	for (int i = 0; i < w; i++)
	{
		cin >> y >> x;
		//(y, x)
		points.push_back(Point(x, y));
	}

	cout << dp_buttom_up(0, 0) << '\n';
	back_tracking(0, 0);

	//index_result 리버스로

}