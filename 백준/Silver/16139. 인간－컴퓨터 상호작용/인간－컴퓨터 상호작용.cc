#include <iostream>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	char c;
	string s;
	int start, end;
	int i, sum;
	int n;
	cin >> s;

	cin >> n;
	while (n--) {
		sum = 0;
		cin >> c >> start >> end;
		for (i = start; i <= end; i++)
		{
			if (c == s[i]) {
				sum++;
			}
		}

		//답출력
		cout << sum << '\n';
	}
}