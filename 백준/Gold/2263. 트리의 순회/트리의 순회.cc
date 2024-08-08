#include <iostream>
#include <vector>

#define INF 2147483647

using namespace std;

int n;
vector<int> preorder;
vector<int> inorder;
vector<int> postorder;
vector<int> inorder_map; //인덱스는 inorder값, 값에는 주소

/*
class Edge {
public:
	int left = -1;
	int right = -1;
};
*/

void pre_div(int istart, int iend, int pstart, int pend)
{
	if (istart > iend || pstart > pend) {
		return;
	}
	int root = postorder[pend];
	cout << root + 1 << ' ';

	int index = inorder_map[root]; //중위 인덱스

	int right_size = iend - index;
	//두개로 나눠야함
	pre_div(istart, index - 1, pstart, pend - right_size - 1);
	pre_div(index + 1, iend, pend - right_size, pend - 1); //매개변수 pstart가 잘못됨
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int before, num;
	
	cin >> n;
	inorder = vector<int>(n);
	postorder = vector<int>(n);
	inorder_map = vector<int>(n + 1); //인덱스는 inorder값, 값에는 주소

	//중위
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		num--;
		inorder[i] = num;
		inorder_map[num] = i;
	}

	//후위[]
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		num--;
		postorder[i] = num;
	}

	pre_div(0, n - 1, 0, n - 1);

	//전위 (값에다가 +1을 해야한다)
}
