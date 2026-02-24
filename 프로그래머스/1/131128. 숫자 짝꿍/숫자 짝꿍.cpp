#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string x, string y) 
{
    string answer = "";
    int s[2][10] = {0};
    
    for(int i = 0; i < x.size(); i++)
    {
        s[0][x[i] - '0']++;
    }
    for(int i = 0; i < y.size(); i++)
    {
        s[1][y[i] - '0']++;
    }
    for(int i = 9; i >= 0; i--)
    {
        for(int j = 0; j < min(s[0][i], s[1][i]); j++)
        {
            answer += i +'0';
        }
    }
    
    if(answer == "")
    {
        answer += "-1";
    }
    else if(answer[0] == '0' && answer[answer.size() - 1] == '0')
    {
        answer = "0";
    }
    
    return answer;
}