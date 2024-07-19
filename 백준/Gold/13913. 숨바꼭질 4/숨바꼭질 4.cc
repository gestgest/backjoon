#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 2147483647
#define MAX_SIZE 100001 
using namespace std;

int dp[100001];

void addDp(queue<int>& q, int index, int value)
{
	if (index >= MAX_SIZE || index < 0)
	{
		return;
	}
	if (dp[index] <= value) {
		return;
	}
	dp[index] = value;
	q.push(index);
}

//bfs
void bfs(int start)
{
	dp[start] = 0;
	queue<int> q;
	q.push(start);

	while (!(q.empty()))
	{
		int index = q.front();
		q.pop();

		addDp(q, index + 1, dp[index] + 1);//음수라인은 무조건 for문?
		//i * 2
		for (int i = index * 2; i < MAX_SIZE; i *= 2)
		{
			if (dp[i] <= dp[i / 2] + 1)
				break;
			dp[i] = dp[i / 2] + 1;
			q.push(i);
		}
		//i - 1
		for (int i = index - 1; i >= 0; i--)
		{
			if (dp[i] <= dp[i + 1] + 1)
				break;
			dp[i] = dp[i + 1] + 1;
			q.push(i);
		}
	}

}

void backTracking(const int start, int index)
{
		if (start == index) {
		cout << index << ' ';
		return;
	}
	else if (index + 1 < MAX_SIZE && dp[index + 1] == dp[index] - 1) 
	{
		backTracking(start, index + 1);
		cout << index << ' ';
	}
	else if (index % 2 == 0 && dp[index / 2] == dp[index] - 1)
	{
		backTracking(start, index / 2);
		cout << index << ' ';
	}
	else
	{
		backTracking(start, index - 1);
		cout << index << ' ';
	}
}


int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int start, dst;

	cin >> start >> dst;
	
	for (int i = 0; i < MAX_SIZE; i++)
	{
		dp[i] = INF;
	}

	bfs(start);
	//-1 /2 +1를 해서 역추적

	
	cout << dp[dst] << '\n';
	backTracking(start, dst);
}
//7%