#include <string>
#include <vector>

using namespace std;
#define WEEK_SIZE 7

class TimeData{
public:
    int hour;
    int min;
    TimeData(int time)
    {
        hour = time / 100;
        min = time % 100;
    }
    void addTimeData(int min)
    {
        this->min += min;
        if(this->min >= 60)
        {
            this->min %= 60;
            this->hour++;
        }
    }
    bool operator >(TimeData &td)
    {
        if(this->hour > td.hour)
        {
            return true;
        }
        else if(this->hour < td.hour)
        {
            return false;
        }
        if(this->min > td.min)
        {
            return true;
        }
        return false;
    }
};

bool isCheck(int hope_time, vector<int>& timelogs, int startday)
{
    TimeData hope_time_data(hope_time);
    hope_time_data.addTimeData(10);
    
    for(int i = 0; i < WEEK_SIZE; i++)
    {
        startday %= 7;
        
        //평일
        if(5 > startday)
        {
            TimeData td(timelogs[i]);
            
            //늦게 와버림
            if(td > hope_time_data)
            {
                return false;
            }
        }
        startday++;    
    }
    return true;
}



//희망_스케줄, 현실_스케줄, 시작요일 1~7
int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) 
{
    int answer = 0; //다 완수한?
    startday--;
    for(int i = 0; i < schedules.size(); i++)
    {
        if(isCheck(schedules[i], timelogs[i], startday))
        {
            answer++;
        }
    }
    
    return answer;
}