#include <iostream>
#include <vector>
#include <algorithm>

#define INF 2147483647

using namespace std;
vector<int> v1;
vector<int> v2;
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	//상근, 선영
	int n, m;
	int index = 0;
	int sum = 0;
	int a = 0, b = 0;
	v1 = vector<int>(1000005);
	v2 = vector<int>(1000005);

	while (true)
	{
		cin >> n >> m;
		a = 0; b = 0;
		sum = 0;

		if (n == m && n == 0)
		{
			break;
		}
		//상근이
		for (int i = 0; i < n; i++)
		{
			cin >> v1[i];
		}

		//상근이
		for (int i = 0; i < m; i++)
		{
			cin >> v2[i];
		}

		//선영이
		while(true)
		{
			if (a == n || b == m)
			{
				break;
			}
			if (v1[a] == v2[b])
			{
				a++;
				b++;
				sum++;
			}
			else if (v1[a] > v2[b])
			{
				b++;
			}
			else {
				a++;
			}
		}
		cout << sum << '\n';
	}
}
