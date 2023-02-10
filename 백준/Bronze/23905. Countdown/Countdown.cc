#include <iostream>
using namespace std;


int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);

	int t;
	cin >> t;

	for (int i = 1; i <= t; i++)
	{
		cout << "Case #" << i << ": ";

		int k, n;
		int countdown;
		int count;

		cin >> n >> k;

		count = 0;
		countdown = k;

		for (int j = 0; j < n; j++)
		{
			int number;
			cin >> number;

			if(number != countdown) {
				countdown = k;
			}
			if (number == countdown)
			{
				countdown--;
				if (countdown == 0)
				{
					count++;
					countdown = k;
				}
			}
		}
		cout << count << '\n';
	}

	return 0;
}
// 3 2 3 2 1 0