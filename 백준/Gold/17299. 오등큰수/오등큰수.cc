#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <algorithm>

using namespace std;

int m[1000000] = {0,};
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, num;
	cin >> n;

	vector<int> v = vector<int>(n);
	stack<int> my_stack;
	
	//n
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		v[i] = num;
		m[num]++;
	}

	//n
	for (int i = 0; i < n; i++)
	{
		num = m[v[i]];
		//스택 탐색
		while (!(my_stack.empty()))
		{
			if (m[v[my_stack.top()]] < num)
			{
				v[my_stack.top()] = v[i];
				my_stack.pop();
			}
			else {
				break;
			}
		}
		my_stack.push(i);
	}
	// 나머지 스택은 -1

	//n
	while (!(my_stack.empty()))
	{
		v[my_stack.top()] = -1;
		my_stack.pop();
	}

	//n
	for (int i = 0; i < n; i++)
	{
		cout << v[i] << ' ';
	}
}