#include <iostream>
#include <set>
#include <vector>
#include <iterator>
using namespace std;

int case_count(int n)
{
	int num;
	int count = 0;
	int size;

	vector<int> tju_v;
	set<int> tju_set;
	set<int> tju_set2;

	for (int i = 0; i < n; i++)
	{
		cin >> num;
		tju_v.push_back(num);
		tju_set.insert(num);
	}

	size = tju_set.size();

	for (int i = 0; i < tju_v.size(); i++)
	{
		num = tju_v[i];
		count++;
		if (tju_set2.count(num) == 0)
		{
			tju_set2.insert(num);
			size--;
			if (size == 0)
			{
				return count;
			}
		}
		
	}
	//
	return count;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);


	int T;
	int N;

	cin >> T;
	for (int i = 1; i <= T; i++)
	{
		cin >> N;
		cout << "Case " << i << ": " << case_count(N) << '\n';
	}
	
}