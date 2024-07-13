#include <iostream>
#include <deque>

using namespace std;

string boom_str;
string indexToString(int n)
{
	string s = "";
	for (int i = 0; i < n; i++)
	{
		s += boom_str[i];
	}
	return s;
}

string stack_remove(deque<int> &my_deque)
{
	string s = "";
	while (!(my_deque.empty()))
	{
		s += indexToString(my_deque.front());
		my_deque.pop_front();
	}
	return s;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	string s, result = "";
	deque<int> my_deque;
	cin >> s >> boom_str;

	
	for (int i = 0; i < s.size(); i++)
	{
		if (boom_str[0] == s[i])
		{
			my_deque.push_back(1);
			//스택 크기가 1이면 스택 크기 비교해서 스택 pop
			if (my_deque.back() == boom_str.size())
			{
				my_deque.pop_back();
			}
		}
		else if (!(my_deque.empty()))
		{
			//스택 문자열 비교
			if (boom_str[my_deque.back()] == s[i])
			{
				my_deque.back() += 1; //만약 top이 const면
				if (my_deque.back() == boom_str.size())
				{
					my_deque.pop_back();
				}
			}
			else {
				result += stack_remove(my_deque);
				result += s[i];
			}
			
		}
		else 
		{
			result += s[i];
		}
	}
	//남아있는 스택 제거
	result += stack_remove(my_deque);

	if (result == "")
		cout << "FRULA";
	else
		cout << result;
}

