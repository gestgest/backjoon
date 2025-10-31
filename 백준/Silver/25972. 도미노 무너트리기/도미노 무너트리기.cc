#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define INF 2147483647

class Domino {
public:
	int x;
	int l;
	Domino()
	{

	}
	Domino(int x, int l)
	{
		this->x = x;
		this->l = l;
	}
	const bool operator<(Domino & domino) const &
	{
		return this->x < domino.x;
	}
};
vector<Domino> dominos;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	int x, l;
	int count = 0;
	cin >> n;
	dominos = vector<Domino>(n);


	//a가 x좌표, l이 길이
	for (int i = 0; i < n; i++)
	{
		cin >> dominos[i].x >> dominos[i].l;
	}

	//정렬
	sort(dominos.begin(), dominos.end());

	x = -1; //범위
	for (int i = 0; i < n; i++)
	{
		//cout << dominos[i].x << '\n'; // debug
		if (x < dominos[i].x)
		{
			count++;
		}
		x = dominos[i].x + dominos[i].l;

	}
	cout << count << '\n';
}