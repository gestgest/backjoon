#include <iostream>
using namespace std;

int insertCow(int* cow, int n, int index) {
	int sum = 0;
	
	for(int i = 0; i < 4; i++)
	{
		int start = (index - 3 + i);

		if (start < 0) {
			start += n;
		}
		start %= n;

		int p = 1;
		for (int j = 0; j < 4; j++)
		{
			p *= cow[(start + j) % n];
		}
		sum += p;
	}
	return sum;
}

int sumCow(int* cow, int n)
{
	int sum = 0;
	
	for (int i = 0; i < n; i++)
	{
		int p = 1;
		for (int j = 0; j < 4; j++)
		{
			p *= cow[(i + j) % n];
		}
		sum += p;
	}
	return sum;
}


int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, q;
	int index;
	int sum;
	cin >> n >> q;
	

	int* cow = new int[n];

	for (int i = 0; i < n; i++)
	{
		cin >> cow[i];
	}

	for (int i = 0; i < q; i++)
	{
		cin >> index;
		cow[index - 1] *= -1;
		if (i == 0) {
			sum = sumCow(cow, n);
			cout << sum << '\n';
		}
		else {
			sum += 2 * insertCow(cow, n, index - 1);
			cout << sum << '\n';

		}
	}
	
	delete[] cow;


}