#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

bool isCheck(int s[], int div, int n)
{
	int num = s[0] % div;
	for (int i = 1; i < n; i++)
	{
		if (num != s[i] % div) {
			return false;
		}
	}
	return true;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	int* s;
	vector<int> v;

	cin >> n;

	s = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
	}

	sort(s, s + n);

	int num = s[1] - s[0];
	v.push_back(num);
	for (int i = 2; i <= sqrt(num); i++)
	{
		if (num % i == 0) {
			if (isCheck(s, i, n)) {
				cout << i << ' ';
			}
			if (i != num / i)
				v.push_back(num / i);
		}
	}
	for (int i = v.size() - 1; 0 <= i; i--)
	{
		if (isCheck(s, v[i], n)) {
			cout << v[i] << ' ';
		}
	}

	delete[] s;
}
//10