#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define INF 2147483647

int n;
int max_weight;

int binary_search_weight(vector<int> & tmp, int start, int end, int value)
{
	//값이 같으면 end가 내려가야함
	if (start > end)
	{
		return start;
	}

	int mid = (start + end) / 2;

	if (value >= tmp[mid])
	{
		return binary_search_weight(tmp, mid + 1, end, value);
	}
	else {
		return binary_search_weight(tmp, start, mid -1, value);
	}
}

void myBruthforce(vector<int> & input, vector<int>& output, int sum, int index, int max_index)
{
	if (sum > max_weight)
	{
		return;
	}
	if (index == max_index)
	{
		output.push_back(sum);
		return;
	}

	myBruthforce(input, output, sum + input[index], index + 1, max_index);
	myBruthforce(input, output, sum, index + 1, max_index);
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int sum = 0;

	cin >> n >>  max_weight;
	vector<int> input = vector<int>(n);
	vector<int> output[2];
	for (int i = 0; i < n; i++)
	{
		cin >> input[i];
	}

	myBruthforce(input, output[0], sum, 0, n / 2);
	myBruthforce(input, output[1], sum, n / 2, n);

	sort(output[0].begin(), output[0].end());

	for (int i = 0; i < output[1].size(); i++)
	{
		int value = max_weight - output[1][i];
		int count = binary_search_weight(output[0], 0, output[0].size() - 1, value);
		sum += count;
	}

	cout << sum << '\n';

	//절반은 정렬, 절반은 bf 2^15
	//
}