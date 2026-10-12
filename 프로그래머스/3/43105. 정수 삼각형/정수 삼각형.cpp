#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) 
{
    int answer = 0;
    vector<vector<int>> t = vector<vector<int>>(triangle.size());
    for(int i = 0; i < triangle.size(); i++)
    {
        t[i] = vector<int>(triangle[i].size(), 0);
    }
    t[0][0] = triangle[0][0]; // 시작점
    
    for(int i = 1; i < triangle.size(); i++)
    {
        int size = triangle[i].size();
        
        // 처음
        t[i][0] = t[i - 1][0] + triangle[i][0];
        
        // 중간
        for(int j = 1; j < size - 1; j++)
        {
            t[i][j]= max(t[i - 1][j - 1], t[i - 1][j]) + triangle[i][j];
        }
        // 끝
        t[i][size - 1] = t[i - 1][size - 2] + triangle[i][size - 1];
    }
    for(int i = 0; i < t[t.size() - 1].size(); i++)
    {
        answer = max(answer, t[t.size() - 1][i]);
    }
    
    return answer;
}