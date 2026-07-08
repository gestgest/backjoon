#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
#define INF 2147483647

//만약 지나가다가 공이 맞을 거 같으면 X
//왼쪽기준
int horizontalCal(int start_x, int start_y, int x, int y, int max_x, bool isLeft)
{
    int newx;
    int newy = start_y - y;
    if(isLeft)
        newx = start_x + x;
    else
        newx = 2 * max_x - x - start_x;
    
    
    //isleft인데 x가 start_x보다 왼쪽에 있는 경우
    //isleft가 아닌데 x가 start_x보다 오른쪽에 있는 경우
    if(newy == 0) //공에 바로 닿으니까
    {
        if(isLeft && start_x > x)
            return INF;
        if(!isLeft && start_x < x)
            return INF;
    }
    
    return newx * newx + newy * newy;
}

int verticalCal(int start_x, int start_y, int x, int y, int max_y, bool isUp)
{
    int newy;
    int newx = start_x - x;
    if(isUp)
        newy = start_y + y;
    else
        newy = 2 * max_y - y - start_y;
    
    
    if(newx == 0) //공에 바로 닿으니까
    {
        if(isUp && start_y > y)
            return INF;
        if(!isUp && start_y < y)
            return INF;
    }
    
    return newx * newx + newy * newy;
}

//m x n
//맞춰야하는 볼 리스트 : ball. 볼 갯수 천개
vector<int> solution(int m, int n, int startX, int startY, vector<vector<int>> balls) 
{
    vector<int> answer;
    
    for(int i = 0; i < balls.size(); i++)
    {
        int value = INF;
        
        //4벽을 기준 => bf느낌으로 2쿠션 3쿠션 생각해야할듯
        value = min(value, horizontalCal(startX, startY, balls[i][0], balls[i][1], m, true));
        value = min(value, horizontalCal(startX, startY, balls[i][0], balls[i][1], m, false));
        value = min(value, verticalCal(startX, startY, balls[i][0], balls[i][1], n, true));
        value = min(value, verticalCal(startX, startY, balls[i][0], balls[i][1], n, false));
        answer.push_back(value);
    }
    
    return answer;
}