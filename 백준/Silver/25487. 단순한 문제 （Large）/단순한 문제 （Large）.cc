#include <iostream>
using namespace std;


int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	int a, b, c;

	cin >> n;
	while (n--)
	{
		cin >> a >> b >> c;
		int min, max;

		min = a;

		if (b < min) {
			min = b;
		}
		if (c < min) {
			min = c;
		}

		cout << min << '\n';
	}

}