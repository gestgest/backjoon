#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;


class Edge {
public:
	int dis;
	int index1;
	int index2;

	Edge(int dis, int index1, int index2) {
		this->dis = dis;
		this->index1 = index1;
		this->index2 = index2;
	}
	const bool operator<(const Edge& edge) const {
		return this->dis > edge.dis;
	}
};


//유니온
int find_union(vector<int>& union_arr, int n)
{
	if (union_arr[n] == n) return n;
	return union_arr[n] = find_union(union_arr, union_arr[n]);
}

void insert_union(vector<int>& union_arr, int a, int b)
{
	a = find_union(union_arr, a);
	b = find_union(union_arr, b);

	if (a < b) {
		union_arr[b] = a;
	}
	else {
		union_arr[a] = b;
	}
}

//6497
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int house_count, edge_count;
	int index1, index2, value;


	while (true)
	{
		int sum = 0;
		int real_sum = 0;
		cin >> house_count >> edge_count;
		vector<int> union_arr = vector<int>(house_count);

		//유니온 설정
		for (int i = 0; i < house_count; i++)
		{
			union_arr[i] = i;
		}

		priority_queue<Edge> edge_pq;

		if (house_count == 0 && edge_count == 0)
			break;

		//양방향 도로
		for (int i = 0; i < edge_count; i++)
		{
			cin >> index1 >> index2 >> value;
			edge_pq.push(Edge(value, index1, index2));
			real_sum += value;
		}

		//가로등 연결
		while (true)
		{
			if (edge_pq.empty()) {
				break;
			}

			Edge edge = edge_pq.top();
			edge_pq.pop();

			index1 = find_union(union_arr, edge.index1);
			index2 = find_union(union_arr, edge.index2);
			if (index1 != index2) {
				insert_union(union_arr, edge.index1, edge.index2);
				sum += edge.dis;
			}
		}

		cout << real_sum - sum << '\n';
	}
}