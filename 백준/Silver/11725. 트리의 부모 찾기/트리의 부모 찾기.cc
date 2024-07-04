#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> v[100000];
int node[100000];

void bfs(int n)
{
	int index, num;
	queue<int> q;
	node[0] = 0;
	q.push(0);

	while (!(q.empty()))
	{
		index = q.front();
		q.pop();

		for (int i = 0; i < v[index].size(); i++)
		{
			num = v[index][i];
			if(node[num] == -1)
				q.push(num);
			//만약 자기 위에 고정된 값이 있다면
			else {
				node[index] = num;
			}
		}
	}

}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, a, b;

	cin >> n;
	
	

	for (int i = 0; i < n - 1; i++)
	{
		node[i] = -1;
		cin >> a >> b;

		v[a - 1].push_back(b - 1);
		v[b - 1].push_back(a - 1);
	}
	node[n - 1] = -1;

	bfs(n);
	for (int i = 1; i < n; i++)
	{
		cout << node[i] + 1 << '\n';
	}
}