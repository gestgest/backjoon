#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t;
	int rgb[3];
	cin >> t;

	while (t--)
	{
		double avgRGB[3] = { 0,0,0 };
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				cin >> rgb[j];
				avgRGB[j] += rgb[j];
			}
		}
		for (int j = 0; j < 3; j++)
		{
			avgRGB[j] /= 10;
			cout << (int)(avgRGB[j] + 0.5) << ' ';
		}

		cout << '\n';
	}
}