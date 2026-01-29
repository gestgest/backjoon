#include <iostream>
#include <vector>

using namespace std;

#define INF 2147483647


class DVD{
public:
	int min_value;
	int max_value;
	DVD() 
	{
		max_value = -2147483646;
		min_value = INF;
	}
	DVD(int value)
	{
		min_value = value;
		max_value = value;
	}
	DVD setDVD(int value)
	{
		min_value = value;
		max_value = value;
		return *this;
	}
	DVD setDVD(DVD a, DVD b)
	{
		if (a.min_value < b.min_value)
		{
			min_value = a.min_value;
		}
		else
		{
			min_value = b.min_value;
		}

		if (a.max_value < b.max_value)
		{
			max_value = b.max_value;
		}
		else
		{
			max_value = a.max_value;
		}
		return *this;
	}
};

vector<DVD> segmentTree;
vector<int> inputY;

//init
DVD init(int start, int end, int index)
{
	if (start == end) return segmentTree[index].setDVD(inputY[start]);

	int mid = (start + end) / 2;
	return segmentTree[index].setDVD(init(start, mid, 2 * index), init(mid + 1, end, 2 * index + 1));
}


//target_index는 start end사이
DVD addSegmentTree(int start, int end, int target_index, int index)
{
	//흐음
	if (target_index < start || end < target_index)
		return segmentTree[index];

	//단말노드
	if (start == end) return segmentTree[index].setDVD(inputY[start]);

	int mid = (start + end) / 2;

	DVD left = addSegmentTree(start, mid, target_index, 2 * index);
	DVD right = addSegmentTree(mid + 1, end, target_index, 2 * index + 1);
	/*if (mid >= target_index)
	{
		return segmentTree[index].setDVD(addSegmentTree(start, mid, target_index, 2 * index), segmentTree[2 * index + 1]);
	}
	else
	{
		return segmentTree[index].setDVD(segmentTree[2 * index], addSegmentTree(mid + 1, end, target_index, 2 * index + 1));
	}*/

	return segmentTree[index].setDVD(left, right);
}

DVD querySegmentTree(int start, int end, int targetStart, int targetEnd, int index)
{
	//범주 바깥
	if (end < targetStart || targetEnd < start)
	{
		return segmentTree[0]; //min = INF, max = -1
	}
	//범주
	if (targetStart <= start && end <= targetEnd)
	{
		return segmentTree[index];
	}

	int mid = (start + end) / 2;
	DVD dvd;
	return dvd.setDVD(querySegmentTree(start, mid, targetStart, targetEnd, 2 * index),
		querySegmentTree(mid + 1, end, targetStart, targetEnd, 2 * index + 1));
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	//L ~ R
	int t, n, k;
	int a, b, c;
	cin >> t;
	segmentTree = vector<DVD>(400005);
	inputY = vector<int>(100005);

	//트리 값은 max, min값으로 설정
	while (t--)
	{
		cin >> n >> k;

		for (int i = 0; i < n; i++)
		{
			inputY[i] = i;
		}
		init(0, n - 1, 1);


		//그냥 단일 노드만 수정할까?
		//아 그냥 노드에 true, false만 넣어서 만약 바뀌어도 변함이 없다면 true, 변함이 있다면 false

		for (int i = 0; i < k; i++)
		{
			cin >> a >> b >> c;

			//change
			if (a == 0)
			{
				int tmp = inputY[b];
				inputY[b] = inputY[c];
				inputY[c] = tmp;

				addSegmentTree(0, n - 1, b, 1);
				addSegmentTree(0, n - 1, c, 1);
			}
			//query
			else 
			{
				DVD dvd = querySegmentTree(0, n - 1, b, c, 1);
				if (dvd.min_value == b && dvd.max_value == c)
				{
					cout << "YES" << '\n';
				}
				else 
				{
					cout << "NO" << '\n';
				}
			}
		}
	}
}