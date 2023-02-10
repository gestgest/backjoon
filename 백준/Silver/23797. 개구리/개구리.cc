#include <iostream>
#include <string>
#include <vector>
using namespace std;


int p_count = 0;
int k_count = 0;

bool vector_add(char c)
{

	//p가 있는지 [PK인 경우]
	if (0 < p_count && c == 'K')
	{
		p_count--;
		k_count++;
		return false;
	}
	//KP인 경우 [이때 KPK이면 ]
	else if (0 < k_count && c == 'P')
	{
		k_count--;
		p_count++;
		return false;
	}
	
	if (c == 'P')
	{
		p_count++;
	}
	else if (c == 'K')
	{
		k_count++;
	}
	
	//없으면 새로운 벡터 추가
	return true;
}

int main() 
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);


	string s;
	cin >> s;

	int count = 0;

	for (int i = 0; i < s.length(); i++)
	{
		if (vector_add(s[i]))
		{
			count++;
		}
	}

	cout << count << "\n";

}



//PPKKPPKKP
//KKPKPPKKKP
//쿠엑
//쿠쿠엑쿠엑엑쿠쿠쿠엑
//1 3에 쿠엑/ 2 5에 쿠엑 /4 6에 쿠엑