#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	int i, j;
	int number;
	int count = 0;
	int dis;

	vector<int> person;
	vector<int> indexList;
	vector<int> trees;

	cin >> n >> m;

	for (i = 0; i < n; i++)
	{
		cin >> number;
		person.push_back(number);
	}
	sort(person.begin(), person.end());

	for (i = 0; i < m; i++)
	{
		cin >> number;
		trees.push_back(number);
	}
	sort(trees.begin(), trees.end());

	for (i = 0; i < n; i++)
	{
		number = person.at(i);

		//이하인 경우
		if (number <= trees.at(0))
		{
			indexList.push_back(0);
			continue;
		}
		for (j = 0; j < m - 1; j++)
		{
			//범주내에 있다면
			if (trees.at(j) <= number && number <= trees.at(j + 1))
			{
				int dis_a = number - trees.at(j);
				int dis_b = trees.at(j + 1) - number;


				//dis_a 당첨
				if (dis_a <= dis_b)
				{
					indexList.push_back(j);
				}
				//dis_b당첨
				else {
					indexList.push_back(j + 1);
				}
				break;
			}
		}
		if (j == m - 1)
		{
			indexList.push_back(j);
		}
	}
	int before_index = indexList.at(0);

	//인덱스 비교
	for (i = 1; i < n; i++)
	{
		if (before_index == indexList.at(i))
		{
			count++;
		}
		else {
			before_index = indexList.at(i);
		}
	}
	cout << count;
}