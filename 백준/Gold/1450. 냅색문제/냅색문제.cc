#include <iostream>
#include <algorithm>
#include <vector>

#define INF 2147483647

using namespace std;

void bf(int weight[], vector<int>& sum, int start, const int end, int value, const int max_weight)
{
	if (value > max_weight || start > end) {
		return;
	}
	if (start == end) {
		sum.push_back(value);
		return;
	}

	bf(weight, sum, start + 1, end, value + weight[start], max_weight); //O
	bf(weight, sum, start + 1, end, value, max_weight); //X
}

int binary_search_weight(vector<int>& sum, int start, int end, int value)
{
	if (start > end) 
	{
		return start;
		// 1 2 3 4 (10) 15 => 여기서 4의 index 3을 원하면 return end;
		// ㄴ 15의 index 4를 원하면 return start;
		// 0 1 1 1 1 4 => 
	}
	int mid = (start + end) / 2;

	//<-
	if (value < sum[mid]) {
		return binary_search_weight(sum, start, mid - 1, value);
	}
	//같아도 ->,  start 
	else { 
		return binary_search_weight(sum, mid + 1, end, value);
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, max_weight;
	int weight[30];
	int count = 0;

	vector<int> sum[2];

	//n은 30까지
	cin >> n >> max_weight;

	for (int i = 0; i < n; i++)
	{
		cin >> weight[i];
	}
	
	bf(weight, sum[0], 0, n / 2, 0, max_weight);
	bf(weight, sum[1], n / 2, n, 0, max_weight);

	sort(sum[1].begin(), sum[1].end()); //이분탐색을 위한 정렬

	for (int i = 0; i < sum[0].size(); i++)
	{
		int a = sum[0][i];
		int b = binary_search_weight(sum[1], 0, sum[1].size() - 1, max_weight - a);
		count += b;
	}

	cout << count << '\n';
}