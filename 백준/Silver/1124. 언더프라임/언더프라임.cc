#include <iostream>
#include <vector>
#include <algorithm>

#define INF 2147483647

using namespace std;

int s[100001] = { 0 };
bool primLine[100001] = { false };

//10만 * 10만 흠,,,
//1 까지도 해야하나
void addMul(int start, int end)
{
	for (int i = start; i <= end; i += start)
	{
		s[i] += 1;
	}
}

// 10000 
void addPow(int start, int end)
{
	//100000000
	//start가 50000이상이면 그때부터 이상해짐
	for (long long i = start; i <= end; i *= start)
	{
		primLine[i] = true;
	}
}

//dp
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int sum = 0;
	int a, b;
	//a <= 언더프라임 갯수 <= b
	cin >> a >> b;

	for (int i = 2; i <= b; i++)
	{
		//소수
		if (s[i] == 0)
		{
			addPow(i, b);
		}
		if (primLine[i])
		{
			addMul(i, b);
		}
	}

	//a ~ b 출력 계산
	for (int i = a; i <= b; i++)
	{
		//s[i] 값이 소수인 경우 => 값이 1인 경우
		if (s[s[i]] == 1)
		{
			sum++;
		}
	}
	cout << sum << '\n';
}

