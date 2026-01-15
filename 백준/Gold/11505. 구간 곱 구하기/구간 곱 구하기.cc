#include <iostream>
#include <vector>
#include <algorithm>

#define INF 2147483647
#define DIV_VALUE 1000000007

using namespace std;

vector<long long> inputV;
vector<long long> segmentTree;


//index는 1이 root
//start ~ end가 구간합 segmentTree가 그 트리 index
long long init(int start, int end, int index)
{
	if (start == end) return segmentTree[index] = inputV[start];
	int mid = (start + end) / 2;

	return segmentTree[index] = (init(start, mid, index * 2) * init(mid + 1, end, index * 2 + 1)) % DIV_VALUE; //여기 start end 값 다시 봐라
}

//index는 segmentTree의 인덱스다. 초기에는 index는 1을 넣도록
long long addValue(int start, int end, int index, int targetInputIndex)
{
	
	if(start == end) return segmentTree[index] = inputV[start]; //targetInputIndex = start = end

	int mid = (start + end) / 2;

	//<-
	if (mid >= targetInputIndex)
	{
		return segmentTree[index] = addValue(start, mid, index * 2, targetInputIndex) * segmentTree[index * 2 + 1] % DIV_VALUE;
	}
	//->
	else 
	{
		return segmentTree[index] = segmentTree[index * 2] * addValue(mid + 1, end, index * 2 + 1, targetInputIndex) % DIV_VALUE;
	}
}

long long printSum(int start, int end,int target_start, int target_end, int index)
{
	//start end가 범위~범위 안에 있다면 그냥 segment index 출력
	//아예없다면 return 1;
	if (target_start <= start && end <= target_end)
	{
		return segmentTree[index];
	}
	else if(end < target_start || target_end < start) //범주 바깥
	{
		return 1;
	}

	int mid = (start + end) / 2;

	return printSum(start, mid, target_start, target_end, 2 * index) 
		* printSum(mid + 1, end, target_start, target_end, 2 * index + 1) 
		% DIV_VALUE;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);


	int n, m, k;
	int a, b, c;
	cin >> n >> m >> k;

	segmentTree = vector<long long>(4 * n);
	inputV = vector<long long>(n);

	for (int i = 0; i < n; i++)
	{
		cin >> inputV[i];
	}
	init(0, n - 1, 1);

	//1은 
	//2가 출력
	for (int i = 0; i < m + k; i++)
	{
		cin >> a >> b >> c;
		b--;
		if (a == 1) //addValue
		{
			inputV[b] = c;
			addValue(0, n - 1, 1, b);
		}
		if (a == 2) //print
		{
			c--;
			cout << printSum(0, n - 1, b, c, 1) << '\n';
		}
	}
}
