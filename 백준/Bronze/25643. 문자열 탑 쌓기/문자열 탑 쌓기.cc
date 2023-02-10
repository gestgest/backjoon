#include <iostream>
#include <string>
using namespace std;

bool isCheck(string s1, string s2, int m) {
	int i, j;
	if (s1==s2)
	{
		return true;
	}

	for (i = 1; i < m; i++)
	{
		//9와 0, 8 9와 0 1
		for (j = 0; j < i; j++)
		{
			//s1[9] == s2[0]
			if (s1[m - i + j] != s2[j])
			{
				break;
			}
			
		}
		if (j == i) {
			return true;
		}


		for (j = 0; j < i; j++)
		{
			//s1[0] == s2[9]
			if (s1[j] != s2[m - i + j])	{
				break;
			}

		}
		if (j == i) {
			return true;
		}
	}
	
	return false;
}


int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int m, n;

	cin >> n >> m;

	string *s = new string[n];
	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
	}
	for (int i = 0; i < n - 1; i++)
	{
		if (!isCheck(s[i], s[i + 1], m))
		{
			cout << 0 << '\n';
			return 0;
		}
	}

	cout << 1 << '\n';
	return 0;

}

//sup
//upv