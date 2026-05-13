#include <string>
#include <vector>

using namespace std;


int gcd (int a, int b)
{
    if(b == 0)
    {
        return a;
    }
    return gcd(b, a % b); //16 12 => 12 4 => 4 0=>
}

int lcm(int a, int b)
{
    int p = gcd(a,b);
    a /= p;
    b /= p;
    return a * b * p;
}


//오른쪽 끝발 기준
//초 노 빨 => 노란불이 되야함
//최대 5개의 신호등
int solution(vector<vector<int>> signals) 
{
    int max_value = 1;
    
    //바로 나오는 경우 [start + 노란 + dis]
    for(int i = 0; i < signals.size(); i++)
    {
        max_value = lcm(max_value, signals[i][0] + signals[i][1] + signals[i][2]);
    }
    //만약 무한반복이 된다면
    
    //time을 반복
    for(int i = 1; i <= max_value; i++)
    {
        bool isCheck = true;
        for(int j = 0; j < signals.size(); j++)
        {
            int time = (i - 1) % (signals[j][0] + signals[j][1] + signals[j][2]) + 1;
            
            //false면 바로 다음 단계
            if(!(signals[j][0] < time && time <= signals[j][0] + signals[j][1]))
            {
                isCheck = false;
                break;
            }
            
        }
        if(isCheck) //answer
        {
            return i;
        }
    }
    
    
    return -1;
}

//9 11=> 99정도에 
//12 16 => 최소공배수 = 최대공약수 * a의 나머지 * b의 나머지