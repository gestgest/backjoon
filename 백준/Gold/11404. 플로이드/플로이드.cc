#include <iostream>
#include <vector>
#include <algorithm>

#define INF 2147483647
using namespace std;

int n, m;

int s[100][100];

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> m;
	int start, end, value;

	//초기화
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			s[i][j] = INF;
		}
	}

	//입력
	for (int i = 0; i < m; i++)
	{
		cin >> start >> end >> value;
		start--; end--;

		if (s[start][end] > value) {
			s[start][end] = value;
		}
	}

	//Floyd
	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (i == j || j == k || k == i) {
					continue;
				}
				if (s[i][k] == INF || s[k][j] == INF) {
					continue;
				}

				if (s[i][j] > s[i][k] + s[k][j])
					s[i][j] = s[i][k] + s[k][j];
			}
		}
	}


	//출력
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (INF != s[i][j])
				cout << s[i][j] << ' ';
			else
				cout << 0 << ' ';
		}
		cout << '\n';
	}
}