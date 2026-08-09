#include <string>
#include <vector>

using namespace std;

long long doSeesaw(int * s, int weight)
{
    long long result = 0;
    
    //같다면 => C2
    result += (long long)s[weight] * (s[weight] - 1) / 2;
    
    //내 몸무게
    for(int i = 2; i <= 4; i++)
    {
        for(int j = 2; j <= i; j++)
        {
            if(i == j)
                continue;
            if(weight * i % j != 0)
                continue;
            if(1000 < weight * i / j)
                continue;
            
            //6개 * 7개
            result += (long long)s[weight * i / j] * s[weight];
        }
    }
    return result;
}

long long solution(vector<int> weights) {
    long long answer = 0;
    int s[1001] = {0};
    
    //배열에 넣는다.
    for(int i = 0; i < weights.size(); i++)
    {
        s[weights[i]]++;
    }
    
    //이후 
    for(int i = 100; i <= 1000; i++)
    {
        answer += doSeesaw(s, i);
    }
    return answer;
}