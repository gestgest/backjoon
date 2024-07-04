#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Ans {
public:
	int h;
	int score; //1
	Ans(int h, int score) {
		this->h = h;
		this->score = score;
	}
};

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n; //50만
	stack<Ans> my_stack;
	int h;
	long long sum = 0;

	for (int i = 0; i < n; i++)
	{
		cin >> h;

		int cnt = 1;
		while (!(my_stack.empty()))
		{
			if (h < my_stack.top().h)
			{
				break;
			}
			else if(h == my_stack.top().h) {
				cnt += my_stack.top().score;
			}
			sum += my_stack.top().score;
			my_stack.pop();
		}
		if (!my_stack.empty()) sum++; //스택이 있으면 적어도 
		my_stack.push(Ans(h, cnt));
	}
	cout << sum << '\n';

}