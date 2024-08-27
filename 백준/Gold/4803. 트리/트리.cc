#include <iostream>
#include <vector>
#include <queue>

#define INF 2147483647
#define MAX_SIZE 500

using namespace std;
bool isCheck[MAX_SIZE] = { false };


bool bfs(vector<int> trees[], int start)
{
	int edge_count = 0;
	int node_count = 0;
	queue<int> tree_queue;

	tree_queue.push(start);

	while (!tree_queue.empty())
	{
		int index = tree_queue.front();
		tree_queue.pop();

		if (isCheck[index]) {
			continue;
		}
		node_count++;
		isCheck[index] = true;
		for (int i = 0; i < trees[index].size(); i++)
		{
			edge_count++;
			tree_queue.push(trees[index][i]);
		}
	}
	if (2 * (node_count - 1) == edge_count) {
		return true;
	}
	return false;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	int a, b;
	int index = 0;
	int count;
	while (true)
	{
		count = 0;
		cin >> n >> m;
		if (n == m && n == 0)
			break;

		index++;
		for (int i = 0; i < n; i++)
		{
			isCheck[i] = false;
		}

		//vector 트리 만들기
		vector<int> trees[MAX_SIZE];

		for (int i = 0; i < m; i++)
		{
			cin >> a >> b; a--; b--;
			trees[a].push_back(b);
			trees[b].push_back(a);
		}

		//
		for (int i = 0; i < n; i++)
		{
			if (isCheck[i]) {
				continue;
			}
			if (bfs(trees, i))
			{
				count++;
			}
		}

		cout << "Case " << index << ": ";
		if (count == 0) {
			cout << "No trees.";
		}
		else if (count == 1) {
			cout << "There is one tree.";
		}
		else {
			cout << "A forest of "<< count << " trees.";
		}
		cout << '\n';
	}
}

