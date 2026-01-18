#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

#define INF 2147483647


class Number {
public:
	int index;
	int value;
	bool operator < (const Number& number) const &
	{
		if (this->value > number.value)
		{
			return true;
		}
		else if (this->value < number.value)
		{
			return false;
		}
		if (this->index > number.index)
		{
			return true;
		}
		return false;
	}
};
vector<Number>input;
vector<int> segmentTree;

//init는 안해도 될지도?

//targetIndex는 start end의 index다.
void addSegmentTree(int start, int end, int index, int targetIndex)
{
	segmentTree[index]++;

	if (end == start)
	{
		return;
	}

	int mid = (start + end) / 2;

	if (targetIndex <= mid)
	{
		addSegmentTree(start, mid, 2 * index, targetIndex);
	}
	else
	{
		addSegmentTree(mid + 1, end, 2 * index + 1, targetIndex);
	}
}

long long querySegmentTree(int start, int end, int target_start, int target_end, int index)
{
	if (end < target_start || target_end < start)
	{
		return 0;
	}
	if (target_start <= start && end <= target_end)
	{
		return segmentTree[index];
	}

	int mid = (start + end) / 2;

	long long left = querySegmentTree(start, mid, target_start, target_end, index * 2);
	long long right = querySegmentTree(mid + 1, end, target_start, target_end, index * 2 + 1);

	return left + right;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	long long sum = 0;
	priority_queue<Number> pq;

	cin >> n;
	input = vector<Number>(n);
	segmentTree = vector<int>(4 * n, 0);

	for (int i = 0; i < n; i++)
	{
		cin >> input[i].value;
		input[i].index = i;
		pq.push(input[i]);
	}

	//미리정렬
	//sort(input.begin(), input.end());

	//오름차순으로 제거
	//ㄴ 버블정렬은 내 기준 오른쪽 노드가 작은 갯수만큼 swap한다.
	//ㄴ 그것을 이용해서 가변하는 가중치합을 계산하면 된다.
	while (!pq.empty())
	{
		Number number = pq.top();
		pq.pop();

		//query
		//number.index + 1로 하기에는 마지막 노드인 경우 오류가 생긴다. 그래서 아쉽게도 계산 하나를 추가하고 number.index로 하기로 했다.
		sum += querySegmentTree(0, n - 1, number.index, n - 1, 1);

		//add
		addSegmentTree(0, n - 1, 1, number.index);
	}
	cout << sum << '\n';

}