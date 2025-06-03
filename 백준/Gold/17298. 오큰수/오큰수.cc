#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

#define INF 2147483647

using namespace std;

class Ans {
public:
	int index;
	int number;

	Ans(int index, int number)
	{
		this->index = index;
		this->number = number;
	}
};

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	//스택?
	//스택이 쌓인다면 무조건 내림차순으로 떨어진다

	int n, num;
	cin >> n;
	vector<int> v = vector<int>(n, -1);
	stack<Ans> my_stack;


	for (int i = 0; i < n; i++)
	{
		cin >> num;

		//100만
		while (!my_stack.empty())
		{
			Ans ans = my_stack.top();

			if (ans.number < num)
			{
				v[ans.index] = num;
				my_stack.pop();
			}
			else 
			{
				break;
			}
		}

		my_stack.push(Ans(i, num));
	}

	for (int i = 0; i < n; i++)
	{
		cout << v[i] << ' ';
	}
}
