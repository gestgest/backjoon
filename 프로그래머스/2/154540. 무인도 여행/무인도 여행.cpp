#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Point {
public:
    int x;
    int y;
    Point() {}
    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
    //
    Point operator +(const Point & point) const &
    {
        Point result;
        result.x = this->x + point.x;
        result.y = this->y + point.y;
        
        return result;
    }
};

//상하좌우
Point dir[4] = {
    Point(1,0), Point(-1,0), Point(0, 1), Point(0, -1)
};

bool isRange(vector<vector<bool>>& visited, Point & point)
{
    if(point.x < 0 || point.y < 0)
        return false;
    if(visited[0].size() <= point.x || visited.size() <= point.y)
        return false;
    return true;
}
//
int addUnion(vector<string>& maps, 
            vector<vector<bool>>& visited,
            Point & start)
{
    int result = 0;
    visited[start.y][start.x] = true;
    result = maps[start.y][start.x] - '0';
    
    //dfs
    for(int i = 0; i < 4; i++)
    {
        Point point = start + dir[i];
        if(!isRange(visited, point))
        {
            continue;
        }
        
        //방문하지 않았다면
        if(!visited[point.y][point.x])
        {
            result += addUnion(maps, visited, point);
        }
    }
    return result;
}

//X 또는 1 9 => 식량
vector<int> solution(vector<string> maps) 
{
    vector<int> answer;
    vector<vector<bool>> visited = vector<vector<bool>>(maps.size());
    
    //
    for(int i = 0; i < visited.size(); i++)
    {
        visited[i] = vector<bool>(maps[i].size());
        for(int j = 0; j < visited[i].size(); j++)
        {
            if(maps[i][j] == 'X')
                visited[i][j] = true;
            else
                visited[i][j] = false;
        }
    }
    
    for(int i = 0; i < visited.size(); i++)
    {
        for(int j = 0; j < visited[i].size(); j++)
        {
            if(!visited[i][j])
            {
                Point point(j, i);
                answer.push_back(addUnion(maps, visited, point));
            }
        }
    }
    
    sort(answer.begin(), answer.end());
    
    if(answer.empty())
    {
        answer.push_back(-1);
    }
    
    return answer;
}