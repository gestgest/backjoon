#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool s[21][41];
int r, c;

int cal_area(int x, int y, int max_x, int max_y)
{
	for (int i = y; i <= max_y; i++)
	{
		for (int j = x; j <= max_x; j++)
		{
			if (s[i][j]) {
				return -1;
			}
		}
	}
	return (max_x - x + 1) * (max_y - y + 1);
}

int max_value(int x, int y)
{
	int max = 0;
	int value;
	//값 범주
	for (int i = 0; i < r - y ; i++)
	{
		for (int j = 0; j < c - x; j++)
		{
			//시작점 [y~i][x~j]
			value = cal_area(x, y, x + j, y + i);
			if (value > max) {
				max = value;
			}
		}
	}
	return max;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	//r, c
	//기둥 갯수
	//기둥의 rc 위치
	int x, y;
	int wall_count;
	
	//20, 40
	cin >> r >> c;
	cin >> wall_count;

	//초기화
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			s[i][j] = false;
		}
	}

	//벽 입력
	for (int i = 0; i < wall_count; i++)
	{
		cin >> y >> x;
		s[y - 1][x - 1] = true;
	}

	int max = 0;
	//시작점
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (s[i][j]) {
				continue;
			}
			int value = max_value(j, i);
			if (max < value) 
			{
				max = value;
			}
		}
	}
	cout << max;
}