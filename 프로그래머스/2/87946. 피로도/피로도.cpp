#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

//bf 00000000
int bf(int isCheck, vector<vector<int>> & dungeons, int money)
{
    int sum = 0;
    
    // 순열 아님? 
    // 1, 5, 7
    for(int i = 0; i < dungeons.size(); i++)
    {
        // 1 + 2 + 4
        int bit = 1 << i;
        //cout << isCheck << ", " << i <<'\n'; // 1, 2일때 왜 안될까.
        
        // 방문했다면
        if(bit & isCheck)
        {
            // if(isCheck == 1 && i == 2)
            // {
            //     cout << "엄준식1" << '\n';
            // }
            continue;
        }
        
        // 조건이 없는 경우 => 3 2
        if(money < dungeons[i][0])
        {
            // if(isCheck == 1 && i == 2)
            // {
            //     cout << "엄준식2 : " << money << ", " << dungeons[i][0]  << '\n';
            // }
            continue;
        }
        
        bit |= isCheck;
        sum = max(sum, bf(bit, dungeons, money - dungeons[i][1]) + 1);
    }
    return sum;
}

int solution(int k, vector<vector<int>> dungeons) 
{
    int answer = bf(0, dungeons, k);
    
    return answer;
}