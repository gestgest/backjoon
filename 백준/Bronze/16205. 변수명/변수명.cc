#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> camelFunc(string s){
	vector<string> result;
	result.push_back("");

	for (int i = 0; i < s.size(); i++)
	{
		if ('A' <= s[i] && s[i] <= 'Z')
		{
			if(i != 0)
				result.push_back("");
			s[i] = s[i] - 'A' + 'a';
		}
		result[result.size() - 1] += s[i];

	}
	return result;
}

vector<string> snackFunc(string s) 
{
	vector<string> result;
	result.push_back("");

	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '_')
		{
			result.push_back("");
			continue;
		}
		else if ('A' <= s[i] && s[i] <= 'Z')
		{
			s[i] = s[i] - 'A' + 'a';
		}
		result[result.size() - 1] += s[i];

	}

	return result;
}

vector<string> pascalFunc(string s) {
	vector<string> result;

	for (int i = 0; i < s.size(); i++)
	{
		if ('A' <= s[i] && s[i] <= 'Z')
		{
			result.push_back("");
			s[i] = s[i] -'A' + 'a';
		}
		result[result.size() - 1] += s[i];

	}
	return result;
}

/// <summary>
/// /////////////////////////////////////////
/// </summary>
/// <param name="v"></param>
/// <returns></returns>

string toCamelFunc(vector<string> v)
{
	string s = "";
	for (int i = 0; i < v.size(); i++)
	{
		if (i != 0)
		{
			v[i][0] = v[i][0] - 'a' + 'A';
		}
		s += v[i];
	}
	return s;
}

string toSnackFunc(vector<string> v)
{
	string s = "";
	for (int i = 0; i < v.size(); i++)
	{
		if (i != 0) {
			s += '_';
		}
		s += v[i];
	}
	return s;
}

string toPascalFunc(vector<string> v)
{
	string s = "";
	for (int i = 0; i < v.size(); i++)
	{
		v[i][0] = v[i][0] - 'a' + 'A';
		s += v[i];
	}
	return s;
}


int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int num;
	string s;
	vector<string> v;

	cin >> num >> s;


	switch (num) {
	case 1:
		v = camelFunc(s);
		break;
	case 2:
		v = snackFunc(s);
		break;
	case 3:
		v = pascalFunc(s);
		break;
	}

	cout << toCamelFunc(v) << '\n';
	cout << toSnackFunc(v) << '\n';
	cout << toPascalFunc(v) << '\n';
}