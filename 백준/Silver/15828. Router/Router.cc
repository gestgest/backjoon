#include <iostream>
#include <queue>

#define INF 2147483647

using namespace std;

//queue
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	queue<int> q;
	cin >> n;

	while (true)
	{
		cin >> m;
		if (m == -1)
		{
			break;
		}

		if (m == 0)
		{
			q.pop();
		}
		else if (q.size() < n)
		{
			q.push(m);
		}
	}

	if (q.empty())
	{
		cout << "empty" << '\n';
		return 0;
	}
	while (!(q.empty()))
	{
		cout << q.front() << ' ';
		q.pop();
	}

}