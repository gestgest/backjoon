#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int n, k;
int dp[1001][1001] = {0};
int input[1001][2];

int cal_dis(int x1, int y1, int x2, int y2)
{
	return abs(x2 - x1) + abs(y2 - y1);
}

int max_value(int a, int b)
{
	return a > b ? a : b;
}
int min_value(int a, int b)
{
	return a < b ? a : b;
}

//in1은 0,0 경찰차의 마지막 input 인덱스, in2는 k,k 경찰차의 마지막 input 인덱스
//in1 => [0], in2 => [1]
int cal_dp(int in1, int in2) 
{
	int dis[2];

	//완료
	if (in1 == k || in2 == k)
		return 0;

	if (dp[in2][in1] != 0)
		return dp[in2][in1];

	int next = max_value(in1, in2) + 1;
	if (in1 == 0) {
		dis[0] = cal_dis(input[next][0], input[next][1], 1, 1); //0, 0에서 x,y
	}
	else {
		dis[0] = cal_dis(input[next][0], input[next][1], input[in1][0], input[in1][1]); //전 포지션에서 x,y
	}

	if (in2 == 0) {
		dis[1] = cal_dis(input[next][0], input[next][1], n, n); //n,n에서 x,y
	}
	else {
		dis[1] = cal_dis(input[next][0], input[next][1], input[in2][0], input[in2][1]); //전 포지션에서 x,y
	}
	
	dp[in2][in1] = min_value(cal_dp(next, in2) + dis[0], cal_dp(in1, next) + dis[1]);

	return dp[in2][in1];
}

void search_dp(int in1, int in2)
{
	int dis[2];
	if (in1 == k || in2 == k) {
		return;
	}

	int next = max_value(in1, in2) + 1;
	if (in1 == 0) {
		dis[0] = cal_dis(input[next][0], input[next][1], 1, 1); //0, 0에서 x,y
	}
	else {
		dis[0] = cal_dis(input[next][0], input[next][1], input[in1][0], input[in1][1]); //전 포지션에서 x,y
	}

	if (in2 == 0) {
		dis[1] = cal_dis(input[next][0], input[next][1], n, n); //n,n에서 x,y
	}
	else {
		dis[1] = cal_dis(input[next][0], input[next][1], input[in2][0], input[in2][1]); //전 포지션에서 x,y
	}

	if (dp[in2][next] + dis[0] < dp[next][in1] + dis[1]) {
		cout << "1" << '\n';
		search_dp(next, in2);
	}
	else {
		cout << "2" << '\n';
		search_dp(in1, next);
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> k;
	for (int i = 1; i <= k; i++)
	{
		cin >> input[i][0] >> input[i][1];
	}

	//최대치로 한번
	cout << cal_dp(0, 0) <<'\n';
	search_dp(0, 0);

	//디버그
	/*
	for (int i = 0; i < k; i++)
	{
		for(int j = 0; j < k; j++)
		{ 
			cout << dp[i][j] << ' ';
		}
		cout << '\n';
	}
	*/
}
//4%