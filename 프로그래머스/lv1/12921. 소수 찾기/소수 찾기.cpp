#include <string>
#include <vector>
#include <cmath>

using namespace std;

//맞으면 1 틀리면 0
bool isPrime(int n)
{
    for(int i = 2; i <= sqrt(n); i++)
    {
        if(n % i == 0)
        {
            //소수가 아님
            return false;
        }
    }
    return true;
}

int solution(int n) {
    int answer = 0;
    int p = 1;
    bool *s = new bool [n + 1]; //0~n-1 => 1 ~ n
    for(int i = 0; i < n + 1; i++)
    {
        s[i] = false;
    }
        
    for(int i = 2; i <= n; i+=p)
    {
        if(s[i]) {
            continue;
        }
        if(isPrime(i))
        {
            answer++;
            for(int j = i; j < n + 1 ;j += i)
            {
                s[j] = true;
            }
        }
    }
    return answer;
}