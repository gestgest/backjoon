#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;
#define INF 2147483647

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t;
	int n, m;
	int a, b;

	cin >> t;

	while (t--)
	{
		cin >> n;

		queue<int> index_queue;
		stack<int> ans_stack;

		vector<int> graph_count = vector<int>(n, 0); //1등이 n - 1, 꼴지가 0 => 인덱스는 그래프값
		vector<int> rank = vector<int>(n);
		vector<int> value_to_rank = vector<int>(n);

		//그냥 graph값으로 하면 안되나
		bool graph[500][500] = {false}; //y가 출발 -> x가 도착

		//순위 결정
		for (int i = 0; i < n; i++)
		{
			//a => 팀 번호
			cin >> a;
			a--;
			rank[i] = a;
			value_to_rank[a] = i;

			//n ^ 2
			for (int j = 0; j < i; j++)
			{
				graph[a][rank[j]] = true;
				graph_count[rank[j]]++;
			}
		}

		int min_index = rank[n - 1];
		//체인지 횟수
		cin >> m;

		for (int i = 0; i < m; i++)
		{
			//팀 번호임
			cin >> a >> b;
			a--; b--;

			//a => 등수가 낮아야함
			if (value_to_rank[a] > value_to_rank[b])
			{
				int tmp = a;
				a = b;
				b = tmp;
			}

			//b가 감소 
			graph[b][a] = false; 
			graph_count[a]--;
			if (graph_count[a] == 0)
				min_index = a;

			graph[a][b] = true;
			graph_count[b]++;
		}

		//0이 아니라면 => Impossible
		if (graph_count[min_index] == 0)
		{
			index_queue.push(min_index);
		}

		while (!index_queue.empty())
		{
			int index = index_queue.front();
			index_queue.pop();

			ans_stack.push(index);
			for (int i = 0; i < n; i++)
			{
				if (graph[index][i])
				{
					graph_count[i]--;
					if(graph_count[i] == 0)
					{
						index_queue.push(i);
					}
				}
			}
		}

		if (ans_stack.size() != n)
		{
			cout << "IMPOSSIBLE" << '\n';
			continue;
		}

		while (!ans_stack.empty())
		{
			int index = ans_stack.top();
			ans_stack.pop();

			cout << index + 1 << ' ';
		}
		cout << '\n';
	}
}