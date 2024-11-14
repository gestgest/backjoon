#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string text, pattern;
	int count = 0;
	int i = 0, j = 0;
	vector<int> result = vector<int>();

	getline(cin, text);
	getline(cin, pattern);

	int m = pattern.size();
	vector<int> pattern_pi(m, 0);

	//패턴 정상화
	for (j = 1; j < m; j++)
	{
		//일단 앞자리가 같을때까지 i로 탐색
		while (i > 0 && pattern[j] != pattern[i]) 
		{
			i = pattern_pi[i - 1]; //0으로 초기화 
		}
		if (pattern[j] == pattern[i]) {
			pattern_pi[j] = ++i; //연속값을 넣기
		}
	}

	i = 0; j = 0;
	//백만
	for (i = 0; i < text.size(); i++)
	{
		//만약 틀린다면
		//일단 앞자리가 같을때까지 i로 탐색
		while (j > 0 && pattern[j] != text[i])
		{
			j = pattern_pi[j - 1]; //0으로 초기화 
		}
		if(pattern[j] == text[i]) {
			j++;
			//같은 값일 경우, 여담) 만약 AAAA...면? 계속 j값은 3이 나올거다
			if (j == m) {
				result.push_back(i - m + 2);
				j = pattern_pi[j - 1];
			}
		}
		
	}

	cout << result.size() << '\n';
	for (i = 0; i < result.size(); i++)
	{
		cout << result[i] << ' ';
	}

}	