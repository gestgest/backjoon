#include <iostream>
#include <stack>
#include <queue>
#include <deque>

using namespace std;

#define INF 2147483647

int binary_search_music(vector<int> & s, int start, int end, int value)
{
	int mid;
	while (start <= end)
	{
		mid = (start + end) / 2;
		if (s[mid] <= value)
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

	int n, q, num;
	cin >> n >> q;

	vector<int> s = vector<int>(n); 
	cin >> num;
	s[0] = num;

	for (int i = 1; i < n; i++)
	{
		cin >> num;
		s[i] = s[i - 1] + num;
	}

	for (int i = 0; i < q; i++)
	{
		cin >> num;
		num = binary_search_music(s, 0, n - 1, num);
		cout << num + 1 << '\n';
	}
}