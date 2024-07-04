#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int node[1000001];

int min_value(int a, int b)
{
	return a < b ? a : b;
}

int union_search(int num)
{
	if (num == node[num]) return num;
	return node[num] = union_search(node[num]);
}

void add_union(int a, int b)
{
	a = union_search(a);
	b = union_search(b);

	int num = min_value(a, b);
	node[a] = num;
	node[b] = num;

}

bool isUnion(int a, int b) 
{
	a = union_search(a);
	b = union_search(b);
	if (a == b)
		return true;
	else
		return false;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	//백만개
	int n, t;
	int a, b, c;

	cin >> n >> t;

	//배열 초기화
	for (int i = 0; i <= n; i++)
	{
		node[i] = i;
	}

	for (int i = 0; i < t; i++)
	{
		cin >> a >> b >> c; //b-1 c-1
		switch (a) {
		case 0:
			add_union(b, c);
			break;
		case 1:
			if (isUnion(b, c)){
				cout << "YES\n";
			}
			else {
				cout << "NO\n";
			}
			break;
		}
	}

	/* 디버깅
	for (int i = 0; i < n; i++)
	{
		cout << node[i] << ' ';
	}
	cout << '\n';
	*/
}