#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int union_array[1000];


int find_union(int n)
{
	if (n == union_array[n]) return n;
	return union_array[n] = find_union(union_array[n]);
}

void insert_union(int a, int b)
{
	a = find_union(a);
	b = find_union(b);

	if (a > b) {
		union_array[a] = b;
	}
	else {
		union_array[b] = a;
	}
}

//유니온
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int n, m;
	int a, b;
	int count = 0;

	cin >> n >> m;


	//init
	for (int i = 0; i < n; i++)
	{
		union_array[i] = i;
	}

	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		a--; b--;
		insert_union(a, b);
	}


	for (int i = 0; i < n; i++)
	{
		if (find_union(union_array[i]) == i)
		{
			count++;
		}
	}
	cout << count << '\n';

}