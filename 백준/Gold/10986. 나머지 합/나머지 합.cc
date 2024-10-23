#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m, num;
	long long count = 0;
	long long sum = 0;

	cin >> n >> m;
	//s[m]; => %값 넣기

	vector<long long> v = vector<long long>(m, 0);

	for (int i = 0; i < n; i++)
	{
		cin >> num;
		sum += num;

		v[sum % m]++;
	}
	
	//오버플로우?
	count += (v[0] + 1) * (v[0]) / 2;

	for (int i = 1; i < m; i++)
	{
		count += (v[i] - 1) * (v[i]) / 2;
	}

	cout << count << '\n';
	
}