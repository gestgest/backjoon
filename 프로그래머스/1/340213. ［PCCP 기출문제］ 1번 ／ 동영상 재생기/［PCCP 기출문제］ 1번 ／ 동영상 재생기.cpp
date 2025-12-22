#include <string>
#include <vector>

using namespace std;

class TimeData{
public:
    int min = 0;
    int sec = 0;
    TimeData(string s)
    {
        int tmp = s[0] - '0';
        min += tmp;
        min *= 10;
        tmp = s[1] - '0';
        min += tmp;
        
        tmp = s[3] - '0';
        sec += tmp;
        sec *= 10;
        tmp = s[4] - '0';
        sec += tmp;
    }
    void addTime(int time)
    {
        sec += time;
        if(sec >= 60)
        {
            sec %= 60;
            min++;
        }
        
        else if(sec < 0)
        {
            if(min == 0)
            {
                sec = 0;
            }
            else{
                min--;
                sec += 60;
            }
        }
    }
    bool operator<= (TimeData & td)
    {
        if(this->min < td.min)
        {
            return true;
        }
        if(this-> min > td.min)
        {
            return false;
        }
        if(this->sec <= td.sec)
        {
            return true;
        }
        return false;
    }
    void setData(TimeData & td)
    {
        this->min = td.min;
        this->sec = td.sec;
    }
    string toString()
    {
        string result = "00:00";
        result[0] = min / 10 + '0';
        result[1] = min % 10 + '0';
        result[3] = sec / 10 + '0';
        result[4] = sec % 10 + '0';
        return result;
    }
    
    void property(TimeData & video_len, TimeData & op_start, TimeData & op_end)
    {
        //skip
        if(op_start <= *this && *this <= op_end)
        {
            this->setData(op_end);
        }
        else if(video_len <= *this)
        {
            this->setData(video_len);
        }
    }
};

string solution(string video_len_str, string pos, string op_start_str, string op_end_str, vector<string> commands) {
    string answer;
    TimeData video_len(video_len_str);
    TimeData current_time(pos);
    TimeData op_start(op_start_str);
    TimeData op_end(op_end_str);
    
    current_time.property(video_len, op_start, op_end);
    
    for(int i = 0; i < commands.size(); i++)
    {
        if(commands[i] == "prev")
        {
            current_time.addTime(-10);
        }
        else if(commands[i] == "next")
        {
            current_time.addTime(10);
        }
        current_time.property(video_len, op_start, op_end);
    }
    answer = current_time.toString();
    return answer;
}