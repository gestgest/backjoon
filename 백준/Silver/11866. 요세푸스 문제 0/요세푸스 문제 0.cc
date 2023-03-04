#include <iostream>
#include <queue>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;
	int sum = 1;
	queue<int> ans_queue;

	for (int i = 1; i <= n; i++)
	{
		ans_queue.push(i);
	}

	cout << "<";
	while (true)
	{
		if (ans_queue.size() == 1) {
			cout << ans_queue.front();
			break;
		}
		//'숫자, '
		int num = ans_queue.front();
		ans_queue.pop();
		if (sum % k == 0) {
			cout << num << ", ";
		}
		else {
			ans_queue.push(num);
		}

		sum++;
	}
	cout << ">";

}