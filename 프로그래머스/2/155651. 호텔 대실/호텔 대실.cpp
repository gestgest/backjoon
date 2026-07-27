#include <string>
#include <vector>
#include <queue>

using namespace std;

class Time{
public:
    int start = 0;
    int end = 0;
    int op = 0;
    bool isStart = false;
    Time(string start, string end)
    {
        this->start = (start[0] - '0') * 10 + start[1] - '0';
        this->start *= 60;
        this->start += (start[3] - '0') * 10 + start[4] - '0';
        
        
        this->end = (end[0] - '0') * 10 + end[1] - '0';
        this->end *= 60;
        this->end += (end[3] - '0') * 10 + end[4] - '0';
        this->end += 10; //방청소
        
        op = this->start;
    }
    void onIsStart()
    {
        isStart = true;
        op = this->end;
    }
    
    //오름차순
    bool operator < (const Time & time) const
    {
        if(op > time.op)
        {
            return true;
        }
        //같다면 => 만약 이럴 경우 isStart가 true인 놈을 
        else if(op == time.op)
        {
            if(time.isStart)
            {
                return true;
            }
            if(this->isStart)
            {
                return false;
            }
            return false;
        }
        return false;
    }
};

int solution(vector<vector<string>> book_time) 
{
    int answer = 0;
    int current = 0;
    priority_queue<Time> time_queue;
    for(int i = 0; i < book_time.size(); i++)
    {
        Time t(book_time[i][0], book_time[i][1]);
        time_queue.push(t);
    }
    //시작, 끝을 우선순위 큐?
    while(!time_queue.empty())
    {
        Time t = time_queue.top();
        time_queue.pop();
        
        //방에 넣기
        if(!t.isStart)
        {
            t.onIsStart();
            current++;
            if(current > answer)
            {
                answer = current;
            }
            time_queue.push(t);
        }
        else
        {
            current--;
        }
        
    }
    
    //끝 넣을때 +10도 해야함
    
    return answer;
}