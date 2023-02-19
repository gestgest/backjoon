#include <iostream>

using namespace std;

class Ans {
public:
	int b = 0; //startB
	int w = 0; //startW
	Ans operator +(Ans ans) {
		Ans result;
		result.b = this->b + ans.b;
		result.w = this->w + ans.w;
		return result;
	}
	Ans operator -(Ans ans) {
		Ans result;
		result.b = this->b - ans.b;
		result.w = this->w - ans.w;
		return result;
	}
	int minAns() {
		if (b < w) {
			return b;
		}
		return w;
	}
};

void debug(int i, int j) {
	if (i == 0 && j == 0) {
		cout << "삐약";
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int col, row, k;
	char c;
	int i, j;
	cin >> col >> row >> k;

	Ans** s = new Ans * [col];
	for (i = 0; i < col; i++)
	{
		s[i] = new Ans[row];
	}

	for (i = 0; i < col; i++) 
	{
		for (j = 0; j < row; j++)
		{
			cin >> c;

			Ans ans;

			//0인데 B다. [w는 틀렸다]
			if ((i + j) % 2 == 0) {
				if (c == 'B') {
					ans.w++;
				}
				else {
					ans.b++;
				}
			}
			else {
				if (c == 'W') {
					ans.w++;
				}
				else {
					ans.b++;
				}
			}

			if (i == 0 && j == 0) {
				s[i][j] = ans;
				continue;
			}
			else if(i == 0) {
				s[i][j] = s[i][j - 1] + ans;
			}
			else if (j == 0) {
				s[i][j] = s[i - 1][j] + ans;
			}
			else {
				s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + ans;
			}
		}
	}


	int min;
	//start = 0 ~ 7 0 ~ 7 k = 8
	for (int i = k - 1; i < col; i++)
	{
		for (int j = k - 1; j < row; j++)
		{
			if (k - 1 == j && k - 1 == i) {
				int num = s[i][j].minAns();
				min = num;
			}
			else if(k - 1 == j) {
				Ans ans = s[i][j] - s[i - k][j];
				int num = ans.minAns();
				if (num < min) {
					min = num;
				}
			}
			else if (k - 1 == i) {
				Ans ans = s[i][j] - s[i][j - k];
				int num = ans.minAns();
				if (num < min) {
					min = num;
				}
			}
			else {
				Ans ans = s[i][j] - s[i][j - k] - s[i - k][j] + s[i - k][j - k];
				int num = ans.minAns();
				if (num < min) {
					min = num;
				}
			}
		}
	}

	cout << min << '\n';

	for (i = 0; i < col; i++)
	{
		delete[] s[i];
	}

	delete[] s;
}

/*
//디버그
for (i = 0; i < col; i++)
{
	for (j = 0; j < row; j++)
	{
		cout << s[i][j].w << ' ';
	}
	cout << '\n';
}

cout << "\n\n\n블랙 스타트 : \n";
for (i = 0; i < col; i++)
{
	for (j = 0; j < row; j++)
	{
		cout << s[i][j].b << ' ';
	}
	cout << '\n';
}
*/