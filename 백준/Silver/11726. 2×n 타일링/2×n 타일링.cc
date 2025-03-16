#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;

	cin >> n;

	int dp[2] = {2, 1}; // [i - 1] + [i - 2]

	for (int i = 3; i <= n; i++)
	{
		dp[i % 2] = (dp[(i - 1) % 2] + dp[(i - 2) % 2]) % 10007;
	}
	cout << dp[n % 2] % 10007 << '\n';
	
}