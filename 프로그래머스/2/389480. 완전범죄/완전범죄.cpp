#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//r <= 40, c = 2
int solution(vector<vector<int>> info, int n, int m) 
{
    int answer = 0;

    int dp[41][121] = {0}; //A흔적 //r*m
    //x가 B흔적

    //y : r
    for (int i = 1; i <= info.size(); i++)
    {
        //B
        int num = info[i - 1][1];
        
        //불가피하게 A로만 채워진 경우
        for (int j = 0; j <= num; j++)
        {
            //A의 값과 기존 값를 더함
            dp[i][j] = dp[i - 1][j] + info[i - 1][0];
        }
        //만약 (3,1) (2,1)가 들어온 경우 [1]에 2를 넣어야 함
        //B의 영역, 기존 거 덮어쓰기
        for(int j = num + 1; j <= m; j++)
        {
            dp[i][j] = min(dp[i - 1][j - num], info[i - 1][0] + dp[i - 1][j]);
        }
    }
    
    //m을 넘어서지마라
    answer = dp[info.size()][m];
    if(answer >= n)
    {
        answer = -1;
    }

    return answer;

}