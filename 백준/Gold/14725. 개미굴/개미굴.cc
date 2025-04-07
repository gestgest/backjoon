#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <iterator>

#define INF 2147483647

using namespace std;

class Node {
public:
	map<string, Node*> children;
	string s;
	int height = -1;
};

void height_print(int height)
{
	for (int i = 0; i < height; i++)
	{
		cout << "--";
	}
}
void node_search(Node *node)
{
	if (node->height != -1)
	{
		height_print(node->height);
		cout << node->s << '\n';
	}
	//자식 탐색
	for (map<string,Node*>::iterator it = node->children.begin(); it != node->children.end(); it++)
	{
		node_search(it->second);
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, k;
	string s;
	cin >> n;

	Node *root = new Node();
	Node* node;

	//1000 * 15
	for (int i = 0; i < n; i++)
	{
		cin >> k;

		node = root;
		for (int j = 0; j < k; j++)
		{
			cin >> s;
			//존재하지 않는다면
			if (node->children.count(s) == 0)
			{
				//생성
				Node *tmp = new Node();
				tmp->s = s;
				tmp->height = node->height + 1;

				node->children[s] = tmp;
			}
			node = node->children[s]; //이동
		}
	}

	//노드 탐색
	node_search(root);
}
