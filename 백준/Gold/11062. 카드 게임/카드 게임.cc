#include <iostream>
#include <vector>
#include <algorithm>

#define INF 2147483647

using namespace std;
int n;

//근우의 점수로 짜야한다
int dp[1001][1001];

//서로 최고의 경우의 수를 찾는 게 너무 힘들다

//left right => bottom up, left right는 마지막으로 꺼낸 left right index 번호
int cal_dp(vector<int> &input, int left, int right)
{
	if (left > right)
	{
		return 0;
	}

	if (dp[left][right] > 0)
	{
		return dp[left][right];
	}
	
	int right_index = n - 1 - right;

	//근우
	if ((right_index + left) % 2 == 0)
	{
		//왼쪽 or 오른쪽
		return dp[left][right] = max(cal_dp(input, left + 1, right) + input[left], cal_dp(input, left, right - 1) + input[right]);
		//max(cal_dp())
	}
	else //명우 => 명우 기준에서 큰 값을 골라야 한다 => 근우는 작아야 한다
		//=> 근우 기준으로 하는 dp표 기준으로 작아야 한다. => 그리고 근우 기준이니 인풋은 넣지않는다.[★]
	{
		//min(cal_dp())
		return dp[left][right] = min(cal_dp(input, left + 1, right), cal_dp(input, left, right - 1));
	}
}


int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t;

	cin >> t;

	while (t--)
	{
		//1000
		cin >> n;
		vector<int> input;
		int sum = 0;

		input = vector<int>(n);
		for (int i = 0; i < n; i++)
		{
			cin >> input[i];
			sum += input[i];
			for (int j = 0; j < n; j++)
			{
				dp[i][j] = 0;
			}
		}
		
		cout << cal_dp(input, 0, n - 1)<< '\n';
	}
}
