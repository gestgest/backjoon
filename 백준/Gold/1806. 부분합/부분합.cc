#include <iostream>
#include <vector>
#include <algorithm>

#define INF 2147483647

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;

	//투포인터 인덱스
	int start = 0, end = 0;
	

	long long sum = 0;
	int dis = INF;


	cin >> n >> m;
	vector<int> s = vector<int>(n);
	

	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
	}
	while (true)
	{
		//값이 아직 합 이상이 안됐을때
		if (sum < m)
		{
			if (n <= end)
			{
				break;
			}
			sum += s[end];
			end++;
		}
		//값이 충족이 됐을때
		else
		{
			sum -= s[start];
			start++;

			//저장
			if (end - start + 1 < dis)
			{
				dis = end - start + 1;
			}
		}
	}
	if (dis == INF)
		cout << 0 << '\n';
	else {
		cout << dis << '\n';
	}
}