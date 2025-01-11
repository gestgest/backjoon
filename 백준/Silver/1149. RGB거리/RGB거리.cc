#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int rgb[2][3] = {0};
	int n, num;
	cin >> n;
	

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> num;
			rgb[(i + 1) % 2][j] = num + min(rgb[(i) % 2][(j + 1) % 3], rgb[(i) % 2][(j + 2) % 3]);
		}
	}
	int min_num = rgb[n % 2][0];
	for (int j = 1; j < 3; j++)
	{
		if (min_num > rgb[n % 2][j]) {
			min_num = rgb[n % 2][j];
		}
	}
	cout << min_num << '\n';
}