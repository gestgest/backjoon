#include <string>
#include <vector>
#include <queue>

#define INF 2147483247
using namespace std;

bool canAdd(vector<int> & v, int index, int value)
{
    //범위 내.
    if(index >= v.size())
    {
        return false;
    }
    if(v[index] != -1) //이미 다녀간 경우
    {
        return false;
    }
    v[index] = value;
    return true;
}

//bfs
int bfs(int src, int dst, int n)
{
    vector<int> v = vector<int>(dst + 1, -1);
    queue<int> index_queue;
    v[src] = 0;
    index_queue.push(src);
    
    while(!index_queue.empty())
    {
        int index = index_queue.front();
        index_queue.pop();
        
        if(dst == index)
            break;
        
        if(canAdd(v, index + n, v[index] + 1))
            index_queue.push(index + n);
        if(canAdd(v, index * 2, v[index] + 1))
            index_queue.push(index * 2);
        if(canAdd(v, index * 3, v[index] + 1))
            index_queue.push(index * 3);
    }
    return v[dst];
}

int solution(int x, int y, int n) 
{
    return bfs(x,y,n);
}