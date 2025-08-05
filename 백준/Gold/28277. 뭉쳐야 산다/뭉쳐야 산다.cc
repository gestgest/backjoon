#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <iterator>

using namespace std;
#define INF 2147483647


//1) set <long> 하면 용량이 넘치지 않을까? => 거기 내부 알고리즘으로 용량이 안 넘침, 어차피 원소 갯수는 50만개 아래.
//500,000
set<int> numbers[500001];

void union_add(int a, int b)
{
	//2) 아무리 생각해도 시간초과 될 거 같은데
	//최대 50만 * 25만번 => 12.5 * 10^10 => 1250 0000 0000 => ??? 시간초과 안 나려나?
	if (numbers[a].size() <= numbers[b].size()) swap(numbers[a], numbers[b]);

	for (int num : numbers[b])
		numbers[a].insert(num);


	numbers[b].clear();
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, query;
	int size;
	int a, b, c;
	cin >> n >> query;
	

	for (int i = 0; i < n; i++)
	{
		cin >> size;
		for (int j = 0; j < size; j++) 
		{
			cin >> a;
			numbers[i].insert(a);
		}
	}
	//query =>
	for (int i = 0; i < query; i++)
	{
		cin >> a;

		if (a == 1)
		{
			cin >> b >> c;
			--b; --c;
			union_add(b, c);
		}
		//2
		else {
			cin >> b;
			cout << numbers[--b].size() << '\n';
		}
	}

}