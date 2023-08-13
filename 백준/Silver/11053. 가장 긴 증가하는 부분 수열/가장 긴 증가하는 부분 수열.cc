#include <iostream>
#include <vector>
using namespace std;

class Seq {
public:
	int dp;
	int count;
	Seq(int dp) {
		this->dp = dp;
		count = 1;
	}
	Seq(int dp, int count) {
		this->dp = dp;
		this->count = count;
	}
};

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	int num;
	int i, j;
	int min = 0;
	vector<Seq> seqV = vector<Seq>();

	cin >> n;

	for (i = 0; i < n; i++)
	{
		cin >> num;
		if (min == 0 || num < min)
		{
			//벡터 생성
			Seq seq(num);
			seqV.push_back(seq);
			min = num;
		}
		else
		{
			//백터들을 순회 [num보다 작은 dp벡터중에서 count값이 가장 큰 놈의 + 1을 백터 생성한다.]
			int max = 0;
			bool isSameDP = false;
			int count = 0;

			for (j = 0; j < seqV.size(); j++)
			{
				if (seqV[j].dp < num)
				{
					if (max < seqV[j].count) {
						max = seqV[j].count;
					}
				}
				else if (seqV[j].dp == num) {
					bool isSameDP = true;
					count = seqV[j].count;
				}
			}
			//근데 만약 그 벡터 dp값이 존재한다면 크기 비교를 한다
			if (!isSameDP || count < max + 1) {
				//백터 생성 [count]
				Seq seq(num, max + 1);
				seqV.push_back(seq);
			}

		}
	}
	int max = 0;

	for (i = 0; i < seqV.size(); i++)
	{
		if (max < seqV[i].count)
		{
			max = seqV[i].count;
		}
	}

	cout << max << '\n';
}