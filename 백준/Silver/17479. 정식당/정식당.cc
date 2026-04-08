#include <iostream>
#include <map>

using namespace std;

#define INF 2147483647

class Food {
public:
	long long type = 0; //0, 1, 2
	long long cost;
	Food() {}
	Food(long long type, long long cost)
	{
		this->type = type;
		this->cost = cost;
	}
};

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s;
	long long a, b, c, n, money;
	long long sum[2] = { 0,0 };
	map<string, Food> m;

	cin >> a >> b >> c;

	for (int i = 0; i < a; i++)
	{
		cin >> s >> money;
		m.insert(make_pair(s, Food(0, money)));
	}
	for (int i = 0; i < b; i++)
	{
		cin >> s >> money;
		m.insert(make_pair(s, Food(1, money)));
	}
	for (int i = 0; i < c; i++)
	{
		cin >> s;
		m.insert(make_pair(s, Food(2, 0)));
	}

	cin >> n;
	bool isOkay = true;
	bool isTwo = false;

	for (int i = 0; i < n; i++)
	{
		cin >> s;

		if (m.count(s))
		{
			if (m[s].type == 2)
			{
				//스페셜 두 번
				if (isTwo)
				{
					isOkay = false;
				}
				isTwo = true;
				continue;
			}
			sum[m[s].type] += m[s].cost;
		}
	}
	//특별을 샀는데 그냥이 2만원 아래인 경우
	if (sum[1] > 0 && sum[0] < 20000)
	{
		isOkay = false;
	}
	if (isTwo && sum[0] + sum[1] < 50000)
	{
		isOkay = false;
	}

	if (isOkay)
	{
		cout << "Okay" << '\n';
	}
	else {
		cout << "No" << '\n';
	}
}