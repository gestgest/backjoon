#include <iostream>
#include <map>
#include <iterator>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	int num;
	long sum = 0;

	cin >> n >> m;
	int* s = new int[n];
	map<long, long> other_map;
	
	cin >> num;
	num %= m;
	s[0] = num;
	other_map.insert(pair<int, int>(num, 1));

	for (int i = 1; i < n; i++)
	{
		cin >> num;

		num %= m;
		s[i] = (s[i - 1] + num) % m;

		if (other_map.count(s[i])) {
			other_map[s[i]]++;
		}
		else {
			other_map.insert(pair<int,int>(s[i], 1));
		}
	}

	map<long, long>::iterator it;
	for (it = other_map.begin(); it != other_map.end(); it++)
	{
		if (it->first == 0) {
			sum += it->second;
		}
		sum += (it->second) * (it->second - 1) / 2;
	}

	cout << sum << '\n';

}

//time over