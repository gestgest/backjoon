#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define INF 2147483647


int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;

	int first[3];
	int input[3];
	int s[2][3][3] = { 0 }; //맨 처음은 index, 두번째는 처음 스타팅
	//가운데를 무시
	cin >> n;

	//초기 세팅
	cin >> first[0] >> first[1] >> first[2];
	cin >> input[0] >> input[1] >> input[2];

	
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if(i == j)
				s[1][i][j] = INF;
			else
				s[1][i][j] = first[i] + input[j];
		}
	}
	
	// [n - 2]
	for (int i = 2; i < n - 1 ; i++)
	{
		cin >> input[0] >> input[1] >> input[2];

		//s[0]의 인덱스
		for (int j = 0; j < 3; j++)
		{
			//실제 마지막 노드
			for (int k = 0; k < 3; k++)
			{
				//여기서 j는 참조만 해야한다
				s[i % 2][j][k] = min(s[(i + 1) % 2][j][(k + 1) % 3], s[(i + 1) % 2][j][(k + 2) % 3]) + input[k];
			}
		}
	}
	cin >> input[0] >> input[1] >> input[2];

	int min_value = INF;
	//s[n - 1] = 뭐시기 뭐시기
	int index = (n + 1) % 2;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{	
			if (i == j)
			{
				s[index][i][j] = INF; //s[0]의 시작점과 같음
			}
			else
			{
				s[index][i][j] = min(s[(index + 1) % 2][i][(j + 1) % 3], s[(index + 1) % 2][i][(j + 2) % 3]) + input[j];
				if (s[index][i][j] < min_value)
				{
					min_value = s[index][i][j];
				}
			}
		}
	}
	cout << min_value;

	//근데 이러면 
}