#include <string>
#include <vector>

using namespace std;

int solution(vector<int> topping) 
{
    // 토핑 종류 갯수를 공평하게 자를 수 있는 경우의 수
    int answer = 0;
    int t[2][10000] = {0};
    int type[2] = {0};
    
    // 오른쪽에 전부 넣고
    for(int i = 0; i < topping.size(); i++)
    {
        int index = topping[i] - 1;
        
        // 비어있다면
        if(t[1][index] == 0)
        {
            type[1]++;
        }
        t[1][index]++;
    }
    
    // 하나씩 빼기
    for(int i = 0; i < topping.size(); i++)
    {
        int index = topping[i] - 1;
        
        // 비어있다면
        if(t[0][index] == 0)
        {
            type[0]++;
        }
        if(t[1][index] == 1)
        {
            type[1]--;
        }
        t[0][index]++;
        t[1][index]--;
        
        if(type[0] == type[1])
        {
            answer++;
        }
    }
    
    return answer;
}