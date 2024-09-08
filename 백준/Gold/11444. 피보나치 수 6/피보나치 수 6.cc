#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_DIV 1000000007

class Matrix {
	int row, col;
public:

	vector<vector<long long>> matrix;
	Matrix(int row, int col)
	{
		this->row = row;
		this->col = col;

		matrix = vector<vector<long long>>(row);

		for (int i = 0; i < row; i++)
		{
			matrix[i] = vector<long long>(col, 0);
		}
	}

	void setValue(int y, int x, long long value)
	{
		this->matrix[y][x] = value;
	}

	Matrix operator *(Matrix m)
	{
		//this->col == matrix->row
		Matrix tmp(this->row, m.col);

		for (int i = 0; i < m.col; i++)
		{
			for (int j = 0; j < this->col; j++)
			{
				for (int k = 0; k < this->row; k++)
				{
					tmp.matrix[k][i] += this->matrix[j][k] * m.matrix[j][i];
				}
			}
		}
		tmp % MAX_DIV;
		return tmp;
	}

	Matrix operator %(int div)
	{
		for (int i = 0; i < this->row; i++)
		{
			for (int j = 0; j < this->col; j++)
			{
				this->matrix[i][j] %= div;
			}
		}

		return *this;
	}

	void print()
	{
		cout << row << " " << col << '\n';
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				cout << matrix[i][j] << ' ';
			}
			cout << '\n';
		}
	}
};

//분할 계산
Matrix div_cal(Matrix m, long long n)
{
	if (n <= 1) return m % MAX_DIV;

	Matrix mat = div_cal(m, n / 2);
	mat = (mat * mat) % MAX_DIV;
	if (n % 2 == 1) return mat * m % MAX_DIV;
	return mat;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	long long n;
	cin >> n;

	//피보나치로 행렬
	Matrix m(2, 1);
	m.setValue(0, 0, 0); //p0
	m.setValue(1, 0, 1); //p1
	
	Matrix a(2, 2);
	a.setValue(0, 0, 0); 
	a.setValue(1, 0, 1); 
	a.setValue(0, 1, 1); 
	a.setValue(1, 1, 1); 

	Matrix mm = div_cal(a, n - 1); //n - 1, n
	
	Matrix mmm = mm * m;
	cout << mmm.matrix[1][0] << '\n';

}