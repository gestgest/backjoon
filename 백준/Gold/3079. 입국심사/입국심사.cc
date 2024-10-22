#include <iostream>
#include <vector>
#include <algorithm>

#define INF 2147483647

#define MAX_TIME 1000000000

using namespace std;

vector<int> v;

int n;
long long m;

long long min(long long a, long long b)
{
	return a > b ? b : a;
}

long long sum_people(long long time)
{
	long long count = 0;

	for (int i = 0; i < v.size(); i++)
	{
		count += time / v[i];
	}
	return count;
}

long long binary_search_check(long long start, long long end)
{
	if (start > end) {
		return start;
	}
	long long mid = (start + end) / 2;

	long long num = sum_people(mid);

	//해결된 사람이 너무 많다면 => 시간이 너무 많다면
	if (num >= m) {
		//줄이기
		return min(binary_search_check(start, mid - 1), mid);
	}
	//사람이 적다면 => 시간이 적다면
	else {
		return binary_search_check(mid + 1, end);
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);


	//입국 심사대 n, 학생
	cin >> n >> m;
	v = vector<int>(n);

	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	sort(v.begin(), v.end());

	//이분탐색
	cout << binary_search_check(1, m * v[0]) << '\n';
}
