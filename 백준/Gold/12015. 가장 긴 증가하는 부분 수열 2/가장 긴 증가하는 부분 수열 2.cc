#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;

int binary_search_v(int start, int end, int num)
{
	while (start <= end)
	{
		int mid = (start + end) / 2;

		if (num > v[mid])
		{
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}
	}
	return start;
}

void addDP(int num)
{
	//이분탐색
	if (v.size() == 0)
	{
		v.push_back(num);
		return;
	}
	if (v[v.size() - 1] < num)
	{
		v.push_back(num);
		return;
	}
	v[binary_search_v(0, v.size() - 1, num)] = num;
}


//dp
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, num;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		addDP(num);
	}
	cout << v.size() << '\n';
	
}