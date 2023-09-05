#include <iostream>
#include <vector>
#include <algorithm>

#define DIV 1000000007
using namespace std;

long long binary_sqr(int k, int n) {
	if (n <= 1) {
		return k % DIV;
	}
	long long sum = 0;
	sum = binary_sqr(k, n / 2);
	sum = sum * sum % DIV;
	//홀수의 경우의 수
	if (n % 2 == 1) sum *= k;
	return sum %= DIV;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, k;
	long long sum = 1, b = 1;
	cin >> n >> k;

	if (n / 2 < k) {
		k = n - k;
	}
	//분자
	for(int i = 0; i < k; i++)
	{
		sum *= n - i;
		sum %= DIV;
	}
	for (int i = 2; i <= k; i++)
	{
		b *= i;
		b %= DIV;
	}
	//분모 [^(n - 2)]
	sum *= binary_sqr(b, DIV - 2);
	sum %= DIV;

	cout << sum << '\n';
}