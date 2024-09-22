#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class DynamicNode {
public:
	int not_value = 0;
	int value;
};

vector<int> graph[10000];
vector<int> ans;
vector<DynamicNode> weight_nodes;

//매우 기본적인 DP 트리 틀
void dp(int current, int parent)
{
	for (int i = 0; i < graph[current].size(); i++)
	{
		int index = graph[current][i];
		if (index != parent)
		{
			dp(index, current);
			weight_nodes[current].not_value += max(weight_nodes[index].not_value, weight_nodes[index].value);
			weight_nodes[current].value += weight_nodes[index].not_value;//
		}
		//5 - 5 - 5 - 10억
		//    ㄴ 5
		//    ㄴ 5
		//10억인지 5인지 고르는게 max함수 쪽
	}
}

void find_ans(int current, int parent, bool isInclude)
{
	if (isInclude)
	{
		ans.push_back(current); //경로
	}
	for (int i = 0; i < graph[current].size(); i++)
	{
		int index = graph[current][i];
		bool _isInclude = isInclude;
		if (index == parent)
		{
			continue;
		}
		if (_isInclude)
		{
			_isInclude = false;
		}
		else {
			_isInclude = weight_nodes[index].not_value < weight_nodes[index].value;
		}
		
		find_ans(index, current, _isInclude);
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	int a, b;
	cin >> n;
	weight_nodes = vector<DynamicNode>(n);

	//한 마디로 연결 안 된 노드끼리의 집합의 가장 큰 합을 구해라. 그리고 그 노드의 index를 적어라
	for (int i = 0; i < n; i++)
	{
		cin >> weight_nodes[i].value;
	}

	//간선 설정
	for (int i = 0; i < n - 1; i++)
	{
		cin >> a >> b;
		a--; b--;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	dp(0, -1);
	if (weight_nodes[0].not_value > weight_nodes[0].value)
		cout << weight_nodes[0].not_value << '\n';
	else
		cout << weight_nodes[0].value << '\n';

	// 최단거리 추적
	find_ans(0, -1, weight_nodes[0].not_value < weight_nodes[0].value);

	sort(ans.begin(), ans.end());

	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] + 1 << ' ';
	}

	/* 아래의 함수만으로 찾아야 한다 => 기본 DP 트리 틀
	* def countSubtreeNodes(currentNode) :
    size[currentNode] = 1 // 자신도 자신을 루트로 하는 서브트리에 포함되므로 0이 아닌 1에서 시작한다.
    for Node in currentNode’s child:
        countSubtreeNode(Node)
        size[currentNode] += size[Node]
	*/
}