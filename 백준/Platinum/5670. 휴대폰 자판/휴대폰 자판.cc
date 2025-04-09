#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//class 트리
//만약 p[26] 처럼 고정적으로 하면 무조건 26^80 => 즉 메모리 초과든 시간초과는 생길 거 같다 => vector.
//단 정리를 해야한다
//root 처음은 무조건 비어있다.
class Tree {
public:
	vector<Tree*> pointer; //이거 해시가 될까? => 안될 거 같기도
	char c;

	bool isFin = false;
	//일단 자식 제외 총 합으로 함
	//알아서 자식은 자식 자체의 경우의 수다.
	//이거 왜 하냐면 hel넣고 hell 넣으면 hell만 출력되고 hel은 출력 안되는 오류가 있을 수 있음
	//그거 방지 isFin

	~Tree()
	{
		for (int i = 0; i < pointer.size(); i++)
		{
			delete pointer[i];
		}
	}
};

//
//[ ] 일단 이분탐색 없이 함 => 시간초과 뜨면 정렬, 이분탐색까지 해야함
int search_tree(vector<Tree*> & pointer, char c)
{
	int index = -1;
	//탐색
	for (int i = 0; i < pointer.size(); i++)
	{
		//만약 존재한다면.
		if (c == pointer[i]->c)
		{
			return index = i;
		}
	}
	return index;
}


//트리에 넣는 함수
void add_tree(Tree * root, string s)
{
	Tree* tmp = root;
	//문자열
	for (int i = 0; i < s.size(); i++)
	{
		int index = search_tree(tmp->pointer, s[i]);

		//존재하지 않으면 만들고 tmp에 넣고
		if (index == -1)
		{
			Tree* tree = new Tree; //[ ] 메모리 초기화 어떡하냐
			tmp->pointer.push_back(tree);
			tmp = tree;
			tree->c = s[i];

		}
		//존재하면 tmp에 넣는다
		else
		{
			tmp = tmp->pointer[index];
		}

		if (i == s.size() - 1)
		{
			tmp->isFin = true;
		}

	}
}

//dfs => 값 계산 함수
//그냥 hel처럼 하나만 있으면 count 값 패스
// [ ] 여기서도 메모리 초과나오거나 시간 초과 될 거 같은 느낌이
int dfs(Tree* root, int count, bool isRoot = false)
{
	Tree *tmp = root;
	int sum = 0;

	//먼저 isFin가 있는지 확인
	int plus_value = root->isFin ? 1 : 0;
	if (isRoot) {
		plus_value = 1;
	}

	if (root->isFin) //마지막 값 모든 리턴값
	{
		sum += count;
	}
	// [ ] 만약 초반에 root->pointer.size()가 1이 나온다면?
	if (root->pointer.size() + plus_value > 1)
	{
		count += 1;
	}

	//자식 탐색
	for (int i = 0; i < root->pointer.size(); i++)
	{
		sum += dfs(root->pointer[i], count);
	}

	return sum;
}


//트라이
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cout.setf(ios::fixed); //정수도 소수점 아래 처리
	cout.precision(2); //cout의 소수점 범위를 10자리까지 늘린다. 4은 3.1415

	int n;
	string s;

	//hell 처럼 끝자락이지만 뒤에 아무것도 없어서 2개 적는 경우의 수
	//hello
	//heaven

	//
	while (cin >> n)
	{
		Tree *root = new Tree;
		Tree* tmp = root;
		//트리 다시 만드는 함수

		for (int i = 0; i < n; i++)
		{
			cin >> s; //80글자
			tmp = root;

			add_tree(tmp, s);
		}
		tmp = root;
		
		//계산하는 함수
		cout << (double)dfs(tmp, 0, true) / n<< '\n';

		delete root;
	}
}