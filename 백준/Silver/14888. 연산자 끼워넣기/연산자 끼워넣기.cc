#include <iostream>
using namespace std;

class Answer {
public:
	int max = -1000000000;
	int min = 1000000000;
};

//개수가 하나라도 남아있다면 if(1 2 3 4)
Answer* cal(int* s, int op[], int* ops, int index, int n)
{
	Answer* answer = new Answer();

	if (n - 1 == index)
	{
		int count = s[0];

		for (int i = 0; i < n - 1; i++)
		{


			switch (ops[i]) {
			case 0:
				count = count + s[i + 1];
				break;
			case 1:
				count = count - s[i + 1];
				break;
			case 2:
				count = count * s[i + 1];
				break;
			case 3:
				count = count / s[i + 1];
				break;
			}

			if (count < -1000000000) {
				count = -1000000000;
			}

			else if (count > 1000000000) {
				count = 1000000000;
			}
		}

		//계산
		answer->max = count;
		answer->min = count;

		return answer;
	}

	for (int i = 0; i < 4; i++)
	{
		if (0 < op[i])
		{
			op[i]--;
			//ops변경
			ops[index] = i;
			Answer* a = cal(s, op, ops, index + 1, n);

			//비교

			if (answer->max < a->max) {
				answer->max = a->max;
			}
			if (a->min < answer->min) {
				answer->min = a->min;
			}

			//변경전으로 되돌림
			op[i]++;
			delete a;
		}
	}

	return answer;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int number;
	int n;
	int max, min;
	cin >> n;

	int* s = new int[n];
	int* ops = new int[n - 1];
	int op[4];

	for (int i = 0; i < n; i++)
	{
		cin >> number;
		s[i] = number;
	}

	for (int i = 0; i < 4; i++)
	{
		cin >> number;
		op[i] = number;
	}

	//
	Answer* answer = cal(s, op, ops, 0, n);

	cout << answer->max << '\n';
	cout << answer->min << '\n';

	delete[] s;
	delete[] ops;
}

//예제 3개는 다 맞음
//