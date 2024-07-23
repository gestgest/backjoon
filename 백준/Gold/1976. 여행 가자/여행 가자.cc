#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int union_node[200];


//유니온 결합
void union_combine(int a, int b)
{
	int min;
	while (union_node[a] != a)
	{
		a = union_node[a];
	}
	while (union_node[b] != b)
	{
		b = union_node[b];
	}
	if (a < b) {
		min = a;
	}
	else {
		min = b;
	}

	union_node[a] = min;
	union_node[b] = min;
}

bool isUnion(int a, int b) 
{
	while (union_node[a] != a)
	{
		a = union_node[a];
	}
	while (union_node[b] != b)
	{
		b = union_node[b];
	}
	if (a == b)
		return true;
	return false;
}

void print_union(const int m, int standard_num)
{
	int num;

	//m번
	for (int i = 1; i < m; i++)
	{
		cin >> num;
		//유니온 배열 출력후 비교
		if (!isUnion(standard_num, num - 1)) {
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int num, standard_num;
	int node, m;
	cin >> node >> m;

	for (int i = 0; i < node; i++)
	{
		union_node[i] = i;
	}

	//
	for (int i = 0; i < node; i++)
	{
		for (int j = 0; j < node; j++)
		{
			cin >> num;
			if (num == 0)
				continue;

			union_combine(i, j);
		}
	}

	cin >> standard_num;
	standard_num--;

	print_union(m, standard_num);
}

/*
0 1 2 3 4 5
2 <- 0

0 1 0 3 4 5
두개를 비교할때 배열 값이 적은거 위주

1 <- 2

0 0 0 3 4 5

---
0 1 2 3 4 5
2 <- 3

0 1 2 2 4 5

0 <- 3
0 1 2 0 4 5
배열에 있는 값도 비교
while문
0 1 2


0 0 2 2 2 2 2 7
7은 0

0 0 2 2 2 2 2 0
7과 3
=> 0

0 2비교
=> 0
0 0 0 2 2 2 2 0

---
0 <-> 2
1 <-> 3
결과적으로 2 와 3이 결합하면



*/