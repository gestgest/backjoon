#include <iostream>
#include <vector>
#include <algorithm>

#define INF 2147483647

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, num;
	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		for (int j = 0; j < num; j++)
		{
			cout << '=';
		}
		cout << '\n';
	}
}

