#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cout.setf(ios::fixed);
	cout.precision(3);

	int n, t, num;
	int count;
	int* s;
	double sum = 0;
	cin >> t;


	while (t--)
	{
		cin >> n;

		vector<int> scoreVector = vector<int>(1000);

		sum = 0;
		count = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> num;
			scoreVector.push_back(num);
			sum += num;
		}
		sort(scoreVector.begin(), scoreVector.end());

		sum /= n;

		for (int i = scoreVector.size() - 1; 0 < i; i--)
		{
			if (scoreVector[i] <= sum)
			{
				break;
			}
			count++;
		}

		float percent = (float)count * 100 / n;
		cout << percent << '%' << '\n';
	}
	
}