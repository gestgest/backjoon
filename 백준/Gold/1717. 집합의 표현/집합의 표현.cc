#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int union_array [1000001];

int find_union(int i)
{
	if (i == union_array[i]) return i;
	return union_array[i] = find_union(union_array[i]);
}

void add_array(int a, int b)
{
	a = find_union(a);
	b = find_union(b);

	if (a < b) {
		union_array[b] = a;
	}
	else {
		union_array[a] = b;
	}
}


int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	//10 6따리, 10 5따리
	int n, m, flag;
	int a, b;
	cin >> n >> m;

	for (int i = 0; i <= n; i++)
	{
		union_array[i] = i;
	}

	//유니온?
	for (int i = 0; i < m; i++)
	{
		cin >> flag;
		cin >> a >> b;

		if (flag == 0) {
			add_array(a, b);
		}
		else {
			if (find_union(a) == find_union(b))
			{
				cout << "YES" << '\n';
			}
			else {
				cout << "NO" << '\n';
			}
		}
	}
	
}