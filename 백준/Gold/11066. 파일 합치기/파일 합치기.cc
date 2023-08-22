#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Ans {
public:
	int a = 0;
	int b = 0;
	int c() {
		return a + b;
	}
};
Ans dp[500][500];

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t, n, num;
	cin >> t;

	while (t--)
	{
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			for (int j = i; 0 <= j; j--)
			{
				if (j == i)	{
					cin >> num;
					dp[i][j].b = num;
				}
				else {
					//for
					dp[i][j].b = dp[j][j].b + dp[i][j + 1].b;
					int min;
					
					for (int k = 0; k < i - j; k++) 
					{
						num = dp[k + j][j].c() + dp[i][j + k + 1].c();
						if (k == 0) {
							min = num;
						}
						if (num < min) {
							min = num;
						}
					}
					dp[i][j].a = min;
				}
				
			}
		}
		cout << dp[n - 1][0].a << '\n';
	}
}