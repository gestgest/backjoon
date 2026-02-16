#include <string>
#include <vector>

using namespace std;

int solution(int number, int limit, int power) 
{
    int answer = 0;
    vector<int> v = vector<int>(number, 0);
    
    //
    for(int i = 1; i <= number; i++)
    {
        for(int j = i; j <= number; j += i) 
        {
            v[j - 1]++;
        }
    }
    
    for(int i = 0; i < number; i++)
    {
        if(v[i] <= limit)
        {
            answer += v[i];
        }
        else
        {
            answer += power;
        }
    }
    return answer;
}