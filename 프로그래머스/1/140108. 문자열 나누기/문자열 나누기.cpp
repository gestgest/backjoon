#include <string>
#include <vector>

using namespace std;

int solution(string s) 
{
    int answer = 0;
    bool isFirst = true;
    char firstChar;
    int count[2]; //갯수
    
    for(int i = 0; i < s.size(); i++)
    {
        if(isFirst)
        {
            firstChar = s[i];
            isFirst = false;
            count[0] = 1;
            count[1] = 0;
        }
        else if(firstChar == s[i])
        {
            count[0]++;
        }
        else
        {
            count[1]++;
        }
        if(count[0] == count[1])
        {
            isFirst = true;
            answer++;
        }
        
    }
    if(!isFirst)
    {
        answer++;
    }
    return answer;
}