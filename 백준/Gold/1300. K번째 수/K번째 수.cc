#include <iostream>
#include <vector>
#include <algorithm>

#define INF 2147483647

using namespace std;

int n;
int k;

//div 4
//1 2 3 
//2 4 6     => 안되는 숫자 = min((div / (i + 1)), n)
//3 6 9

//4, 6등
//6, 8등


//div = 4, sum = 4. 순위는  (n * n + 1 - sum) => 6. 4 / 6
// div = 5, sum = 3
//div = 6, sum = 3 순위는 3. 순위는 7. => 7, 최대한 오른쪽으로
long long cal_rank(int div)
{
	long long sum = 0; //div 앞에 있는 숫자 => 
	for (int i = 1; i <= n; i++)
	{
		sum += min(div / i, n);
	}

	return sum;
}


//이분탐색
int binary_search_div(int start, int end)
{
	if (start > end)
	{
		return start;
	}

	int mid = (start + end) / 2;
	long long rank = cal_rank(mid);

	if (rank >= k) {
		return binary_search_div(start, mid - 1);
	}
	else {
		return binary_search_div(mid + 1, end);
	}
	
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> k;

	cout << binary_search_div(1, k) << '\n';


	/*
	1 2 3
	2 4 6
	3 6 9
	*/


}
