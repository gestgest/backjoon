#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	long long r,c;
	long long result;

	cin >> r >> c;
	
	if (r % 2 == 1 && c % 2 == 1)
	{
		if (r > c)
			result = c;
		else
			result = r;
	}
	else {
		result = 0;
	}

	cout << result << '\n';

	/*
	//작은 값
	int num1 = cal(r, c);
	int num2 = cal(c, r);
	if (num1 > num2) {
		num1 = cal(r + 1, c) - num1;

		cout << num1;
	}
	else {
		num2 = cal(c + 1, r) - num2;

		cout << num2;
	}
	*/
}