#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define INF 2147483647

class Stiker
{
public:
	int w[2];
	int operator*(Stiker &stiker)
	{
		return this->w[0] * this->w[1] + stiker.w[0] * stiker.w[1];
	}
};

bool isCheck(Stiker &area, Stiker &a, Stiker&b)
{
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			//area
			for (int k = 0; k < 2; k++)
			{
				//10 1 < 5 1 6 1
				if (area.w[k] < a.w[i] + b.w[j])
				{
					continue;
				}

				if (area.w[(k + 1) % 2] >= a.w[(i + 1) % 2] && area.w[(k + 1) % 2] >= b.w[(j + 1) % 2])
				{
					return true;
				}
			}
		}
	}
	return false;
}


int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);


	Stiker paper;
	int n;
	int a, b;
	int sum_w, sum_h;
	cin >> paper.w[0] >> paper.w[1] >> n;
	int area = 0;

	vector<Stiker> v = vector<Stiker>(n);

	for (int i = 0; i < n; i++)
	{
		cin >> v[i].w[0] >> v[i].w[1];
	}
	//O(n^2)
	for (int i = 0; i < v.size(); i++)
	{
		for (int j = i + 1; j < v.size(); j++)
		{
			if (!isCheck(paper, v[i], v[j]))
			{
				continue;
			}

			int num = v[i] * v[j];
			if (area < num)
			{
				area = num;
			}
		}
	}

	cout << area << '\n';
}