#include <iostream>
#include <stack>
using namespace std;


int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int len;
	int count = 0;
	int count_a = 0;
	int count_b = 0;
	string s;
	cin >> len;
	cin >> s;

	//홀수면 X
	if (len % 2 == 1)
	{
		cout << -1 << endl;
		//또는 ((((
		return 0;
	}

	for(int i = 0; i < len; i++)
	{
		if (s[i] == '(')
		{
			//)가 있는 경우
			if (0 < count_b) {
				//높이 측정
				if (count < count_b) {
					count = count_b;
				}
				count_b--;
			}
			else {
				count_a++;
			}
		}
		else {
			//(가 있는 경우
			if (0 < count_a) {
				if (count < count_a) {
					count = count_a;
				}
				count_a--;
			}
			else {
				count_b++;
			}
		}
	}

	if (0 < count_a || 0 < count_b)
	{
		cout << -1 << endl;
		return 0;
	}
	cout << count << endl;


}

//(()))((())