#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define INF 2147483647

vector<int> v;

int find_union(int a)
{
	if (v[a] == a) return a;
	return v[a] = find_union(v[a]);
}
int add_union(int a)
{
	a = find_union(a);

	if (a == 0)
	{
		return a;
	}
	int b = a-1;

	b = find_union(b);
	v[a] = v[b];
	return a; //v[b]가 적은 값
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int g, p, a;
	int sum = 0;
	bool isEnd = false;
	cin >> g >> p;
	v = vector<int>(g + 1); //graph 자신의 값을 담겨있다가 자신이 맡을 수 있는 가장 밑 값 출력
	//0이면 끝난거

	//union
	for (int i = 0; i <= g; i++)
	{
		v[i] = i;
	}

	for (int i = 0; i < p; i++)
	{
		cin >> a;

		if (add_union(a) != 0 && !isEnd)
		{
			sum++;
		}
		else {
			isEnd = true;
		}
	}
	cout << sum << '\n';
}