#include <iostream>
using namespace std;


int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	bool isTurn = false;
	int aj, bj, ap, bp, dis;


	cin >> aj >> bj >> ap >> bp;

	dis = ap - bp;

	while (true)
	{
		if (ap == bp)
		{
			cout << bp << endl;
			return 0;
		}
		if (dis == ap - bp && isTurn)
		{
			cout << -1 << endl;
			return 0;

		}
		if (ap < bp)
		{
			ap += aj;
		}
		else {
			bp += bj;
		}
		isTurn = true;
	}
}

//1 1 12 7
//7 7 1 2
//3 3 3 6
//9 18 3 2
//9 40
//aj bj가 최소
// 계산하기전 dis[ap와 bp차이]를 구하고 bool로 ap가 큰지 bp가 큰지 비교하고
//그 dis와 bool값이 같다면