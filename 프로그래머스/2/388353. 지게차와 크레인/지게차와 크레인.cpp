#include <string>
#include <vector>

using namespace std;

//x, y
int dir[4][2] = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};

bool isInArea(int y, int x, int max_y, int max_x)
{
    if(y >= max_y || x >= max_x)
    {
        return false;
    }
    if(y < 0|| x < 0)
    {
        return false;
    }
    return true;
}

void dfsAlpha(vector<vector<int>>& graph, int start_y, int start_x, int alpha)
{
    graph[start_y][start_x] = -2; //나중에 없앨거
    
    for(int i  = 0; i < 4; i++)
    {
        int y = start_y + dir[i][0];
        int x = start_x + dir[i][1];
        if(!isInArea(y, x, graph.size(), graph[0].size()))
        {
            continue;
        }
        if(graph[y][x] == alpha)
        {
            graph[y][x] = -2; //나중에 없앨거 => 못 들어가는 음수
        }
        else if(graph[y][x] == -1) //지나갈 수 있는 음수
        {
            dfsAlpha(graph,y,x,alpha);
        }
    }
    
}

void allAlpha(vector<vector<int>>& graph, int alpha)
{
    for(int i = 0; i < graph.size(); i++)
    {
        for(int j = 0; j < graph[i].size(); j++)
        {
            if(graph[i][j] == alpha)
            {
                graph[i][j] = -1;
            }
        }
    }
}

void allTransform(vector<vector<int>>& graph)
{
    for(int i = 0; i < graph.size(); i++)
    {
        for(int j = 0; j < graph[i].size(); j++)
        {
            if(graph[i][j] == -2)
            {
                graph[i][j] = -1;
            }
        }
    }
}
    
int getCount(vector<vector<int>>& graph)
{
    int answer = 0;
    for(int i = 0; i < graph.size(); i++)
    {
        for(int j = 0; j < graph[i].size(); j++)
        {
            if(graph[i][j] >= 0)
            {
                answer++;
            }
        }
    }
    return answer;
}

int solution(vector<string> storage, vector<string> requests) 
{
    int answer = 0;
    
    //가장자리를 0으로 채움
    vector<vector<int>> graph = vector<vector<int>>(storage.size() + 2);
    
    for(int i = 0; i < storage.size() + 2; i++)
    {
        graph[i] = vector<int>(storage[0].size() + 2);
        //가장자리 -1 만들기
        if(i == 0 || storage.size() + 1 == i)
        {
            for(int j = 0; j < storage[0].size() + 2; j++)
            {
                graph[i][j] = -1;
            }
        }
        else
        {
            graph[i][0] = -1; //1 ~ storage.size()
            for(int j = 1; j < storage[0].size() + 1; j++)
            {
                graph[i][j] = storage[i - 1][j - 1] - 'A';
                
            }
            graph[i][storage[0].size() + 1] = -1; //1 ~ storage.size() => 하나씩 +1 한거임
        }
    }
    
    
    for(int i = 0; i < requests.size(); i++)
    {
        if(requests[i].size() == 1)
        {
            int a = requests[i][0] -'A';
            //스타트는 0, 0
            dfsAlpha(graph,0, 0, a);
            allTransform(graph);
        }
        else //2번
        {
            int a = requests[i][0] -'A';
            allAlpha(graph, a);
        }
    }
    //마무리에 answer 출력
    answer = getCount(graph);
    return answer;
}

//반례 : 크레인 ㅁ A A 남은 경우 AA 둘다 없어지면 안된다.