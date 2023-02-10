#include <iostream>
using namespace std;

int fib(int n)
{
	if (n == 1 || n == 2)
		return 1;
	else
		return fib(n - 1) + fib(n - 2);
}



int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;

	cin >> n;
	cout << fib(n) << '\n';
	cout << n - 2 << '\n';

	//1 1 2 3 5
}