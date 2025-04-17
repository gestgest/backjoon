#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define INF 3147483647

//39%
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;

	long long min_value = INF;
	long long result[3];
	long long num; //30억 최대 => int는 21억이 한계

	cin >> n;

	vector<long long> v = vector<long long>(n); //10억 끼리 덧셈 => 오버플로우?


	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	//5000 * 5000 = 2500만
	//맨 처음 인덱스
	for (int i = 0; i < n - 2; i++)
	{
		int start = i + 1;
		int end = n - 1;

		//5000번
		while (start < end)
		{
			num = v[i] + v[start] + v[end];

			if (abs(num) < min_value)
			{
				result[0] = v[i];
				result[1] = v[start];
				result[2] = v[end];
				min_value = abs(num);
			}
			if (num == 0)
			{
				break;
			}
			else if (num < 0)
			{
				start++;
			}
			else {
				end--;
			}

		}
		if (min_value == 0)
		{
			break;
		}
	}

	for (int i = 0; i < 3; i++)
	{
		cout << result[i] << ' ';
	}

}