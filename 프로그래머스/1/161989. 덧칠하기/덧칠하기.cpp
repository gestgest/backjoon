#include <string>
#include <vector>

using namespace std;

//section는 오름차순
int solution(int n, int m, vector<int> section) 
{
    int answer = 0;
    int paint = 0;
    
    for(int i = 0; i < section.size(); i++)
    {
        if(paint < section[i])
        {
            answer++;
            paint = section[i] + m - 1;
        }
    }
    
    return answer;
}