#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int isCheck = 0; //-1은 감소 0은 Xinit 1은 증가
	int n;
	int num;
	int ss[2][8]; //내림차 오름차 


	for (int i = 0; i < 8; i++)
	{
		ss[0][i] = 8 - i;
		ss[1][i] = i + 1;
	}

	for (int i = 0; i < 8; i++)
	{
		cin >> num;

		if (ss[0][i] == num)
		{
			if (isCheck == 1)
			{
				cout << "mixed\n";
				return 0;
			}
			isCheck = -1;
		}
		else if (ss[1][i] == num)
		{
			if (isCheck == -1)
			{
				cout << "mixed\n";
				return 0;
			}
			isCheck = 1;
		}
		else
		{
			cout << "mixed\n";
			return 0;
		}
	}
	if (isCheck == 1) {
		cout << "ascending\n";
	}
	else if (isCheck == -1) {
		cout << "descending\n";
	}
}