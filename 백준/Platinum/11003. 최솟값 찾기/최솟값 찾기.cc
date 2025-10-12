#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define INF 2147483647

class MinValue
{
public:
	int value;
	int index;

	MinValue(int value, int index)
	{
		this->value = value;
		this->index = index;
	}
	bool operator < (const MinValue & mv) const &
	{
		//오름차순
		if (this->value > mv.value)
		{
			return true;
		}
		else if (this->value < mv.value)
		{
			return false;
		}
		if (this->index > mv.index)
		{
			return true;
		}
		return false;
	}

};

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, l, num;

	cin >> n >> l;
	//우선순위 큐?
	priority_queue<MinValue> pq;

	for (int i = 0; i < n; i++)
	{
		cin >> num;

		pq.push(MinValue(num, i));

		while (!pq.empty())
		{
			MinValue mv = pq.top();

			//빼야함
			if (mv.index > i - l)
			{
				cout << mv.value << ' ';
				break;
			}
			pq.pop();
		}
	}

}