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
	sum += dis;

	for (i = 1; i < house.size(); i++)
	{
		//간소화[★]
		if (sum <= house[i])
		{
			sum = house[i];
			sum += dis;
			count++;
		}
	}
	//
	if (count < c)
		return -1;
	return dis;
}


int wife_binary_search(vector<int>& house, int start, int end, const int max, const int c)
{
	//이것을 맨 앞에 넣었어야 함[★]
	//이런 배열탐색전 조건문은 맨 앞에
	if (end < start) {
		return 0;
	}
	int mid = (start + end) / 2;
	int jud = indexSearch(house, mid, c, max);


	// dis값이 큰 경우
	if (jud == -1) {
		return wife_binary_search(house, start, mid - 1, max, c);
	}
	else {
		int num = wife_binary_search(house, mid + 1, end, max, c);
		return (num > jud) ? num : jud;
	}

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
	num = (max - min) / (c - 1); //이 값을 넘을 수 없음 [기존의 탑]


	//간격으로 이분탐색하는게 포인트
	//1 ~ num값의 이진탐색
	cout << wife_binary_search(house, 1, num, max, c) << '\n';
	//1~num
}

