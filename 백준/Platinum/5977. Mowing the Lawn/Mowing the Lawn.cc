#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

#define INF 100000000000000

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	//소 갯수, 최소한 허용되는 연속 소 갯수
	//그러니까 연속 K를 넘어서면 안되는 듯 
	int n, k;
	int num;
	long long sum = 0;
	deque<int> myDeque; //인덱스 보관
	//e_i

	cin >> n >> k;

	//연속 갯수
	vector<long long> inputs = vector<long long>(n + 1, 0);
	vector<long long> dp = vector<long long>(n + 1, 0); // 그냥 최솟값으로 해서 psum - dp
	
	//long long


	//입력 : n번
	for (int i = 1; i <= n; i++)
	{
		cin >> inputs[i];
		sum += inputs[i];
	}

	myDeque.push_back(0);
	long long ret = INF;

	//[n % 2]
	for (int i = 1; i <= n; i++)
	{
		//왜 +1을 하는가 =>  +1를 안하면 나중에 어차피 dp[i - 1] 이런식으로 하나를 뺀다.
		while (!myDeque.empty() && i > myDeque.front() + 1 + k)
		{
			myDeque.pop_front();
		}

		dp[i] = dp[myDeque.front()] + inputs[i]; //일단 인풋넣기.


		// 예를 들어 dp[4]를 넣을땐 dp[1]값을 가져오고 + 입력값인데
		// dp[1]은 input1, 즉 input[1] + input[4]인데
		// 마지막언저리부터는 x를 생략해도 연속이 안 깨질 수 있으니 ret = min(ret, dp[i])가 되는거다.
		// 그래서 n - k라면 3부터 5까지는 3이 최솟값이면(3자리에서 소를 멈춘다면) 
		// 4하고 5는 풀을 먹일 수 있으니(+input[i]를 추가 안해도 되니) if문이 발동되는거다
		if (n - k <= i)
		{
			ret = min(dp[i], ret);
		}

		while (!myDeque.empty() && dp[myDeque.back()] >= dp[i])
		{
			myDeque.pop_back();
		}
		myDeque.push_back(i);
	}
	cout << sum - ret << '\n';
}
