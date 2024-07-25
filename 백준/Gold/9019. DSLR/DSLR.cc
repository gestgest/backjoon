#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

#define NODE_SIZE 10000
#define INF 2147483647

using namespace std;

int dp[NODE_SIZE];

int register_left(int n)
{
	int other = n / 1000;
	n *= 10;

	n += other;
	n %= 10000;
	return n;
}

int register_right(int n)
{
	int other = n % 10;
	n /= 10;

	n += other * 1000;
	return n;
}

void register_left_fun(queue<int>& q, int n, int count)
{
	//L은 3번
	for (int i = 0; i < 3; i++)			
	{
		n = register_left(n);
		if (count + i + 1 < dp[n])
		{
			dp[n] = count + i + 1;
			q.push(n);
		}
	}
}
void register_right_fun(queue<int>& q, int n, int count)
{
	//R은 3번
	for (int i = 0; i < 3; i++)
	{
		n = register_right(n);
		if (count + i + 1 < dp[n])
		{
			dp[n] = count + i + 1;
			q.push(n);
		}
	}
}
void register_s_fun(queue<int>& q, int n, int count)
{
	int num;
	//S는 1

	num = n - 1 + 10000;
	num %= 10000;
	if (count + 1 < dp[num])
	{
		dp[num] = count + 1;
		q.push(num);
	}
	/*
	for (int i = 1; i < 10000; i++)
	{
		num = n - i + 10000;
		num %= 10000;
		if (count + i < dp[num])
		{
			dp[num] = count + i;
			q.push(num);
		}
	}
	*/
}
void register_d_fun(queue<int>& q, int n, int count)
{
	n *= 2;
	n %= 10000;
	if (count + 1 < dp[n])
	{
		dp[n] = count + 1;
		q.push(n);
	}
}


void _bfs(int start)
{
	dp[start] = 0;
	int count, n;

	queue<int> q;
	q.push(start);

	while (!q.empty())
	{
		n = q.front();
		q.pop();

		count = dp[n];

		//DSLR
		register_d_fun(q, n, count);
		register_s_fun(q, n, count);
		register_left_fun(q, n, count);
		register_right_fun(q, n, count);

	}
}

void reverse_dp(int end)
{
	int count = dp[end];
	if (count == 0)
	{
		return;
	}
	int num;

	num = register_right(end);
	if (dp[num] == dp[end] - 1) {
		reverse_dp(num);
		cout << "L";
		return;
	}

	num = register_left(end);
	if (dp[num] == dp[end] - 1) {
		reverse_dp(num);
		cout << "R";
		return;
	}

	num = (end + 1) % 10000;
	if (dp[num] == dp[end] - 1) {
		reverse_dp(num);
		cout << "S";
		return;
	}


	//무조건 여기서부터는 짝수여야 함
	num = end / 2;
	if (dp[num] == dp[end] - 1) {
		reverse_dp(num);
		cout << "D";
		return;
	}
	num = (end + 10000) / 2;
	if (dp[num] == dp[end] - 1) {
		reverse_dp(num);
		cout << "D";
		return;
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	int start, end;

	cin >> n;

	while (n--)
	{
		//초기화
		//memset(dp, INF, sizeof(int) * NODE_SIZE);
		for (int i = 0; i < NODE_SIZE; i++)
		{
			dp[i] = INF;
		}

		cin >> start >> end;

		_bfs(start);

		reverse_dp(end);
		cout << '\n';
	}

}