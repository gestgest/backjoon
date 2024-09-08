#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int find_union(vector<int> & union_s, int n)
{
	if (union_s[n] == n) return n;
	return union_s[n] = find_union(union_s, union_s[n]);
}


bool insert_union(vector<int>& union_s, int a, int b)
{
	a = find_union(union_s, a);
	b = find_union(union_s, b);

	//같은 계열
	if (a == b)
	{
		return true;
	}
	if (a < b) {
		union_s[b] = a;
	}
	else {
		union_s[a] = b;
	}
	return false;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int n, e;
	int a, b;
	int case_number = 0;
	cin >> n >> e;

	vector<int> union_s = vector<int>(n);

	for (int i = 0; i < n; i++)
	{
		union_s[i] = i;
	}

	for (int i = 0; i < e; i++)
	{
		cin >> a >> b;

		if (insert_union(union_s, a, b) && case_number == 0)
		{
			case_number = i + 1;
		}
	}
	cout << case_number;
}