#include <string>
#include <vector>

using namespace std;


//count 가 5개가 되면 + for문으로 ans 모두가 0이 되어야 한다
int bf(vector<vector<int>> & v, int n, vector<int> ans, int count, int last_code)
{
    int sum = 0;
    
    //그냥 여기서 for문으로 ans 판별 해야할듯
    for(int i = 0; i < v[last_code].size(); i++)
    {
        ans[v[last_code][i]]--;
        
        //음수가 된다? 존재할 수 없는 코드
        if(ans[v[last_code][i]] < 0)
        {
            return 0;
        }
    }
    
    if(count == 5)
    {
        //for문으로 ans 탐색
        for(int i = 0; i < ans.size(); i++)
        {
            if(ans[i] != 0)
                return 0;
        }
        return 1;
    }
    
    
    //for문 스타트는 last_code + 1
    for(int i = last_code + 1; i <= n; i++)
    {
        sum += bf(v, n, ans, count + 1, i);
    }
    
    return sum;
}

//bf 1 ~ n
int solution(int n, vector<vector<int>> q, vector<int> ans) 
{
    vector<vector<int>> v = vector<vector<int>>(n + 1); //0은 포기
    //입력
    for(int i = 0; i < q.size(); i++)
    {
        for(int j = 0; j < q[i].size(); j++)
        {
            v[q[i][j]].push_back(i);
        }
    }
    
    return bf(v, n, ans, 0, 0); //debug
}