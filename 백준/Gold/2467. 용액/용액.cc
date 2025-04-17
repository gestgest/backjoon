#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define INF 2147483647

//https://www.acmicpc.net/problem/2467
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, num;

	cin >> n;

	int min_value = INF;
	vector<int> v = vector<int>(n);

	//투포인터
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	int start = 0, end = n - 1;
	int result_start = 0, result_end = n - 1;
	while (start < end)
	{
		num = v[start] + v[end];

		//값 차이가 적다면
		if (abs(num) < min_value)
		{
			min_value = abs(num);
			result_start = start;
			result_end = end;

			if (num == 0) {
				break;
			}
		}

		//합한 값이 작다면
		if (num < 0)
		{
			start++;
		}
		else
		{
			end--;
		}
	}

	cout << v[result_start] << ' ' << v[result_end] << '\n';
}