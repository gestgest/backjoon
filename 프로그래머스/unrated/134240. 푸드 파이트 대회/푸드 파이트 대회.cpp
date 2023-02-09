#include <string>
#include <vector>

using namespace std;

string solution(vector<int> food) {
    string copy_s = "";
    string answer = "";
    
    for(int i = 1; i < food.size(); i++)
    {
        for(int j = 0; j < food[i] / 2; j++)
        {
            copy_s += i + '0';
            answer += i + '0';
        }
    }
    answer += '0';
    
    for(int i = copy_s.size() - 1; 0 <= i; i--)
    {
        answer += copy_s[i];
    }
    return answer;
}