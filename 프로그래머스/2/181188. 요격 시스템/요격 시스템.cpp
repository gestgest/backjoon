#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Missile{
public:
    int start;
    int end;
    Missile(int start, int end)
    {
        this->start = start;
        this->end = end;
    }
    
    bool operator < (Missile & missile) const
    {
        if(start < missile.start)
        {
            return true; //true일수록 맨 앞에
        }
        if(start > missile.start)
        {
            return false;
        }
        if(end < missile.end) 
        {
            return true;
        }
        return false;
    }
};

//10 ~ 20일때 10, 20에서 쏘면 빗 맞는다
//(10^8, 10^8)
int solution(vector<vector<int>> targets)
{
    int answer = 0;
    int end = -1;
    
    //정렬
    vector<Missile> missiles;
    for(int i = 0; i < targets.size(); i++)
    {
        missiles.push_back(Missile(targets[i][0], targets[i][1]));
    }

    //s를 먼저 정렬하고 e는 나중에
    sort(missiles.begin(), missiles.end());
    
    for(int i = 0; i < missiles.size(); i++)
    {
        //교집합 바깥
        if(end <= missiles[i].start)
        {
            end = missiles[i].end;
            answer++;
        }
        else
        {
            //3~7 4~5 5~12 반례. => 자연스럽게 4~5에서 5를 end에 넣어야함
            if(missiles[i].end < end)
            {
                end = missiles[i].end;
            }
        }
    }
    //그러다가 한번 하고 => 교집합 애들 전부 true하고 다시 false된 애를 찾고
    
    //answer = missiles[2].end;
    return answer;
}