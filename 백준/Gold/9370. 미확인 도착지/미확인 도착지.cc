#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define INF 2147483647

class Road {
public:
	int dst;
	int value;
	Road(int dst, int value) {
		this->dst = dst;
		this->value = value;
	}
};

int shortest_path(vector<Road> v[], int start, int end, int node)
{
	vector<int> output = vector<int>(node);
	for (int i = 0; i < node; i++)
	{
		output[i] = INF;
	}
	queue<Road> q;
	q.push(Road(start, 0));

	while (!q.empty())
	{
		Road road = q.front();
		q.pop();
		if (output[road.dst] <= road.value)
			continue;

		output[road.dst] = road.value;
		if (road.dst == end)
			return output[road.dst];

		for (int i = 0; i < v[road.dst].size(); i++)
		{
			q.push(Road(v[road.dst][i].dst, v[road.dst][i].value + road.value));
		}
	}
}

void shortest_path_list(vector<Road> v[], int start, vector<int>& dst_list, int output[], int node)
{
	for (int i = 0; i < node; i++)
	{
		output[i] = INF;
	}
	queue<Road> q;
	q.push(Road(start, 0));

	while (!q.empty())
	{
		Road road = q.front();
		q.pop();
		if (output[road.dst] <= road.value)
			continue;

		output[road.dst] = road.value;

		for (int i = 0; i < v[road.dst].size(); i++)
		{
			q.push(Road(v[road.dst][i].dst, v[road.dst][i].value + road.value));
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int T;
	int crossline, road_size, dst_size;
	int start, g,h; //무조건 g => h를 지나야 함
	int a, b, value;
	cin >> T;
	while (T--)
	{
		vector<Road> v[2000];
		vector<int> dst;
		cin >> crossline >> road_size >> dst_size;
		cin >> start >> g >> h;
		int dis[3][2000]; //0 => start, 1 => g, 2 => h

		start--; g--; h--;
		for (int i = 0; i < road_size; i++)
		{
			cin >> a >> b >> value;
			v[a - 1].push_back(Road(b - 1, value));
			v[b - 1].push_back(Road(a - 1, value));
		}

		//목적지
		for(int i = 0; i < dst_size; i++)
		{
			//목적지
			cin >> value;
			dst.push_back(value - 1);
		}
		sort(dst.begin(), dst.end());

		//start <-> dst목록
		shortest_path_list(v, start, dst, dis[0], crossline);
		shortest_path_list(v, g, dst, dis[1], crossline);
		shortest_path_list(v, h, dst, dis[2], crossline);

		//start <-> crossline[0] <-> crossline[0]과 [1] 사이 <-> 1과 dst 목록
		// or => 누가 더 작은지 => 일단 구하고 중간에 0과 1사이를 구해서 더하면 된다
		//start <-> crossline[1] <-> crossline[0]과 [1] 사이 <-> 0과 dst 목록

		// 비교
		//즉 start에서 한번 [0]에 한번 [1]에 한번 => list최단거리

		//만약 크기가 다르면 출력 X

		int dis_crossline = shortest_path(v,g,h,crossline);


		for (int i = 0; i < dst_size; i++)
		{
			long long num[3];
			num[0] = dis[0][g] + dis[2][dst[i]];
			num[1] = dis[0][h] + dis[1][dst[i]];

			if (num[0] > num[1])
			{
				num[0] = num[1];
			}
			num[0] += dis_crossline;

			num[2] = dis[0][dst[i]];
			if (num[0] == num[2])
			{
				cout << dst[i] + 1 << ' ';
			}
		}
		cout << '\n';

	}

}