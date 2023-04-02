#include <iostream>

using namespace std;

//
int binary_search(int *s, int start, int end, int k, int n) 
{
	int div = (start + end) / 2;
	//start - end = 1

	//200 ~ 201
	if (end <= start)
		return div - 1;

	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += s[i] / div;
	}
	if (k <= sum) {
		return binary_search(s, div + 1, end, k, n);
	}
	else {
		return binary_search(s, start, div - 1, k, n);
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, k;
	int num;
	int sum = 0;

	cin >> n >> k;
	int* s = new int[n];

	for (int i = 0; i < n; i++)
	{
		cin >> num;
		s[i] = num;
		sum += num;
	}
	int div = sum / k;
	int result = binary_search(s, 0, div, k, n);

	cout << result << '\n';
	
	delete[] s;
}