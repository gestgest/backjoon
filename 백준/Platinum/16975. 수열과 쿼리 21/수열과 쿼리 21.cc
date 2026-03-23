#include <iostream>
#include <queue>

#define INF 2147483647

using namespace std;

vector<int> s;
vector<long long> dp;


//init, index는 dp의 index. 초반에는 1
void init(int index, int start, int end)
{
	if (start == end)
	{
		dp[index] = s[start];
		return;
	}
	int mid = (start + end) / 2;
	init(index * 2, start, mid);
	init(index * 2 + 1, mid + 1, end);
}

//add
void add(int index, int start, int end, int target_start, int target_end, int value)
{
	//범위 밖?
	if (target_end < start || end < target_start)
	{
		return;
	}
	//매우 범위 안
	if (target_start <= start && end <= target_end)
	{
		dp[index] += value;
		return;
	}
	int mid = (start + end) / 2;
	add(index * 2, start, mid, target_start, target_end, value);
	add(index * 2 + 1, mid + 1, end, target_start, target_end, value);
}

//query  (모든 과정을 합치면 됨)
long long query(int index, int start, int end, int target_input_index)
{
	long long result = dp[index];
	if (start == end) return result;

	int mid = (start + end) / 2;
	if (target_input_index <= mid)
	{
		result += query(index * 2, start, mid, target_input_index);
	}
	else
	{
		result += query(index * 2 + 1, mid + 1, end, target_input_index);
	}
	return result;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, q;
	int num, a,b,c;

	cin >> n;
	s = vector<int>(n);
	dp = vector<long long>(4 * n, 0);

	//배열 입력
	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
	}
	
	//init
	init(1, 0, n - 1);

	//쿼리 개수
	cin >> q;
	for (int i = 0; i < q; i++)
	{
		cin >> num;

		cin >> a;
		a--;
		if (num == 1)
		{
			cin >> b >> c;
			b--;
			add(1, 0, n - 1, a, b, c);
		}
		else
		{
			cout << query(1, 0, n - 1, a) << '\n';
		}
	}

}