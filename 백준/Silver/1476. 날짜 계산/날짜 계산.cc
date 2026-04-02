#include <iostream>
#include <vector>

using namespace std;

#define INF 2147483647


int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);


	int sum;
	int a, b, c;
	cin >> a >> b >> c;
	
	if (a == 15) a = 0;
	if (b == 28) b = 0;
	if (c == 19) c = 0;

	sum = b;
	//(1 ≤ E ≤ 15, 1 ≤ S ≤ 28, 1 ≤ M ≤ 19)
	//16 29 20 => 33
	//01 04 13


	//2131
	//5266
	//7980

	/*sum = 2131;
	a = sum % 15;
	b = sum % 28;
	c = sum % 19;

	cout << a << " " << b << " " << c << '\n';*/


	if (sum == 0)
	{
		sum += 28;
	}

	while (true)
	{
		if (sum % 15 == a && sum % 19 == c)
		{
			break;
		}
		sum += 28;
	}
	cout << sum << '\n';
}

//33
//