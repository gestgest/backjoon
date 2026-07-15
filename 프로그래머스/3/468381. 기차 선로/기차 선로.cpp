
#include <string>
#include <vector>
#include <iostream>

using namespace std;

#define LEFT 0
#define UP 1
#define RIGHT 2
#define DOWN 3

class Point {
public:
    int x;
    int y;
    Point () {}
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

//summary : 북을 0,1로 설정함
Point direction[4] = {Point(-1,0), Point(0,-1), Point(1, 0), Point(0, 1)};

//!
int able[4][4] = 
{
    //출발지
    {1, 3, 4, 7},  //left
    {2, 3, 4, 5},  //up
    {1, 3, 5, 6},  //right
    {2, 3, 6, 7},  //down
};

//y x 
bool isRange(int row, int col, Point & p)
{
    if(p.x < 0 || p.y < 0)
        return false;
    if(p.y >= row || p.x >= col)
        return false;
    return true;
}

vector<int> roadToDir(int road, int before_dir)
{
    vector<int> result;
    switch (road) {
        case 1: //0 => 2 2 => 0
        case 2:
        case 3:
            before_dir += 2;
            before_dir %= 4;
            result.push_back(before_dir);
            break;
        case 4: //0 1 1 0
            if(before_dir == LEFT) result.push_back(UP); 
            else result.push_back(LEFT); 
            break;
        case 5: //1 2 2 1
            if(before_dir == UP) result.push_back(RIGHT); 
            else result.push_back(UP); 
            break;
        case 6: //2 3 3 2
            if(before_dir == RIGHT) result.push_back(DOWN); 
            else result.push_back(RIGHT); 
            break;
        case 7: //3 0 0 3
            if(before_dir == DOWN) result.push_back(LEFT); 
            else result.push_back(DOWN); 
            break;
    }
    return result;
}

void debugPrint(vector<vector<int>> & grid)
{
    cout << "-----------시작합니다.\n";
    
    for(int i = 0; i < grid.size(); i++)
    {
        for(int j = 0; j < grid[i].size(); j++)
        {
            cout << grid[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << "-----------끝.\n";
}

bool isRightRoad(int road, int direction)
{
    switch(road) {
        case 1:
            return direction == LEFT || direction == RIGHT;
            break;
        case 2:
            return direction == UP || direction == DOWN;
            break;
        case 3: //어디로든 가능
            return true;
            break;
        case 4:
            return direction == LEFT || direction == UP;
            break;
        case 5:
            return direction == RIGHT || direction == UP;
            break;
        case 6:
            return direction == RIGHT || direction == DOWN;
            break;
        case 7:
            return direction == LEFT || direction == DOWN;
            break;
        return false;
    }
}

bool checkRoad(vector<vector<int>> & grid, vector<vector<int>> & visited)
{
    for(int i = 0; i < grid.size(); i++)
    {
        for(int j = 0; j < grid[i].size(); j++)
        {
            if(grid[i][j] <= 0) //벽, 빈거
            {
                continue;
            }
            if(grid[i][j] == 3 && visited[i][j] <= 1)
            {
                return false;
            }
            //선로에 방문하지 않았다면
            if(visited[i][j] <= 0)
            {
                return false;
            }
        }
    }
    return true;
}

//모든 grid가 -1와 0을 제외한 길은 1이어야 하지만 3은 2어야 한다.
//dfs
int dfs(vector<vector<int>> & grid, vector<vector<int>> & visited, Point & point, int dir)
{
    int result = 0;
    
    //범위에 맞는지
    if(!isRange(grid.size(), grid[0].size(), point))
        return 0;
    
    
    //-1이면 컷 => 벽
    if(grid[point.y][point.x] == -1)
        return 0;
    
    //방문했다면
    //visited가 1이면 컷. 단 grid로 3인 경우는 2컷
    if((visited[point.y][point.x] == 1 && grid[point.y][point.x] != 3) 
       || (visited[point.y][point.x] == 2 && grid[point.y][point.x] == 3))
    {
        return 0;
    }
    visited[point.y][point.x]++;
    //dir은 LEFT
    
    //cout << point.x << ' ' << point.y << '\n';
    //debugPrint(grid);
    
    //대충 여기서 설치
    if(grid[point.y][point.x] == 0)
    {
        for(int i = 0; i < 4; i++)
        {
            //right로 하면 이제 뭐 able에서 뽑음
            grid[point.y][point.x] = able[dir][i];
            
            //debugPrint(grid);
            //그 선로라면 어디로 가야할까
            vector<int> dirs = roadToDir(grid[point.y][point.x], dir); 
            for(int j = 0; j < dirs.size(); j++)
            {
                Point p = point + direction[dirs[j]];
                
                //근데 리버스 dirs로 해야할듯
                //방향은 순수 dirs
                result += dfs(grid, visited, p, (dirs[j] + 2) % 4);
            }
            
            grid[point.y][point.x] = 0; //다시 초기화
        }

    }
    else //선로가 있음
    {
        //summary : 그럼 여기서 검사를 해야하나.
        if(!isRightRoad(grid[point.y][point.x], dir))
        {
            visited[point.y][point.x]--;
            return 0;
        }
        
        //모든 선로에서 visited가 0또는 grid3 0,1 찾기
        //있으면 0
        //없으면 1
        if(grid.size() - 1 == point.y && grid[0].size() - 1 == point.x)
        {
            if(checkRoad(grid,visited))
            {
                visited[point.y][point.x]--;
                return 1;
            }
            
            visited[point.y][point.x]--;
            return 0;
        }
        
        vector<int> dirs = roadToDir(grid[point.y][point.x], dir); 
        for(int j = 0; j < dirs.size(); j++)
        {
            Point p = point + direction[dirs[j]];
            
            //근데 리버스 dirs로 해야할듯
            //방향은 순수 dirs
            result += dfs(grid, visited, p, (dirs[j] + 2) % 4);
        }
        //debugPrint(grid);
    }
    
    visited[point.y][point.x]--;
    return result;
}

int solution(vector<vector<int>> grid) 
{
    int answer = 0;
    vector<vector<int>> visited = vector<vector<int>>(grid.size());
    
    for(int i = 0; i < visited.size(); i++)
    {
        visited[i] = vector<int>(grid[i].size(), 0);
    }
    Point point(1,0);
    // if(visited.size() >= 4)
    //     return 644;
    // if(visited[0].size() >= 4)
    //     return 644;
    
    //summary : 이거 빼먹음
    visited[0][0] = 1;
    answer = dfs(grid, visited, point, LEFT);
    
    return answer;
}