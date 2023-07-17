#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int min(int a, int b)
{
	if (a < b) {
		return a;
	}
	else {
		return b;
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;
	int  start = 1, end = k;
	int result = k;

	while (start <= end)
	{
		int mid = (start + end) / 2;
		int sum = 0;
		for (int i = 1; i <= n; i++)
		{
			sum += min(mid / i, n);

			if (mid < i) {
				break;
			}
		}
		if (sum < k) //-> 
		{
			start = mid + 1;
		}
		else if(k <= sum) {
			end = mid - 1;
			result = min(result, mid);
		}
	}

	cout << result << '\n';

	/*
	vector<int> v;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			v.push_back(i * j);
		}
	}
	sort(v.begin(), v.end());

	cout << v[k - 1] << '\n';
	*/
}