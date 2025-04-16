#include <iostream>
#include <vector>
#include <algorithm>

#define INF 2147483647

using namespace std;

class Tree {
public:
	Tree* children[10] = {NULL};
	bool isFin = false;
	~Tree()
	{
		for (int i = 0; i < 10; i++)
		{
			if(children[i] != NULL)
				delete children[i];
		}
	}
};

Tree * add_tree(Tree * tree, int index)
{
	//대충 isFin이 true면  NO
	//비어있다면
	if (tree->children[index] == NULL)
	{
		Tree *tmp = new Tree();
		tree->children[index] = tmp;
	}
	return tree->children[index];
}

bool test_fun()
{
	int n;
	string num;
	bool result = true;

	Tree* root = new Tree();

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		Tree* tree = root;
		cin >> num;

		for (int j = 0; j < num.size(); j++)
		{
			tree = add_tree(tree, num[j] - '0');
			if (tree->isFin)
			{
				//isFin이 true라면 => 911이후 911~
				result = false;
			}
		}
		//끝을 나타내는 isFin
		if (!tree->isFin)
		{
			tree->isFin = true;
			//끝났는데 자식이 있는 경우 => 911~ 이후 911
			for (int i = 0; i < 10; i++)
			{
				if (tree->children[i] != NULL)
				{
					result = false;
				}
			}
		}
	}

	delete root;
	return result;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t;
	cin >> t;


	while (t--)
	{
		//한 마디로 트라이가 isFin가 나올만한 상황이면 No를 외쳐라
		if (test_fun())
		{
			cout << "YES\n";
		}
		else {
			cout << "NO\n";

		}
	}

}
