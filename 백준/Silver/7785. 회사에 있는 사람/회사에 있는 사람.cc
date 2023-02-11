#include <iostream>
#include <map>
#include <iterator>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	map<string, bool> company_map;

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string name, b;
		
		cin >> name >> b;

		if (b == "enter")
		{
			if (company_map.count(name)) {
				company_map.at(name) = true;
			}
			else {
				company_map.insert(pair<string, bool>(name, true));
			}
		}
		else {
			company_map.at(name) = false;
		}
	}

	map<string, bool>::iterator it;
	it = company_map.end();
	it--;
	for (; it != company_map.begin(); it--)
	{
		if(it->second == true)
			cout << it->first << '\n';
	}
	if (it->second == true)
		cout << it->first << '\n';


}