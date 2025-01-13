#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

double cal_dis(int x, int y)
{
	return sqrt(x * x + y * y);
}

double cal_time1(double dis, int t, int jump_dis)
{
	int n = floor(dis / jump_dis);

	return dis + n * (t - jump_dis);
}

double cal_time2(double dis, int t, int jump_dis)
{
	int n = ceil(dis / jump_dis);
	double num1 = n * t + abs(jump_dis - dis);

	if (n < 2) {
		n = 2;
	}
	if (num1 > n * t) {
		num1 = n * t;
	}

	return num1;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int x, y;
	int t, jump_dis;

	cout.setf(ios::fixed); //정수도 소수점 아래 처리
	cout.precision(10);

	cin >> x >> y >> jump_dis >> t;

	double dis = cal_dis(x, y);

	double dis_time, dis_time_tmp;
	dis_time = dis;

	dis_time_tmp = cal_time1(dis, t, jump_dis);
	if (dis_time_tmp < dis_time)
		dis_time = dis_time_tmp;

	dis_time_tmp = cal_time2(dis, t, jump_dis);
	if (dis_time_tmp < dis_time)
		dis_time = dis_time_tmp;


	cout << dis_time;
}