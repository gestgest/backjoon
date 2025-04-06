#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int* pi;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);


	//kmp
	// 먼저 복귀 값 배열을 정리하자 => 문자열이 틀리면 다시 돌아올 수 있는 발판

	int n, j = 0;
	string s;

	cin >> n;
	pi = new int[n];

	
	//ababa => ab => 2개, aaaaa => a => 1개 최대 n개
	cin >> s;

	pi[0] = 0;
	//KMP의 핵심
	//처음은 제외해야함 => 안 그러면 ABCDE가 0 1 2 3 4로 됨
	for (int i = 1; i < n; i++)
	{
		pi[i] = 0;
		//j > 0인 경우 배열 범주에 벗어남 + 어차피 0임
		//틀리면 0 AAABAAAA => 이때 8번째 A가 탈락하면 0이 아닌 j는 3부터 시작이니까
		while (j > 0 && s[i] != s[j])
		{
			j = pi[j - 1]; //대체적으로는 0. 하지만 위의 경우처럼 AAAA인 경우 j = 3에서 멈춤
		}
		if (s[i] == s[j]) {
			pi[i] = ++j;
		}
	}
	cout << n - pi[n - 1] << '\n';

	delete [] pi;
}