#include <iostream>
#include <vector>
#include <algorithm>

#define INF 2147483647
#define DIV 10007

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int s[3] = { 0,1,3 };

	int n;
	cin >> n;
	
	for (int i = 3; i <= n; i++)
	{
		s[i % 3] = (s[(i - 2) % 3] * 2 + s[(i - 1) % 3]) % DIV;
	}
	cout << s[n % 3] << '\n';

	
}
