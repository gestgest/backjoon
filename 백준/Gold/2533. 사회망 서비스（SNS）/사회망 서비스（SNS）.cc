#include <iostream>
#include <vector>
#include <algorithm>

#define INF 2147483647

using namespace std;

class State {
public:
	int value[2] = {1, 0};
	//not이 3번을 넘어서는 순간 실패 => 그리고 나중에 큰 값 비교할땐 value[2]은 비교하지 않는다
	
	//1, INF, INF => [2]는 제외 => [0]이 1이면 제외?
	//1, 4, INF => [2]는 제외 => [0]이 1이면 제외?
	//2, 1, 4 => 제일 작은 값 : [1] + 1 또는 [2] + 1 또는 [0] + 1 합, [0] 합, [1] 합
	//2, 2, 1
	//2, 2, 2
	//
};

//4 MB

// (1 + 2, 1)- (1, 2) - (1 , 0)
//                ㄴ (1, 0)
// 
// 1 - 5 - 1 - 1 - 5 - 1
// 1 -               - 1
// 1 -               - 1
// 1 -               - 1
// 근데 이러면 가운데 1 - 1이 적용 안됨
// 
// node[][] 이런식으로 하면 메모리 초과 => 아닌가?
vector<int> node[1000001];
vector<State> state;

//트리 탐색
void dp_tree(int current, int parent)
{
	for (int i = 0; i < node[current].size(); i++)
	{
		int index = node[current][i];
		if (index == parent)
			continue;

		dp_tree(index, current);
		state[current].value[0] += min(state[index].value[0], state[index].value[1]); //여기서 max가 sum으로 해야하는지 각각 해야하는지
		state[current].value[1] += state[index].value[0]; //무조건
		//탐색
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	int a, b;
	cin >> n;

	state = vector<State>(n);
	for (int i = 0; i < n - 1; i++)
	{
		cin >> a >> b;
		a--; b--;
		node[a].push_back(b);
		node[b].push_back(a);
	}

	//tree 탐색
	dp_tree(0, -1);
	
	cout << min(state[0].value[0], state[0].value[1]);
}
