#include <string>
#include <vector>

using namespace std;

bool isBig(char c)
{
    if('A' <= c && c <= 'Z')
    {
        return true;
    }
    return false;
}

bool isSmall(char c)
{
    if('a' <= c && c <= 'z')
    {
        return true;
    }
    return false;
}

string solution(string s) {
    string answer = "";
    bool isFirst = true;
    for(int i = 0; i < s.size(); i++)
    {
        if(isFirst && isSmall(s[i]))
        {
            isFirst = false;
            answer += s[i] - 'a' + 'A';
        }
        else if(!isFirst && isBig(s[i]))
        {
            answer += s[i] - 'A' + 'a';
        }
        else if(s[i] == ' ')
        {
            isFirst = true;
            answer += s[i];
        }
        else{
            isFirst = false;
            answer += s[i];
        }
    }
    return answer;
}