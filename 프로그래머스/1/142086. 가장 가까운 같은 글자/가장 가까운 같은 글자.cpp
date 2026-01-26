#include <string>
#include <vector>

#define ALPHA_SIZE 26

using namespace std;


vector<int> solution(string s) 
{
    int before[ALPHA_SIZE];
    vector<int> answer;
    
    for(int i = 0; i < ALPHA_SIZE; i++)
    {
        before[i] = -1;
    }
    
    for(int i = 0; i < s.size(); i++)
    {
        int index = s[i] - 'a';
        if(before[index] == -1)
        {
            answer.push_back(-1);
        }
        else
        {
            answer.push_back(i - before[index]);
        }
        before[index] = i;
    }
    
    return answer;
}