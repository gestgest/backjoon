#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s;
	int n;
	long long sum = 0;
	long long tsum = 1;
	cin >> n;
	cin >> s;


	for (int i = 0; i < n; i++)
	{
		int num = s[i] - 'a' + 1;
		if (i != 0) {
			tsum *= 31;
		}
		sum += tsum * num;
		sum %= 1234567891;
	}
	cout << sum << '\n';
}