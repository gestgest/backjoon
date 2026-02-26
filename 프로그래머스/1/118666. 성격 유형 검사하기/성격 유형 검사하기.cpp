#include <string>
#include <vector>

using namespace std;


void selectSurvey(int *s, char c, int value)
{
    switch(c) {
        case 'R':
            s[0] += value;
            break;
        case 'T':
            s[0] -= value;
            break;
        case 'C':
            s[1] += value;
            break;
        case 'F':
            s[1] -= value;
            break;
        case 'J':
            s[2] += value;
            break;
        case 'M':
            s[2] -= value;
            break;
        case 'A':
            s[3] += value;
            break;
        case 'N':
            s[3] -= value;
            break;
    }
}

string solution(vector<string> survey, vector<int> choices) 
{
    string answer = "";
    int s[4] = {0}; //RT CF JM AN
    
    for(int i = 0; i < survey.size(); i++)
    {
        selectSurvey(s, survey[i][0], choices[i] - 4);
    }
    
    if(s[0] <= 0) answer += 'R'; else answer += 'T';
    if(s[1] <= 0) answer += 'C'; else answer += 'F';
    if(s[2] <= 0) answer += 'J'; else answer += 'M';
    if(s[3] <= 0) answer += 'A'; else answer += 'N';
    
    return answer;
}