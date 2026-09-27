#include <string>
#include <vector>
#include <queue>

using namespace std;

// 병사, 무적권, 적 갯수 배열
int solution(int n, int k, vector<int> enemy) 
{
    int answer = 0;
    priority_queue<int, vector<int>, less<int>> enemy_queue;
    
    // 라운드
    for(int i = 0; i < enemy.size(); i++)
    {
        // 적이 너무 많음
        if(n < enemy[i])
        {
            //만약 무적이 없다면
            if(k <= 0)
            {
                return answer;
            }
            
            // 모자라면 우선순위 큐에서 꺼내기
            n -= enemy[i];
            k--;
            enemy_queue.push(enemy[i]);
            
            // 비어있다면 => 이제 넣을 그게 없음.
            int e = enemy_queue.top();
            enemy_queue.pop();
            
            n += e;
        }
        else
        {
            n -= enemy[i];
            enemy_queue.push(enemy[i]);
        }
        answer++;
    }
    
    return answer;
}