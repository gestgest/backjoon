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
		if (sum < m) {

			if (end >= n) {
				break;
			}

			sum += s[end];
			end++;
		}
		else {
			//dis
			if (dis > end - start) {
				dis = end - start;
			}

			sum -= s[start];
			start++;
		}
	}

	if (dis == INF)
		cout << 0 << '\n';
	else {
		cout << dis << '\n';
	}
}