#include <iostream>

using namespace std;

int binary_search(int* s, long start, long end, int k, int n)
{
	long div = (start + end) / 2;
	long sum = 0;
	//cout << "디버그 : " << start << ", " << div << ", " << end << '\n';
	if (end < start) {
		return end;
	}
	for (int i = 0; i < k; i++)
	{
		sum += s[i] / div;
	}

	if (n <= sum) {
		
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

	int k, n;
	int num;
	int max = 0;

	cin >> k >> n;
	int* s = new int[k];

	// k * log2(k)
	for (int i = 0; i < k; i++)
	{
		cin >> num;
		s[i] = num;
		if (max < num) max = num;
	}


	//cout << max << '\n';
	cout << binary_search(s, 1,max , k, n) << '\n';
	

	delete[]s;

}