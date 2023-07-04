#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//dis는 간격
//리턴 값은 -1은 안됨 [dis값이 크다.] =>  나머지 값은 딱 됨
int indexSearch(vector<int>& house, int dis, int c, int max)
{
	int sum = house[0];
	int i;
	int count = 1;
	int min = 0;
	sum += dis;
	
	for (i = 1; i < house.size(); i++)
	{
		// = 
		if (sum == house[i])
		{
			sum += dis;
			count++;
			min = dis;
		}
		else if (sum < house[i]) {
			int num = house[i] - sum;
			num += dis;
			if (0 == min) {
				min = num;
			}
			else if (num < min) {
				min = num;
			}

			sum = house[i];

			sum += dis;
			count++;
		}
	}
	//
	if (count < c)
		return -1;
	return min;
}


int wife_binary_search(vector<int> &house,int start, int end, const int max, const int c)
{
	int mid = (start + end) / 2;
	if (1 == end)
	{
		return 1;
	}

	if (end < start) {
		return 0;
	}
	int jud = indexSearch(house, mid, c, max);


	//무조건 앞으로 넘겨야 할듯
	//단, return에서 if로 큰 값 비교
	if (jud == -1) {
		if (end <= start) {
			return 0;
		}
		return wife_binary_search(house, start, mid, max, c);
	}
	else {
		int num = wife_binary_search(house, mid + 1, end, max, c);
		return (num > jud) ? num : jud;
	}

	//대충 함수 마지막 함수 인덱스 출력 또는 -1
	// -1이면 넘친다. = end값을 mid
	// else start값을 mid + 1
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	vector<int> house = vector<int>();
	int n, c, num;

	cin >> n >> c;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		house.push_back(num);
	}
	sort(house.begin(), house.end());

	int min = house[0];
	int max = house[n - 1];
	num = (max - min) / (c - 1);


	//간격으로 이분탐색하는게 포인트
	//1 ~ num값의 이진탐색
	cout << wife_binary_search(house, 1, num, max, c) << '\n';
	//1~num
}

/*
5 3
1 2 8 4 9
=> 3

5 2
1 2 3 9 22
=> 21

5 3
1 2 3 9 22
=>8

6 4
1 2 4 8 9 11

10 3
1 2 3 6 40 68 88 90 140 203
=> 89

10 4
1 10 21 33 34 35 36 80 98 121
=> 35
*/