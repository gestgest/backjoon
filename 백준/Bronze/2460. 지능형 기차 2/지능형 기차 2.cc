#include <iostream>
#include <algorithm>

using namespace std;

#define INF 2147483647


int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	//최대 만명. 정원 초과할 수 없다.
	
	int max_value = 0;
	int a, b;
	int sum = 0;

	for (int i = 0; i < 10; i++)
	{
		cin >> a >> b;

		sum += b;
		sum -= a;
		sum = min(10000, sum);

		max_value = max(sum, max_value);
	}

	cout << max_value <<'\n';
}