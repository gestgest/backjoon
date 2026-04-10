#include <iostream>
#include <vector>
#include <algorithm>

#define INF 2147483647

using namespace std;

//18 24 => 6

//24 18
long long gcd(long long a, long long b)
{
	if (a == 0)
	{
		return b;
	}
	return gcd(b % a, a);
}

//20억 언저리
long long getValue(vector<int>& s, int start, int end)
{
	//0 5 => 6. [0 1 2 | 3 4 5]
	// 0 1 2 
	//0 1 => 2 [0 | 1]
	//
	int index = end - start + 1;

	if (index <= 0)
	{
		return 0;
	}

	//하나라면
	if (index == 1)
	{
		return s[start];
	}
	int left_size = index / 2;
	int right_size = index / 2;
	if (index % 2 == 1) right_size++;

	long long left = s[start];
	long long right = s[end];

	//왼쪽값
	for (int i = 0; i < left_size; i++)
	{
		left = gcd(left, s[start + i]);
	}

	//오른쪽 값
	for (int i = 0; i < right_size; i++)
	{
		right = gcd(right, s[end - i]);
	}

	left += getValue(s, start + left_size, end);
	right += getValue(s, start, end - right_size);

	return max(left, right);
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> s = vector<int>(n);

	//입력
	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
	}
	
	cout << getValue(s, 0, n - 1) << '\n';
}
//6
//40 20 10 5 18 24
//