#include <string>
#include <vector>
#include <queue>


using namespace std;

class Point{
public:
    int x;
    int y;
    Point () {}
    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
    Point operator + (Point & point)
    {
        Point result;
        result.x = this->x + point.x;
        result.y = this->y + point.y;
        return result;
    }
};

Point dir[4] = {Point(1,0),Point(-1,0),Point(0,1),Point(0,-1)};

bool isRange(vector<vector<int>> dp, Point & p)
{
    if(p.x < 0 || p.y < 0)
        return false;
    if(dp.size() <= p.y || dp[0].size() <= p.x)
        return false;
    return true;
}



int bfs(vector<string> & maps, Point & start, Point & dst)
{
    queue<Point> q;
    vector<vector<int>> dp = vector<vector<int>>(maps.size()); //-1
    
    for(int i = 0; i < maps.size(); i++)
    {
        dp[i] = vector<int>(maps[i].size(), -1);
    }
    
    dp[start.y][start.x] = 0;
    q.push(start);
    
    while(!q.empty())
    {
        Point p = q.front();
        q.pop();
        
        if(p.y == dst.y && p.x == dst.x)
        {
            return dp[p.y][p.x];
        }
        
        for(int i = 0; i < 4; i++)
        {
            Point future_point = p + dir[i];
            //범위 검사
            if(!isRange(dp, future_point))
                continue;
            
            //bfs니까 뭐 값 <= dp은 안해도되겠지?
            //벽 검사 + dp가 -1인지
            if(maps[future_point.y][future_point.x] == 'X' 
               || dp[future_point.y][future_point.x] != -1)
            {
                continue;
            }
            
            //그재서야 p값에 +1를 하고
            dp[future_point.y][future_point.x] = dp[p.y][p.x] + 1;
            q.push(future_point);
        }
    }
    return -1;
}

//레버 당기고 출구
int solution(vector<string> maps) 
{
    int answer = 0;
    Point start;
    Point lever;
    Point end;
    
    //maps 탐색
    for(int i = 0; i < maps.size(); i++)
    {
        for(int j = 0; j < maps[i].size(); j++)
        {
            if(maps[i][j] == 'S')
            {
                start = Point(j, i);
            }
            else if(maps[i][j] == 'L')
            {
                lever = Point(j, i);
            }
            else if(maps[i][j] == 'E')
            {
                end = Point(j, i);
            }
        }
    }
    //일단 레버까지 가는 길
    answer = bfs(maps, start, lever);
    if(answer == -1)
    {
        return answer;
    }
    //레버에서 exit까지 가는 길
    int dis = bfs(maps, lever, end);
    if(dis == -1)
        return dis;
    answer += dis;
    return answer;
}