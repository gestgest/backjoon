#include <iostream>
#include <vector>
#include <algorithm>

#define INF 2147483647

using namespace std;
vector<int> house;
int n, c;

//1 2 4 8 9
//1 => 2 (1) => 9
//1 => 4 (3) => 9
//1 => 8 (7) => 9 (1)

//길이 찾기 => 탐색한 길이로 직접 실행해본다 => 되면 그 값 리턴 안되면 -1.
int search_dis(int dis)
{
	int count = 0;
	int sum = 0; //sum + dis
	for(int i = 0; i < n; i++)
	{ 
		//만약 dis값이 
		if (sum <= house[i])
		{
			sum = house[i] + dis;
			count++;
		}
		if (c == count) {
			return dis;
		}
	}

	if (count < c) {
		return -1;
	}

	return dis;
}


//이분탐색 => 이분탐색할 것은 길이.
int binary_search_dis(int start, int end)
{
	if (start > end) {
		return -1;
	}
	int mid = (start + end) / 2;
	int num = search_dis(mid);//길이 찾기

	//이분탐색 => dis값이 너무 크다
	if (num == -1) {
		return binary_search_dis(start, mid - 1);
	}
	else {
		return max(binary_search_dis(mid + 1, end), num);
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> c;
	house = vector<int>(n);

	for (int i = 0; i < n; i++)
	{
		cin >> house[i];
	}
	sort(house.begin(), house.end());
	int num = (house[n - 1] - house[0]) / (c - 1); //이것보다 큰 거리 값은 나올 수 없음

	cout << binary_search_dis(1, num) << '\n';

	//이분탐색급으로 나눈다 => 
}
