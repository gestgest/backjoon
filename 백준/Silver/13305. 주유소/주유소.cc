#include <iostream>
#include <algorithm>

using namespace std;

class Gas {
public:
	int value;
	int pos;
};

bool isMax(Gas a, Gas b) {
	if (a.value < b.value)
		return true;
	return false;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	int p;
	int sum = 0;
	int dis;
	cin >> n;
	int* road = new int[n - 1]; //누적합
	Gas* s = new Gas[n - 1];
	dis = n - 2;

	cin >> p;
	road[0] = p;
	for (int i = 1; i < n - 1; i++)
	{
		cin >> p;
		road[i] = p + road[i - 1];
	}

	for (int i = 0; i < n - 1; i++)
	{
		cin >> s[i].value;
		s[i].pos = i;
	}

	//그냥 버리기
	cin >> p;

	//s 짧은 거 정렬
	sort(s, s + n - 1,isMax);
	
	//n - 1개. 4개면 3개 탐색 [0 1 2]
	for (int i = 0; i < n - 1; i++)
	{
		p = s[i].pos;
		if (p == 0) {
			sum += road[dis] * s[i].value;
			break;
		}
		else if (p < dis)
		{
			sum += (road[dis] - road[p - 1]) * s[i].value;
			dis = p - 1;
		}
		
	}
	//새로운 pos가 누적 pos보다 작다면 그냥 무시
	cout << sum << '\n';
}