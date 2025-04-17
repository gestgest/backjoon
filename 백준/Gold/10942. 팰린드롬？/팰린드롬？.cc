#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define INF 2147483647

bool isPen[2000][2000] = { 0 };

void setPen(int index_a, int index_b, int a, int b)
{
	//값이 다른지
	if (a != b) 
	{
		//isPen[index_a][index_b] = 0;
		return;
	}
	index_a++; index_b--;

	//기존 배열이 같은지
	if (index_a <= index_b)
	{
		if (isPen[index_a][index_b] == 0)
		{
			//isPen[index_a][index_b] = 0;
			return;
		}
	}
	index_a--; index_b++;

	isPen[index_a][index_b] = 1;
}


//팰린드롬 = 거꾸로 해도 같은 거
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	int start, end;

	cin >> n;
	vector<int> v = vector<int>(n);

	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	//차이
	for (int i = 0; i < n; i++)
	{
		//시작 점
		for (int j = 0; i + j < n; j++)
		{
			setPen(j, j + i, v[j], v[j + i]);
		}
	}

	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> start >> end;
		start--; end--;
		cout << isPen[start][end] << '\n';
	}

}