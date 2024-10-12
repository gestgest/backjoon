#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

/*
void debug_bit(int my_bit)
{
	int n = 1;
	for (int i = 0; i < 20; i++)
	{
		if (my_bit & n) {
			cout << 1;
		}
		else {
			cout << 0;
		}
		n = n << 1;
	}
	cout << '\n';
}
*/

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, my_bit = 0, m;
	string s;
	cin >> n;

	while (n--)
	{
		cin >> s;
		if (s == "all") {
			my_bit = (1 << 21) - 1;
		}
		else if (s == "empty") {
			my_bit = 0;
		}
		else {
			cin >> m;
			m--;
			if (s == "add") {
				my_bit |= (1 << m);
			}
			else if (s == "remove") {
				my_bit &= ~(1 << m);
			}
			else if (s == "check") {
				if (my_bit & (1 << m)) {
					cout << 1 << '\n';
				}
				else {
					cout << 0 << '\n';
				}
			}
			else if (s == "toggle") {
				my_bit ^= (1 << m);
			}
		}
	}
}