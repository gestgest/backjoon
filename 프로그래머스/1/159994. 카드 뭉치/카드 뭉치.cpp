#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) 
{
    string answer = "";
    int left = 0, right = 0;
    bool isAnswer = true;
    
    for(int i = 0; i < goal.size(); i++)
    {
        if(left < cards1.size() && cards1[left] == goal[i])
        {
            left++;
        }
        else if(right < cards2.size() && cards2[right] == goal[i])
        {
            right++;
        }
        else //둘 다 없다면
        {
            isAnswer = false;
            break;
        }
    }
    
    if(isAnswer)
    {
        answer = "Yes";
    }
    else
    {
        answer = "No";
    }
    
    return answer;
}