#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
#define INF 2147483647

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	//제일 낮은거 두개
	//이후 또 낮은거 두개 합

	//우선순위 큐?

	int t,n;
	long long tmp;
	long long sum = 0;
	cin >> t;

	while (t--)
	{
		priority_queue<long long,vector<long long>, greater<long long>> hypecodes;
		sum = 0;
		
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> tmp;
			hypecodes.push(tmp);
		}

		while (hypecodes.size() > 1)
		{
			long long a = hypecodes.top();
			hypecodes.pop();

			long long b = hypecodes.top();
			hypecodes.pop();

			sum += a + b;
			//cout << "로꾸고 : " << a << " " << b << '\n';
			//cout << "로꾸고 : " << sum << '\n';

			hypecodes.push(a + b);
		}

		cout << sum << '\n';
	}
}