#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n, long long left, long long right) 
{
    // n = 5, left 7, right 16
    // n = 3, 2 5 => 1 4,
    const long long const_left = left;
    vector<int> answer = vector<int>(right - left + 1); 
    
    // 일단 left가 몇 행인가?
    for(; left <= right; left++)
    {
        long long r = left / n; // 1 => [1]
        long long c = left % n; // 1 => [1][1]
        answer[left - const_left] = max(r,c) + 1;
        //answer.push_back(max(r,c) + 1);
    }
    
    
    return answer;
}