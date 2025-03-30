#include <iostream>
#include <vector>
#include <algorithm>

#define INF 2147483647
#define DIV_NUM  1000000003

using namespace std;

int dp[1001][1001];

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, k;

	//n은 4 ~ 1천까지
	cin >> n >> k;
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= k; j++)
		{
			dp[i][j] = 0;
		}
	}
	
	for (int i = 1; i <= n; i++)
	{
		dp[i][0] = 1; //아예 안 고르는 경우의 수
		dp[i][1] = i; //i칸에서 하나를 고르는 경우의 수
		//■ㅁㅁㅁㅁ => [1][1] => 1개
		//■■ㅁㅁㅁ => [2][1] => ■ㅁㅁㅁㅁ, ㅁ■ㅁㅁㅁ 2개
		//...
	}

	//세로는 그동안 차지한 칸 값
	// 예를 들어 ㅁㅁㅁㅁㅁ에서 n = 2, 2칸을 허용한다고 가정하면 ■ㅁㅁㅁㅁ,ㅁ■ㅁㅁㅁ  이렇게 2칸이 채워진다 => [2][1] 경우의 수는 2개
	
	//가로는 횟수 => j가 k값이 되면 k값까지 했으니 멈추기
	for (int i = 2; i <= n; i++)
	{
		for (int j = 2; j <= k; j++)
		{
			//i값을 넣는 경우의 수 + 안 넣는 경우의 수
			dp[i][j] = (dp[i - 2][j - 1] + dp[i - 1][j]) % DIV_NUM;
		}
	}

	//n = 5, k = 2라고 가정
	//n = 2, k = 1이라고 가정한다면

	//[4][2]

	//	ㅇ■■ㅇㅇ에서 맨 오른쪽 경우의 수[2][1] = > 넣을 예정
	//	■■■■ㅇ에서 맨 오른쪽 안 고름 = > [4][2] => 이미 j는 k갯수가 되었으니 맨 오른쪽은 안 넣어도 됨

	//n번째 수를 고르는 경우의 수 + n번째 수를 안 고르는 경우의 수
	cout << (dp[n - 3][k - 1] + dp[n - 1][k]) % DIV_NUM << '\n';
}