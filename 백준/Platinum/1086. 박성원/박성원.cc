#include <iostream>
#include <vector>
#include <algorithm>

#define INF 2147483647
#define MAX_STRING_SIZE 51

using namespace std;

int n, k;
long long base = 1;
long long dp[1 << 15][100];
string s_tmps[15];
int value_string[15]; //나머지 값
int cache[MAX_STRING_SIZE];


//문자열을 나머지 값으로
long long stringToValue(string& s)
{
	long long sum = 0;
	for (int i = 0; i < s.size(); i++)
	{
		long long num1 = (s[i] - '0') % k;
		long long num2 = (cache[s.size() - 1 - i]); //캐시값 자체가 나누기 한 값

		sum += num1 * num2 % k;
		sum %= k;
		//만약 123 456이라면? => for문 j로 나누고 
		//((1 % k) * (100000 % k => 그 cache값으로 구분)) % k;
	}
	return sum;
}

long long dp_park(int value, int status)
{
	//long long num = stringToValue(s);

	if (status == (1 << n) - 1) 
	{
		return value == 0 ? 1 : 0; //나머지 값이 0이면 1, 나머지면 0
	}
	//나머지가 [101][2]인 애는 결국 똑같은 값이 나온다

	//한번이라도 지나갔다면 
	if (dp[status][value] != -1) {
		return dp[status][value];
	}

	dp[status][value] = 0; // 지나간 길 설정


	for (int i = 0; i < n; i++)
	{
		//이미 있다면
		if (status & (1 << i)) {
			continue;
		}
		//문자열 합체

		//value는 이미 k를 나눈 나머지 값
		int next_value = (value * cache[s_tmps[i].size()] % k + value_string[i]) % k;
		//7 + 008이라고 가정하면
		//value * cache[s_tmps[i].size()]는 (7 * (1000 % k))
		//+ value_string[i]는 8

		dp[status][value] += dp_park(next_value, status | (1 << i));
	}

	return dp[status][value];
}

//최대공약수
long long gcd(long long a, long long b)
{
	if (b == 0) {
		return a;
	}

	return gcd(b, a % b);
}

//모든 자릿수의 나머지 값을 수집
void makeCahce()
{
	int result = 1;
	for (int i = 0; i < MAX_STRING_SIZE; i++)
	{
		cache[i] = result;
		result *= 10;
		result %= k;
		//i = 0, i + 1번째 자리
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int status = 0;
	cin >> n;

	for (long long i = 0; i < n; i++)
	{
		cin >> s_tmps[i];
		base *= i + 1;
	}

	cin >> k;
	makeCahce();

	for (int i = 0; i < (1 << n); i++)
	{
		for (int j = 0; j < k; j++)
		{
			dp[i][j] = -1;
		}
	}
	for (int i = 0; i < n; i++)
	{
		value_string[i] = stringToValue(s_tmps[i]); //나머지 값
	}


	long long num = dp_park(0, 0);
	if (num == 0) {
		cout << "0/1" << '\n';
	}
	else {
		long long gg = gcd(num, base);
		cout << num / gg << "/" << base / gg << '\n';
	}
}
