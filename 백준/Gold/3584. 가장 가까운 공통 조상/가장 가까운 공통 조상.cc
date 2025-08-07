#include <iostream>
#include <vector>
#include <algorithm>

#define INF 2147483647

using namespace std;


//is not union, vector
//parent length => depth
//root's length is zero, 



//depth is vector's size
//add => vector's content copy paste
vector<int> connect_union(vector<int>& parent_arr, int a)
{
	vector<int> result;
	while (true)
	{
		result.push_back(a);
		if (parent_arr[a] == a) break;
		a = parent_arr[a];
	}

	//myself else put in the result
	return result;
}


int find_LCA(vector<int>& parent_arr, int a, int b)
{
	vector<int> parent_a = connect_union(parent_arr, a); //lower depth is parent
	vector<int> parent_b = connect_union(parent_arr, b); //

	int a_depth = parent_a.size();
	int b_depth = parent_b.size();

	//setting same depth
	while (a_depth != b_depth)
	{
		if (a_depth < b_depth)
		{
			b = parent_arr[b];
			b_depth--;
		}
		else
		{
			a = parent_arr[a];
			a_depth--;
		}
	}

	while (a != b)
	{
		a = parent_arr[a];
		a_depth--;

		b = parent_arr[b];
		b_depth--;
	}
	return a;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t, n;
	int a, b;


	cin >> t;
	while (t--)
	{
		cin >> n;

		//init
		vector<int>parent_arr = vector<int>(n);
		vector<vector<int>>depth_arr = vector<vector<int>>(n);

		for (int i = 0; i < n; i++)
		{
			parent_arr[i] = i;
		}

		//connect Edge
		for (int i = 0; i < n - 1; i++)
		{
			cin >> a >> b;
			a--; b--;

			parent_arr[b] = a;

			//connect_union(parent_arr, depth_arr, a, b);
		}

		//LCA print
		cin >> a >> b;
		a--; b--;
		cout << find_LCA(parent_arr, a, b) + 1 << '\n';
	}
}
