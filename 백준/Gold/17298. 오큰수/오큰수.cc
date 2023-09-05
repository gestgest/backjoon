#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

int s[1000000];
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	stack<int> my_stack;
	int n, num;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> num;
		s[i] = num;

		//스택 탐색
		while (!(my_stack.empty()))
		{
			int index = my_stack.top();
			if (s[index] < num)
			{
				s[index] = num;
				my_stack.pop();
			}
			else {
				break;
			}
		}
		my_stack.push(i);
	}

	//스택 탐색
	while (!(my_stack.empty()))
	{
		int index = my_stack.top();
		s[index] = -1;
		my_stack.pop();
	}
	for (int i = 0; i < n; i++)
	{
		cout << s[i] << ' ';
	}


}