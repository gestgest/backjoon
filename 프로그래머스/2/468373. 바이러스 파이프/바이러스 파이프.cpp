#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

; //0이면 방문안함 1이면 참조 됨 2이면 왔다감

class Edge{
public:
    int dst;
    int type;
    Edge(int dst, int type)
    {
        this->dst = dst;
        this->type = type;
    }
};

//bfs =>
//dfs
//bfs 했던 값 되돌리기

int bfs(vector<vector<Edge>> & edges, vector<bool> & isVisited, int type)
{
    queue<int> edge_queue;
    int result = 0;
    
    // 이미 방문한 visited애들 전부 queue에 넣자.
    for(int i = 0; i < isVisited.size(); i++) //100번 탐색
    {
        //방문한 애들이면
        if(isVisited[i])
        {
            edge_queue.push(i);
        }
    }
    
    while(!edge_queue.empty())
    {
        int edge_index = edge_queue.front();
        edge_queue.pop();
        
        for(int i = 0; i < edges[edge_index].size(); i++)
        {
            //edge의 dst를 방문안했는지 그리고 타입이 같은지
            if(!isVisited[edges[edge_index][i].dst] && edges[edge_index][i].type == type)
            {
                edge_queue.push(edges[edge_index][i].dst);
                isVisited[edges[edge_index][i].dst] = true;
                result++;
            }
        }
    }
    return result;
}


//bf? (int sum)
int dfs(vector<vector<Edge>> & edges, vector<bool> isVisited, int index, int k, int type)
{
    //bfs
    int result = bfs(edges, isVisited, type); //0이면 무시한다는 뜻
    
    //1번이면 위까지는 계산된다.
    if(index == k)
    {
        return result;
    }
    
    int max_value = 0;
    
    
    //dfs
    for(int i = 1; i <= 3; i++)
    {
        //max값 비교
        max_value = max(max_value, dfs(edges, isVisited, index + 1, k, i));
    }
    //이렇게 되면 자연스럽게 되돌아가짐
    return result + max_value;
}


//1~n 
int solution(int n, int infection, vector<vector<int>> e, int k) 
{
    int answer = 0;
    vector<bool> isVisited = vector<bool>(n, false);
    vector<vector<Edge>> edges = vector<vector<Edge>>(n); 
    
    //edges 변환
    for(int i = 0; i < e.size(); i++)
    {
        edges[e[i][0] - 1].push_back(Edge(e[i][1] - 1, e[i][2]));    //src
        edges[e[i][1] - 1].push_back(Edge(e[i][0] - 1, e[i][2]));    //src
    }
    //isVisited에 infection - 1에다가 1을 넣어야 한다.
    isVisited[infection - 1] = true;
    answer = dfs(edges, isVisited, 0, k, 0);
    answer++;
    
    return answer;
}