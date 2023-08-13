#include <iostream>
#include <map>
#include <iterator>
using namespace std;


class Seq {
public:
	int left_count;
	int right_count;
};

int maxN(int a, int b) {
	if (a < b) {
		return b;
	}
	else
		return a;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	int num;
	int max = 0;
	map<int, Seq> seq_map;
	map<int, Seq>::iterator it;
	
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int left_count = 0;
		int right_count = 0;

		cin >> num;

		for (it = seq_map.begin(); it != seq_map.end(); it++)
		{
			//작은 dp값 비교 [우상향인 놈만 => 우상향 count]
			if (it->first < num) {
				left_count = maxN(left_count, it->second.left_count);
			}
			else if (num < it->first) {
				//right, left 둘다 비교
				right_count = maxN(right_count, it->second.left_count);
				right_count = maxN(right_count, it->second.right_count);
			}
		}
		left_count++;
		right_count++;
		if (!seq_map.count(num)) {
			Seq seq;
			seq.left_count = left_count;
			seq.right_count = right_count;
			seq_map.insert(make_pair(num, seq));
		}
		else {
			Seq seq = seq_map[num];
			seq.left_count = maxN(seq.left_count, left_count);
			seq.right_count = maxN(seq.right_count, right_count);
			seq_map[num] = seq;
		}
		max = maxN(max, left_count);
		max = maxN(max, right_count);
		//큰 dp값 비교 [우하향인 놈만 => 우하향 count]
		//삽입될땐 기존 값이랑 비교
	}

	cout << max << '\n';

}