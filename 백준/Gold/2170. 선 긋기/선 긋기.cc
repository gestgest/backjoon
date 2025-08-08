#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define INF 2147483647


class Line {
public:
	int start;
	int end;
	Line(int start, int end)
	{
		this->start = start;
		this->end = end;
	}
};


//asc => 우선순위 큐의 정렬 기준과 다름
bool compare(Line a, Line b)
{
	if (a.start < b.start)
	{
		return true;
	}
	else if (a.start > b.start)
	{
		return false;
	}

	return a.end < b.end;
}


int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;

	int a, b;
	int sum_dis = 0;

	vector<Line> lines;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		lines.push_back(Line(a,b));
	}

	sort(lines.begin(), lines.end(), compare);
	int left = -INF;
	int right = -INF;

	for (int i = 0; i < n; i++)
	{
		if (right < lines[i].start)
		{
			sum_dis += right - left;
			left = lines[i].start;
		}

		//끝에 있는 경우
		if(right < lines[i].end) right = lines[i].end;
	}
	sum_dis += right - left;

	cout << sum_dis << '\n';

}