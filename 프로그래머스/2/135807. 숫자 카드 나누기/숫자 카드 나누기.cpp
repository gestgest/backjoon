#include <string>
#include <vector>
#include <cmath>

using namespace std;

//최대 공약수
int gcd(int a, int b)
{
    if(a == 0)
    {
        return b;
    }
    return gcd(b % a, a);
}

int card(vector<int> & arrayA, vector<int> & arrayB)
{
    int num = arrayA[0];
    // 최대공약수 하고
    for(int i = 1; i < arrayA.size(); i++)
    {
        num = gcd(num, arrayA[i]);
        
        // 겹치는 약수가 아예 없음
        if(num == 1)
        {
            return 0;
        }
    }
    
    for(int i = 0; i < arrayB.size(); i++)
    {
        // 나눠지는게 하나라도 있다면
        if(arrayB[i] % num == 0)
        {
            return 0;
        }
    }
    return num;
}


int solution(vector<int> arrayA, vector<int> arrayB) 
{
    int answer = 0;
    answer = max(card(arrayA, arrayB), card(arrayB, arrayA));
    
    return answer;
}