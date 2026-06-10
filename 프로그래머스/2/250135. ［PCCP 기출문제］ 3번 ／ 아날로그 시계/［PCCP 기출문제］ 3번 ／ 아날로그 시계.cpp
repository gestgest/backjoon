#include <string>
#include <vector>
#include <iostream>

using namespace std;

class MyTime
{
public:
    int total;
    //각도단위다.
    bool before_hour = false;
    bool before_min = false;
    
    int hour; //1단위
    int min; //24단위
    int sec; //1440 단위 
    MyTime(int hour, int min, int sec)
    {
        total = sec + min * 60 + hour * 3600; //초 단위로 환산
        translate();
    }
    
    void operator ++(int)
    {
        //여기서는 sec가 둘다 작은데
        total++;
        translate();
        //갑자기 sec가 둘중 하나라도 커지거나 같아진 경우 
    }
    
    
    void translate()
    {
        //total => 
        this->sec = (total % 60) * 1440; //0 ~ 86399 => 0을 86400
        this->min = (total % 3600) * 24;
        this->hour = (total % 43200) * 2; //여기서 잠깐 얘는 24시간이 아닌 12로 나눠야 한다
        
        //근데 이러면 0 ~ 1 방지도 해야함
        
        //cout << this->hour << ", " << this->min << ", " << this->sec << '\n';
        if((this->sec <= this->min))
        {
            before_min = true;
        }
        if(this->sec <= this->hour)
        {
            before_hour = true;
        }
        //cout << before_min << ", " << before_hour <<'\n';
    }
    int isCheck()
    {
        int result = 0;
        //cout << "냠냠 \n";
        //cout << this->hour << ", " << this->min << ", " << this->sec << '\n';
        
        //before 불 값이 하나라도 있으면 true
        //이거 무슨 지나가는 것도 체크해야한다.
        //cout << before_min << ", " << before_hour << '\n';
        
        //만약 hour가 
        //
        
        //3개다 일치한다면
        if(min == hour && hour == sec) 
        {
            before_min = false;
            before_hour = false;
            return 1;
        }
        //나머지 min < sec면 1 , hour < sec면 ++
        //초가 59일때 before가 true라면 아직도 안 지나감
        //hour 
        if(((this->sec >= this->hour) 
            || (this->sec == 0 && this->hour > 59 * 1440)) && before_hour)
        {
            before_hour = false;
            result++;
        }
        if(((this->sec >= this->min)
             || (this->sec == 0 && this->min > 59 * 1440)) && before_min)
        {
            before_min = false;
            result++;
        }
        
        //if(this->sec >= this->min)
        //cout << result << '\n';
        return result;
    }
    int getResult(MyTime & b)
    {
        int result = 0;
        int a_size = total;
        
        for(int i = a_size; i <= b.total; i++)
        {
            //만약 같다면
            result += isCheck();
            (*this)++;
        }
        
        return result;
    }
    
};

//~ 
int solution(int h1, int m1, int s1, int h2, int m2, int s2) 
{
    int answer = -1;
    //초침이 시, 분을 겹쳐야 함.
    // h1 = 11;
    // m1 = 58;
    // s1 = 59;
    // h2 = 11;
    // m2 = 59;
    // s2 = 0;
    
    //max : 86400 => 1 * 86400
    //max : 86400 => 24 * 3600
    //max : 86400 => 1440 * 60
    MyTime a(h1, m1, s1);
    MyTime b(h2, m2, s2);
    
    answer = a.getResult(b);
    // ~ 
    
    
    return answer;
}