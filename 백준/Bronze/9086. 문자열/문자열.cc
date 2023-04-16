#include <iostream>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t;
	string s;

	cin >> t;

	for (int i = 0; i < t; i++)
	{
		cin >> s;

		cout << s[0] << s[s.size()-1] << '\n';
	}
	

}