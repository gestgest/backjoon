#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define INF 2147483647

int s[100][100];

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	//for문 i j k=> n^3

	int n, m;
	int start, end, value;

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			s[i][j] = INF;
		}
	}

	for (int i = 0; i < m; i++)
	{
		cin >> start >> end >> value;
		start--; end--;

		if(s[start][end] > value)
			s[start][end] = value;

	}

	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i < n; i++) 
		{
			for (int j = 0; j < n; j++)
			{
				if (i == j || k == j || k == i)
				{
					continue;
				}

				if (s[i][k] == INF || s[k][j] == INF)
				{
					continue;
				}
				int num = s[i][k] + s[k][j];
				if (s[i][j] > num) 
				{
					s[i][j] = num;
				}
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (s[i][j] == INF) 
			{
				s[i][j] = 0;
			}
			cout << s[i][j] << ' ';
		}
		cout << '\n';
	}
}