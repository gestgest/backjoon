#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class State {
public:
	int value[3] = {0}; //on, not

	int getMaxValue()
	{
		return max(value[0], value[1]);
	}
};

vector<int> graph[10000];
vector<State> state;


void dp_make(int current, int parent)
{
	for (int i = 0; i < graph[current].size(); i++)
	{
		int index = graph[current][i];

		if (index == parent)
			continue;

		dp_make(index, current);
		state[current].value[0] += max(state[index].value[1], state[index].value[2]);
		state[current].value[1] += max(state[index].value[0], state[index].value[1]); //예제
		state[current].value[2] += state[index].value[1];
	}
}

//우수마을은 인접할 수 없다 => [0] += [1]
//무조건 인접 노드에는 우수마을이 있어야 한다
//
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, i;
	int a, b;
	cin >> n;

	state = vector<State>(n);
	for (i = 0; i < n; i++)
	{
		cin >> state[i].value[0];
	}


	for (i = 0; i < n - 1; i++)
	{
		cin >> a >> b;
		a--; b--;

		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	dp_make(0, -1);

	cout << state[0].getMaxValue();
}