#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int binary_search_index(int *s, int start, int end, const int num, const int n)
{
	if (start > end) {
		return start;
	}
	int mid = (start + end) / 2;

	if (s[mid] < num) {
		return binary_search_index(s, mid + 1, end, num, n);
	}
	else {
		return binary_search_index(s, start, mid - 1, num, n);
	}

}

//투포인터 + 이분탐색
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int s[2000];
	bool isCheck[2000] = { false };

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
	}
	sort(s, s + n);

	//투포인터
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			int num = s[i] + s[j];
			int index; //이분탐색 반환 index

			//대충 이분 탐색
			index = binary_search_index(s, 0, n - 1, num, n);

			if (index >= n)
				break;

			if (index == i || index == j)
				continue;

			if (s[index] == num) {
				isCheck[index] = true;
			}
		}
	}
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		//0 0 0 0 파훼
		if (i != 0 && isCheck[i - 1] && s[i] == s[i - 1]) {
			isCheck[i] = true;
		}
		if (isCheck[i])
			sum++;
	}
	cout << sum << '\n';
}
//67%