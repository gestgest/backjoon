#include <iostream>
#include <vector>
#include <algorithm>

#define INF 2147483647

using namespace std;

class Tree {
public:
	int left = -1;
	int right = -1;

	Tree(){}
};

void printFront(vector<Tree> & trees, int index, int type)
{
	if (index == -1)
	{
		return;
	}
	if(type == 0)
		cout << char(index + 'A');
	printFront(trees, trees[index].left, type);

	if (type == 1)
		cout << char(index + 'A');

	printFront(trees, trees[index].right, type);

	if (type == 2)
		cout << char(index + 'A');
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int n;
	char a, b, c;

	cin >> n;
	vector<Tree> trees = vector<Tree>(n);


	for (int i = 0; i < n; i++)
	{
		cin >> a >> b >> c;

		if (b != '.') //자식이 없다.
		{
			trees[a - 'A'].left = b - 'A';
		}
		if (c != '.')
		{
			trees[a - 'A'].right = c - 'A';
		}
	}

	for (int i = 0; i < 3; i++)
	{
		printFront(trees, 0, i);
		cout << '\n';
	}

}

