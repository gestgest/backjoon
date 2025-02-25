#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Process {
	int memory;
	int cost;
};

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	//DP

	//n은 앱 갯수, m은 얻어야 하는 메모리 갯수
	int n, m;
	vector<Process> process_list;
	vector<int> dp;
	int sum = 0;

	//c는 오른쪽
	//값은 메모리값? [메모리 값이 최대한 커야함]
	//예를 들어 c = 3이고 메모리는 20이면
	//0 0 0 20 20 20 20
	//c = 0, 메모리 10이면
	//10 10 10 40 
	//즉 c 인덱스부터 값[index - c] + > 기존값인 경우 

	cin >> n >> m;
	process_list = vector<Process>(n);

	for (int i = 0; i < n; i++)
	{
		cin >> process_list[i].memory;
	}

	for (int i = 0; i < n; i++)
	{
		cin >> process_list[i].cost;
		sum += process_list[i].cost;
		
	}
	dp = vector<int>(sum+ 1, 0);

	for (int i = 0; i < n; i++)
	{
		for (int j = sum; j >= process_list[i].cost; j--)
		{
			int value = dp[j - process_list[i].cost] + process_list[i].memory;
			if (value > dp[j]) {
				dp[j] = value;
			}
		}
	}

	for (int i = 0; i <= sum; i++)
	{
		if (dp[i] >= m)
		{
			cout << i << '\n';
			return 0;
		}
	}
}