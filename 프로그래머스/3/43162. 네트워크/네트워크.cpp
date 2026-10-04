#include <string>
#include <vector>
#include <iostream>

using namespace std;

void debugArray1(vector<bool> & array)
{
    //array.size()
    for(int i = 0; i < 1; i++)
    {
        cout << array[i] << ' ';
    }
    cout << '\n';
    
}

// 유니온이지만 dfs로도 쉽게 가능
bool dfs(vector<bool> & visited, vector<vector<int>> & graph, int start)
{
    if(visited[start])
    {
        return false;
    }
    visited[start] = true;
    
    for(int i = 0; i < graph[start].size(); i++)
    {
        //graph[start][i]
        dfs(visited, graph, graph[start][i]);
    }
    
    return true;
}


int solution(int n, vector<vector<int>> computers) 
{
    int answer = 0;
    vector<bool> visited = vector<bool>(n, false);
    vector<vector<int>> graph = vector<vector<int>>(n);
    
    for(int i = 0; i < computers.size(); i++)
    {
        for(int j = 0; j < computers[i].size(); j++)
        {
            // 이어져 있다면
            if(computers[i][j] && (i != j))
            {
                graph[i].push_back(j);
            }
        }
    }
    
    //debugArray(graph);
    
    for(int i = 0; i < visited.size(); i++)
    {
        if(dfs(visited, graph, i))
        {
            answer++;
        }
    }
        
    return answer;
}