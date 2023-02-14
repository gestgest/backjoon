#include <iostream>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, k;
	int num;
	int sum;

	cin >> n >> k;
	int* s = new int[n];

	cin >> num;
	s[0] = num;

	for (int i = 1; i < n; i++)
	{
		cin >> num;
		s[i] = s[i - 1] + num;
	}

	int max = s[k - 1];
	for (int i = 0; k + i < n; i++)
	{
		num = s[k + i] - s[i];
		if (max < num) {
			max = num;
		}
	}

	cout << max << '\n';

	delete[] s;
}