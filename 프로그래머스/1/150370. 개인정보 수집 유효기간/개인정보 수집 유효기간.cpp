#include <string>
#include <vector>

using namespace std;

int transformDay(string date)
{
    int result = 0;
    int year = 0, month = 0, day = 0;
    for(int i = 0; i < 4; i++)
    {
        year *= 10;
        year += date[i] - '0';
    }
    result = (year - 2000) * 12 * 28;

    //5시작
    for(int i = 5; i < 7; i++)
    {
        month *= 10;
        month += date[i] - '0';
    }
    month = (month - 1) * 28;
    result += month;

    for(int i = 8; i < 10; i++)
    {
        day *= 10;
        day += date[i] - '0';
    }
    
    result += day - 1;
    return result;
}

void transformTerm(vector<int> &terms, string & term)
{
    int sum = 0;
    int index = term[0] - 'A';
    
    for(int i = 2; i < term.size(); i++)
    {
        sum *= 10;
        sum += term[i] - '0';
    }
    terms[index] = sum * 28;
}

//terms는 대문자만 가능
vector<int> solution(string today_str, vector<string> terms_str, vector<string> privacies) 
{
    vector<int> answer;
    int today = transformDay(today_str);
    vector<int> terms = vector<int>(26);

    for(int i = 0; i < terms_str.size(); i++)
    {
        transformTerm(terms, terms_str[i]);
    }
    
    for(int i = 0; i < privacies.size(); i++)
    {
        int tmp = transformDay(privacies[i]);
        int term_index = privacies[i][11] - 'A';
        
        if(tmp + terms[term_index] <= today)
        {
            //answer.push_back(tmp.getDay());
            answer.push_back(i + 1);
        }
    }
    
    
    return answer;
}