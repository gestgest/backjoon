#include <iostream>
#include <vector>
#include <algorithm>


#define DIGIT 31 // 2^30 = 1073741824 => 0 1 2 3
using namespace std;

class Tree {
public:
	Tree * children[2];
	bool isOn[2] = { false, false }; //자식이 들어갔으면 true로 전환

	~Tree() {
		for (int i = 0; i < 2; i++)
		{
			if (isOn[i])
			{
				delete children[i];
			}
		}
	}
};


//direction = 0, 1
Tree* add_tree(Tree * tree, int direction)
{
	//존재하지 않으면 만들어라
	if (!(tree->isOn[direction]))
	{
		Tree* tmp = new Tree();
		tree->isOn[direction] = true;
		tree->children[direction] = tmp;
	}
	
	return tree->children[direction];
}

int search_tree(Tree * tree, int key, int digit)
{
	if (digit < 0) return 0;
	int index = key & 1 << digit;

	if (index != 0) index = 1;
	
	//만약 인덱스가 있다면 반대쪽 애가 있는지
	index = (index + 1) % 2;

	int result = 0;

	if (tree->isOn[index]) result = 1 << digit;
	else { index = (index + 1) % 2; }
	return result + search_tree(tree->children[index], key, digit - 1);
}


//https://www.acmicpc.net/problem/13505
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	int num;

	Tree* root = new Tree;

	cin >> n;
	

	//최대로 큰 값 비교
	int max_value = 0;

	//0과 1의 
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		Tree* tree = root;

		//4byte => digit, 나머지 1bit는 음수라인이라서?
		for (int j = DIGIT - 1; j >= 0; j--)
		{
			//add
			int direction = num & (1 << j);
			if (direction != 0) direction = 1; //여기서 오래걸림
			tree = add_tree(tree, direction);
		}

		tree = root;

		//처음이 아니라면
		if (i != 0)
		{
			int number = search_tree(tree, num, DIGIT - 1);
			if (max_value < number)
			{
				max_value = number;
			}
		}
	}
	delete root;
	cout << max_value << '\n';

}