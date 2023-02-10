#include <iostream>
#include <cmath>
using namespace std;

//int ppap = 0;

//1 2, 1 3, 1 4
//4명 => 3개 [(n - 1)! / 2]
//6명 => 1 2 3/ 1 2 4 / 1 2 5 [5!(5 x 4) / 2] = 5 4 = 10
//1 2 6 / 1 3 4 / 1 3 5 / 1 3 6 / 1 4 5 / 1 4 6 / 1 5 6

void debugCheck(int checkA[], int checkB[], int n)
{

	cout << "A : ";
	for (int i = 0; i < n / 2; i++)
	{
		cout << checkA[i] << " ";
	}
	cout << "B : ";
	for (int i = 0; i < n / 2; i++)
	{
		cout << checkB[i] << " ";
	}
	cout << "\n";
}




// 주어진 인덱스를 주고 특정 인덱스 더하는 함수A
int sumStat(int** s, int n, int check[], int index)
{
	int sum = 0;
	for (int i = 0; i < n / 2; i++)
	{
		int j = check[i];
		//index == j여도 어차피 값은 0이라 상관없음

		sum += s[index][j];
	}

	return sum;
	//if(index != i) sum += [index][i];
}

int totalStats(int** s, int n, int checkA[], int checkB[])
{
	int sumA = 0;
	int sumB = 0;


	//check먼저 합
	for (int i = 0; i < n / 2; i++)
	{
		sumA += sumStat(s, n, checkA, checkA[i]);
	}

	//
	for (int i = 0; i < n / 2; i++)
	{
		sumB += sumStat(s, n, checkB, checkB[i]);
	}

	int number = abs(sumA - sumB);

	return number;
}

void insertCheckB(int checkA[], int checkB[], int n)
{
	bool* s = new bool[n];
	for (int i = 0; i < n; i++)
	{
		s[i] = false;
	}
	for (int i = 0; i < n/2; i++)
	{
		s[checkA[i]] = true;
	}
	
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (!s[i])
		{
			checkB[count] = i;
			count++;
		}
	}

	delete[]s;
}

//0 1
void swapCheck(int checkA[], int checkB[], int n, int index)
{
	for (int i = 0; i < n / 2; i++)
	{
		if (checkA[i] == index)
		{
			checkA[i] = index + 1;
		}
		if (checkB[i] == index + 1)
		{
			checkB[i] = index;
		}
	}

}

//index는 바꿔지는 초창기 index값
int checkStats(int** s, int n, int checkA[], int checkB[], int index, int startindex)
{
	bool isStart = true;
	int min = 999;
	int number;


	for (int i = startindex; i < n / 2 + 1 + index; i++)
	{
		checkA[index] = i;
		if (index < n / 2 - 1)
		{
			number = checkStats(s, n, checkA, checkB, index + 1, i + 1);
		}
		else if (index == n / 2 - 1)
		{
			insertCheckB(checkA, checkB, n);
			number = totalStats(s, n, checkA, checkB);
			//debugCheck(checkA, checkB, n);
		}


		if (number == 0)
		{
			return 0;
		}

		if (isStart)
		{
			isStart = false;
			min = number;
		}
		else if (number < min)
		{
			min = number;
		}
	}

	

	return min;
}

int cal(int** s, int n)
{
	int* checkA = new int[n / 2];
	int* checkB = new int[n / 2];

	bool isStart = true;
	int min;

	//0번째는 무조건 A팀에 있다고 가정
	for (int i = 0; i < n / 2; i++)
	{
		checkA[i] = i;
	}
	for (int i = 0; i < n / 2; i++)
	{
		checkB[i] = i + n / 2;
	}
	//check 아닌 애 따로 빼내서 합

	//대충 스왑함수 4 => 2인덱스 [1 2 3]
	min = checkStats(s, n, checkA, checkB, 1, 1);

	delete[] checkA;
	delete[] checkB;

	return min;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;

	cin >> n;

	int** s = new int* [n];
	for (int i = 0; i < n; i++)
	{
		s[i] = new int[n];
	}



	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> s[i][j];
		}
	}

	cout << cal(s, n) << '\n';
	//cout << ppap << '\n';




	for (int i = 0; i < n; i++)
	{
		delete[] s[i];
	}
	delete[] s;

}