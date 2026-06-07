#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

//현재 층의 분배노드, 사용된 분배노드
long long dfs(long long current_dist, long long used_dist, long long split,
              const int dist_limit, const int split_limit)
{
    long long answer = current_dist;  
    
    for (int i = 2; i <= 3; i++)
    {
        if (split * i > split_limit) continue;

        long long child_dist = current_dist * i; //그냥 여기 기준 자식
        long long has_child_dist = min(child_dist, (long long)dist_limit - used_dist); //분배노드
        
        long long count = (child_dist - has_child_dist)  //(3 반례) 중간 단말노드
            + dfs(has_child_dist, used_dist + has_child_dist, split * i, dist_limit, split_limit);
        answer = max(answer, count);
    }
    return answer;
}

int solution(int dist_limit, int split_limit)
{
    if (dist_limit == 0) return 1;
    return (int)dfs(1, 1, 1, dist_limit, split_limit);
}