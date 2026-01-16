#include <iostream>
#include <vector>

using namespace std;

#define INF 2147483647

vector<int> input;

class Value {
public:
	int max = 0;
	int min = INF;
	void setValue(int value)
	{
		this->max = value;
		this->min = value;
	}
	void setValue(Value& a, Value& b)
	{
		if (a.max > b.max)
		{
			this->max = a.max;
		}
		else {
			this->max = b.max;
		}

		if (a.min > b.min)
		{
			this->min = b.min;
		}
		else {
			this->min = a.min;
		}
	}
};
vector<Value> segmentTree;

//index는 segment
void init(int start, int end, int index)
{
	if (start == end) 
	{
		segmentTree[index].setValue(input[start]);
		return;
	}
	int mid = (start + end) / 2;
	init(start, mid, index * 2);
	init(mid + 1, end, index * 2 + 1);

	segmentTree[index].setValue(segmentTree[index * 2], segmentTree[index * 2 + 1]);
}

Value queryValue(int start, int end,int targetStart, int targetEnd, int index)
{
	//범주 내
	if (targetStart <= start && end <= targetEnd)
	{
		return segmentTree[index];
	}
	if (end < targetStart || targetEnd < start)
	{
		return segmentTree[0];
	}

	Value value;
	int mid = (start + end) / 2;

	Value left = queryValue(start, mid, targetStart, targetEnd, index * 2);
	Value right = queryValue(mid + 1, end, targetStart, targetEnd, index * 2 + 1);
	value.setValue(left, right);
	return value;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	int a, b;

	cin >> n >> m;
	input = vector<int>(n);
	segmentTree = vector<Value>(4 * n);

	for (int i = 0; i < n; i++)
	{
		cin >> input[i];
	}
	init(0, n - 1, 1);

	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;

		a--; b--;

		Value value = queryValue(0, n - 1, a, b, 1);
		cout << value.min << ' ' << value.max << '\n';
	}

}