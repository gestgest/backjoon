#include <iostream>
#include <vector>


#define INF 2147483647

using namespace std;

class Tree {
public:
	int parent;
	vector<int> children;
	int value = 1;
};

vector<vector<int>> edges;
vector<Tree> trees;


void makeTree(int current, int parent)
{
	for (int i = 0; i < edges[current].size(); i++)
	{
		if (edges[current][i] != parent)
		{
			trees[current].children.push_back(edges[current][i]);
			trees[edges[current][i]].parent = current;
			makeTree(edges[current][i], current);
		}
	}
}

void set_tree(int n)
{
	int u, v;
	edges = vector<vector<int>>(n); //메모리 초과 각인데
	trees = vector<Tree>(n);

	//edge 설정
	for (int i = 0; i < n - 1; i++)
	{
		cin >> u >> v;
		u--; v--;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}

}

void countNode(int current)
{
	for (int i = 0; i < trees[current].children.size(); i++)
	{
		countNode(trees[current].children[i]);
		trees[current].value += trees[trees[current].children[i]].value;
	}
}


int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);


	int n, root, query_n, query;
	cin >> n >> root >> query_n;

	root--;
	set_tree(n);
	makeTree(root, -1);
	countNode(root);

	for (int i = 0; i < query_n; i++)
	{
		cin >> query;

		cout << trees[query - 1].value << '\n';
	}
}