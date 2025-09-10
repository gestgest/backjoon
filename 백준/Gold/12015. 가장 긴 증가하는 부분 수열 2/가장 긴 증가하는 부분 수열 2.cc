#include <iostream>
#include <vector>

using namespace std;

#define INF 2147483647

vector<int> v;

int binary_search_index(int start, int end, int value)
{
	int mid;
	while (start <= end)
	{
		mid = (start + end) / 2;

		if (v[mid] < value)
		{
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}
	}
	return start;

}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, num;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> num;
		if (v.size() == 0)
		{
			v.push_back(num);
		}
		else if (v[v.size() - 1] < num)
		{
			v.push_back(num);
		}
		int index = binary_search_index(0, v.size() - 1, num);

		v[index] = num;
	}

	cout << v.size() << '\n';

}