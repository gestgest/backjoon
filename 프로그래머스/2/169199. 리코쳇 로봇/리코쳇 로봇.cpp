#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

class Point{
public:
    int x;
    int y;
    int value = 0;
    Point(){}
    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
    
    Point operator+(Point & point)
    {
        Point result;
        result.x = this->x + point.x;
        result.y = this->y + point.y;
        return result;
    }
};

Point moveDir(vector<vector<int>> & board, Point start, Point dir)
{
    Point point;
    while(true)
    {
        point = start + dir;
        //범위에 벗어나려고 하는 경우
        if(point.x < 0 || point.y < 0)
        {
            return start;
        }
        if(board.size() <= point.y || board[0].size() <= point.x)
        {
            return start;
        }
        if(board[point.y][point.x] == -2) //벽
        {
            return start;
        }
        start = point;
    }
}
void debugPrint(vector<vector<int>> & s)
{
    cout << "스타토\n";
    
    for(int i = 0; i < s.size(); i++)
    {
        for(int j = 0; j < s[i].size(); j++)
        {
            if(s[i][j] == -1)
                cout << 0 << ' ';
            else if(s[i][j] == -2)
                cout << 'D' << ' ';
            else
                cout << s[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << "엔도\n\n";
}

//bfs
void bfs(vector<vector<int>> & board, Point & start)
{
    vector<Point> dir; //서 동 남 북
    dir.push_back(Point(-1, 0));
    dir.push_back(Point(1, 0));
    dir.push_back(Point(0, 1));
    dir.push_back(Point(0,-1));
    
    queue<Point> point_queue;
    start.value = 0;
    board[start.y][start.x] = 0;
    
    point_queue.push(start);
    
    while(!point_queue.empty())
    {
        Point point = point_queue.front();
        point_queue.pop();
        
        //분명 여기서 
        //cout << point.x << ", " << point.y << ", "<< point.value << '\n';
        
        for(int i = 0; i < dir.size(); i++)
        {
            Point p = moveDir(board, point, dir[i]);
            //cout << p.x << ", " << p.y << ", "<< point.value + 1 << '\n';
            //한번도 방문 하지 않았다면. 당연히 벽은 제외
            if(board[p.y][p.x] == -1 || point.value + 1 < board[p.y][p.x])
            {
                p.value = point.value + 1;
                
                //세팅은 여기서
                board[p.y][p.x] = p.value;
                point_queue.push(p);
            }
        }
    }
    
}

//도착한 위치에 다시 도착하면 return 


int solution(vector<string> board) 
{
    int answer = 0;
    vector<vector<int>> s = vector<vector<int>>(board.size());
    Point start;
    Point end;
    //비어있으면 -1
    //벽이라면? -2
    
    
    for(int i = 0; i < board.size(); i++)
    {
        s[i] = vector<int>(board[i].size());
        for(int j = 0; j < board[i].size(); j++)
        {
            if(board[i][j] == 'D') //벽
            {
                s[i][j] = -2;
                continue;
            }
            else if(board[i][j] == 'G') //도착
            {
                end.y = i;
                end.x = j;
            }
            else if(board[i][j] == 'R')//(R) start
            {
                start.y = i;
                start.x = j;
            }
            s[i][j] = -1;      //빈곳 .
            
        }
    }
    bfs(s, start);
    //debugPrint(s);
    answer = s[end.y][end.x];
    
    return answer;
}