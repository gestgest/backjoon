#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define INF 2147483647

int binary_search_index_down(vector<long long>& v, int start, int end, long long value)
{
	int mid;
	while (start <= end)
	{
		mid = (start + end) / 2;
		//값을 올려야 함
		if (v[mid] < value)
		{
			start = mid + 1;
		}
		else { //down
			end = mid - 1;
		}
	}
	return start;
}
int binary_search_index_up(vector<long long>& v, int start, int end, long long value)
{
	int mid;
	while (start <= end)
	{
		mid = (start + end) / 2;
		//값을 올려야 함
		if (v[mid] <= value)
		{
			start = mid + 1;
		}
		else { //down
			end = mid - 1;
		}
	}
	return start; // + 1
}

void addVector(vector<long long>&v , int n)
{
	int num;

	cin >> num;
	v.push_back(num);
	for (int i = 1; i < n; i++)
	{
		cin >> num;

		//누적합
		v.push_back(v[i - 1] + num);
	}

	//모든 경우의 수 넣
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			v.push_back(v[j] - v[i]);
		}
	}

	sort(v.begin(), v.end());
}

void debug_v(vector<long long>& v)
{

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << ' ';
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	long long t;
	int n, m, num;
	long long sum = 0;
	vector<long long> a, b;
	cin >> t;

	cin >> n;
	addVector(a, n);

	cin >> m;
	addVector(b, m);


	for (int i = 0; i < a.size(); i++)
	{
		long long tmp = t - a[i];
		//tmp값인 b배열의 요소 갯수를 구하면 됨

		int start = binary_search_index_down(b, 0, b.size() - 1, tmp);
		int end = binary_search_index_up(b, 0, b.size() - 1, tmp); //! b.size() - 1를 b.size()로 함 => out of range
		num = end - start;

		//cout << num << '\n';
		sum += num;
	}

	cout << sum << '\n';

}

//b