#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int sum[10001] = { 0 };

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, k;
	int money;
	cin >> n >> k;
	//가로 k

	sum[0] = 1;
	for (int i = 0; i < n; i++)
	{
		cin >> money;

		for (int j = money; j <= k; j++)
		{
			sum[j] += sum[j - money];
		}
	}
	cout << sum[k] << '\n';

}