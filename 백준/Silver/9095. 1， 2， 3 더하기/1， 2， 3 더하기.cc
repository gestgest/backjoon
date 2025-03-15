#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t, n;
	int sum = 0;
	int count[10];


	count[0] = 1;
	count[1] = 2;
	count[2] = 4;
	//dp
	for (int i = 3; i < 10; i++)
	{
		count[i] = count[i - 1] + count[i - 2] + count[i - 3];
	}

	cin >> t;

	//수학? => 미리 다 팩토리얼 계산하고 값을 넣으면 바로 나오게 해야하나?
	//이런 이게 DP라니 
	while (t--)
	{
		cin >> n;
		cout << count[n - 1] << '\n';
	}
}