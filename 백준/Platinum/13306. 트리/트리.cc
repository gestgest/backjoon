#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;
#define INF 2147483647

vector<int> union_arr;
vector<int> parent_arr;
int find_union(int index)
{
	if (index == union_arr[index]) return index;
	return union_arr[index] = find_union(union_arr[index]);
}

//union
void connect_union(int a, int b)
{
	union_arr[find_union(b)] = find_union(a);
}

class Query {
public:
	int a;
	int b;
	int c;
	Query(int a, int b, int c)
	{
		this->a = a;
		this->b = b;
		this->c = c;
	}
};


// union + offline query
//what the offline query
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, q;
	int a, b, c = 1;
	stack<int> ans_stack;
	stack<Query> query_stack;

	cin >> n >> q;
	union_arr = vector<int>(n);
	parent_arr = vector<int>(n);
	
	union_arr[0] = 0;
	parent_arr[0] = 0;
	//root node is only "one"
	for (int i = 1; i < n; i++)
	{
		cin >> a;
		a--;
		parent_arr[i] = a;
		union_arr[i] = i;

		//connect
		//connect_union(a, i); => 1) **Key Point**
	}

	//reverse stack, input stack
	for (int i = 0; i < n + q - 1; i++)
	{
		cin >> a >> b;
		b--;
		if (a == 1)
		{
			cin >> c; c--;
		}
		query_stack.push(Query(a, b, c));
	}

	//query stack pop
	while (!query_stack.empty())
	{
		Query query = query_stack.top();
		query_stack.pop();

		//reverse => connect
		if (query.a == 0)
		{
			connect_union(parent_arr[query.b], query.b);
		}
		//query
		else {
			query.b = find_union(query.b);
			query.c = find_union(query.c);

			//same area
			if (query.b == query.c)
			{
				ans_stack.push(1);
			}
			else
			{
				ans_stack.push(0);
			}
		}
	}

	//print ans (stack)
	while (!ans_stack.empty())
	{
		int ans = ans_stack.top();
		ans_stack.pop();
		if (ans == 1)
		{
			cout << "YES" << '\n';
		}
		else
		{
			cout << "NO" << '\n';
		}
	}
}