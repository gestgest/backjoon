#include <iostream>
using namespace std;

int isCheck(int before, int after)
{
	//+
	if (before < after)
		return 1;
	else
		return -1;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n, num;
	int min = 0, before = 0;
	int isPlus;
	int beforePlus = 0;
	int count = 0;
	int secondPlus = 0;

	while (true)
	{
		count = 0;
		cin >> n;
		if (n == 0)
			break;
		for (int i = 0; i < n; i++)
		{
			cin >> num;
			if (i == 0)
			{
				min = num;
				beforePlus = 0;
			}
			else
			{
				isPlus = isCheck(before, num);
				if (beforePlus != isPlus && beforePlus != 0)
					count++;
				if (i == 1)
					secondPlus = isPlus;
				
				beforePlus = isPlus;
				
			}
			before = num;
		}
		isPlus = isCheck(before, min);
		if (beforePlus != isPlus)
			count++;

		// index 1번에 해당하는 before isPlus
		if (secondPlus != isPlus)
			count++;
		// 0 5 3 + - - + - +
		cout << count << '\n';

	}
}