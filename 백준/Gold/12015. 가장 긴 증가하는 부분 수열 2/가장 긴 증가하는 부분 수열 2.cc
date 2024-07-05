#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int binary_index_search(vector<int> &s,int num)
{
	int start = 0, end = s.size() - 1;
	while (start <= end)
	{
		int mid = (start + end) / 2;

		if (s[mid] < num) {
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

	vector<int> s;

	int n;
	int number;
	cin >> n;

	while(n--)
	{
		cin >> number;
		int len = s.size();
		if(len == 0)
			s.push_back(number);
		//LIS 알고리즘
		else if (s[len - 1] < number) {
			s.push_back(number);
		}
		// 이분탐색을 이용한 LIS 알고리즘
		else {
			s[binary_index_search(s, number)] = number;
		}
	}
	cout << s.size() << '\n';

}