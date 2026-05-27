#include <string>
#include <vector>
#include <queue>

using namespace std;

string solution(vector<string> participant, vector<string> completion)
{
    string answer = "";
    priority_queue<string> part_q;
    priority_queue<string> com_q;
    //map
    
    for(int i = 0; i < participant.size(); i++)
    {
        part_q.push(participant[i]);
    }
    for(int i = 0; i < completion.size(); i++)
    {
        com_q.push(completion[i]);
    }
    
    while(true)
    {
        string p = part_q.top();
        part_q.pop();
        
        if(com_q.empty())
        {
            answer = p;
            break;
        }
        string c = com_q.top();
        com_q.pop();
        
        if(p != c)
        {
            answer = p;
            break;
        }
    }
    
    return answer;
}