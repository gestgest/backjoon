#include <string>
#include <vector>

using namespace std;

class Point
{
public:
    int x, y;
    Point() {}
    Point(int y, int x)
    {
        this->x = x;
        this->y = y;
    }
};

class Robot
{
public:
    Point point;
    int end_index = 0;
    vector<Point> points;
    Robot(int y, int x, vector<Point> & points)
    {
        point.x = x;
        point.y = y;
        this->points = points;
    }
    bool isBoundryIndex()
    {
        if(end_index >= points.size())
        {
            return false;
        }
        return true;
    }
    
    bool addIndex()
    {
        end_index++;
        if(end_index >= points.size())
        {
            end_index = points.size();
            return false;
        }
        return true;
    }
};

int isCheck(vector<vector<int>> & robot_count, int r, int c)
{
    bool isEmpty = true;
    int count = 0;
    for(int i = 1; i <= r; i++)
    {
        for(int j = 1; j <= c; j++)
        {
            if(robot_count[i][j] >= 2)
            {
                count++;
                isEmpty = false;
            }
            else if(robot_count[i][j] == 1)
            {
                isEmpty = false;
            }
        }
    }
    if(isEmpty)
    {
        return -1; //비어있다는 뜻
    }
    return count;
}

void move(vector<vector<int>> & count, Robot & robot)
{
    if(!robot.isBoundryIndex())
    {
        return;
    }
    count[robot.point.y][robot.point.x]--;
    int dis_y = robot.point.y - robot.points[robot.end_index].y;
    int dis_x = robot.point.x - robot.points[robot.end_index].x;
    
    //도착 한 경우 바로 다음 목적지로 이동
    if(dis_y == 0 && dis_x == 0)
    {
        robot.addIndex();
        
        //목적지에 도착하면 X
        if(!robot.isBoundryIndex())
        {
            return;
        }
        dis_y = robot.point.y - robot.points[robot.end_index].y;
        dis_x = robot.point.x - robot.points[robot.end_index].x;
    }
    
    //down
    if(dis_y > 0)
    {
        robot.point.y--;
    }
    else if(dis_y < 0)
    {
        robot.point.y++;
    }
    else if(dis_x > 0)
    {
        robot.point.x--;
    }
    else if(dis_x < 0)
    {
        robot.point.x++;
    }
    else
    {
        return;
    }
    
    count[robot.point.y][robot.point.x]++;
}

int solution(vector<vector<int>> points, vector<vector<int>> routes) 
{
    int answer = 0;
    vector<Robot> robots;
    vector<vector<int>> robot_count = vector<vector<int>>(101);
    for(int i = 0; i <= 100; i++)
    {
        robot_count[i] = vector<int>(101);
    }
    
    //입력
    for(int i = 0; i < routes.size(); i++)
    {
        int start_index = routes[i][0] - 1;
        vector<Point> vp;
        for(int j = 1; j < routes[i].size(); j++)
        {
            int end_index = routes[i][j] - 1;
            vp.push_back(Point(points[end_index][0], points[end_index][1]));
        }
        
        robots.push_back(Robot(points[start_index][0], points[start_index][1], vp));
        robot_count[robots[i].point.y][robots[i].point.x]++;
    }
    
    while(true)
    {
        int num = isCheck(robot_count, 100, 100);
        if(num == -1)
        {
            break;
        }
        
        answer += num;
        
        //for문으로 경로
        for(int i = 0; i < robots.size(); i++)
        {
            //이동 만약 이동 된 오브젝트가 있다면
            move(robot_count, robots[i]);
        }
    }
    
    
    return answer;
}