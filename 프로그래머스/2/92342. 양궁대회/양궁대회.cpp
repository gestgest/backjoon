#include <string>
#include <vector>

using namespace std;

vector<int> app_info(11, 0);
vector<int> best;
int bestDiff = 0;

bool better(vector<int> & a, vector<int> & b)
{
    for(int i = 10; i >= 0; i--)
    {
        if(a[i] != b[i]) return a[i] > b[i];
    }
    return false;
}

void dfs(int index, int arrow, vector<int> & info)
{
    if(index == 10)
    {
        app_info[10] = arrow;
        int lion = 0, app = 0;
        for(int i = 0; i < 11; i++)
        {
            // 화살이 없는 경우
            if(info[i] == app_info[i] && info[i] == 0)
                continue;
            if(info[i] >= app_info[i])
                lion += 10 - i;
            else
                app += 10 - i;
        }
        int diff = app - lion;
        if(diff > 0)
        {
            if(diff > bestDiff || (diff == bestDiff && better(app_info, best)))
            {
                bestDiff = diff;
                best = app_info;
            }
        }
        
        app_info[10] = 0;
        return;
    }
    
    if(arrow - info[index] - 1 >= 0)
    {
        app_info[index] = info[index] + 1;
        dfs(index + 1, arrow - info[index] - 1, info);
        app_info[index] = 0;
    }
    dfs(index + 1, arrow, info);
}
vector<int> solution(int n, vector<int> info) 
{
    dfs(0, n, info);
    if(best.size() == 0)
    {
        best.push_back(-1);
    }
    return best;
}