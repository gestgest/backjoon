#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

class Time{
public:
    int sum = 0; // min 단위. sum
    int time[2] = {-1, 1439};
    
    void setTime(int time_index, const string & time)
    {
        int min = 0;
        min += (time[0] - '0') * 10;
        min += (time[1] - '0');
        min *= 60;
        
        min += (time[3] - '0') * 10;
        min += (time[4] - '0');
        
        this->time[time_index] = min;
        
        // 만약 다 했다면
        if(time_index == 1)
        {
            sum += this->time[1] - this->time[0];
            this->time[0] = -1; // 다시 비활성화
            this->time[1] = 1439; // 다시 비활성화
        }
    }
    
};

int getIndex(const string & s)
{
    int index = 0;
    for(int i = 6; i < 10; i++)
    {
        index *= 10;
        index += s[i] - '0';
    }
    return index;
}
// fees => 기본 시간, 기본 금, 단위 시간, 단위 요금
vector<int> solution(vector<int> fees, vector<string> records) 
{
    vector<int> answer;
    map<int, Time> times;
    
    // 차 번호 오름차순
    for(int i = 0; i < records.size(); i++)
    {
        int size = records[i].size();
        
        // I'n' , Ou't'
        bool time_index = records[i][size - 1] == 'N' ? 0 : 1;
        int car_index = getIndex(records[i]);
        
        // 존재 안하는 경우
        if(times.count(car_index) == 0)
        {
            Time time;
            time.setTime(time_index, records[i]);
            times.insert(make_pair(car_index, time));
        }
        else
        {
            times[car_index].setTime(time_index, records[i]);
        }
    }
    
    
    for(auto it = times.begin(); times.end() != it ; it++)
    {
        // 남아있는 주차 시간이 있다면
        if(it->second.time[0] != -1) 
        {
            it->second.sum += it->second.time[1] - it->second.time[0];
        }
        int sum = it->second.sum;
        
        // 기본요금
        int money = fees[1];
        sum = max(0, sum - fees[0]); // 음수 방지
        
        int add = sum % fees[2] == 0 ? 0 : 1;
        
        money += ((sum / fees[2]) + add)* fees[3];
        answer.push_back(money);
    }
    
    return answer;
}