#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <stack>

using namespace std;

class Course {
public:
    string name;
    int dur = 0;
    int time = 0; //분단위
    
    Course(string name, string time, string dur)
    {
        this->name = name;
        //기간
        for(int i = 0; i < dur.size(); i++)
        {
            this->dur *= 10;
            this->dur += dur[i] - '0';
        }
        
        //시각
        for(int i = 0; i < 2; i++)
        {
            this->time *= 10;
            this->time += time[i] - '0';
        }
        this->time *= 60;
        
        int tmp = 0;
        for(int i = 3; i <= 4; i++)
        {
            tmp *= 10;
            tmp += time[i] - '0';
        }
        this->time += tmp;
    }
    
    //오름차순
    bool operator < (const Course & course) const &
    {
        if(this->time > course.time)
        {
            return true;
        }
        return false;
    }
};

vector<string> solution(vector<vector<string>> plans) 
{
    vector<string> answer;
    int time = 0;
    
    priority_queue<Course> pq;
    stack<Course> course_stack;
    //멈춘 과제는 스택구조
    
    //알아서 정렬해야함
    for(int i = 0; i < plans.size(); i++)
    {
        pq.push(Course(plans[i][0], plans[i][1], plans[i][2]));
    }
    
    //answer.push_back(to_string(pq.top().time));
    
    //일단 하나 빼서 time을 설정
    
    Course before = pq.top();
    pq.pop();
    
    while(true)
    {
        //다음 강의가 없다면 => 나가기
        if(pq.empty())
        {
            answer.push_back(before.name);
            while(!course_stack.empty())
            {
                before = course_stack.top();
                course_stack.pop();
                answer.push_back(before.name);
            }
            break;
        }
        
        Course course = pq.top();
        pq.pop();
        
        //다음 강의까지 빼기
        while(true)
        {
            //기간이 너무 많은 경우 => 그 시간만 저장하고 패스
            if(course.time - before.time < before.dur)
            {
                cout << before.name << ':'; //여기서 music이 나오면 
                
                before.dur -= course.time - before.time;
                cout << before.dur << '\n'; //30분
                
                course_stack.push(before);
                
                break;
            }
            //과제를 완료했다면 => stack 돌림 해야함
            else if(course.time - before.time > before.dur)
            {
                answer.push_back(before.name); //답 넣고
                time = before.time + before.dur; //before처리한 시각
                
                //만약 스택에서 꺼낼땐 before.time으로 설정해야한다.
                //즉, 스택에 넣는 순간 time은 무용지물
                //만약 스택이 없다면 break
                if(course_stack.empty())
                {
                    break;
                }
                before = course_stack.top();
                course_stack.pop();
                before.time = time; //최근 시간
            }
            //같다면
            else
            {
                answer.push_back(before.name); //답 넣고
                break;
            }
            
        }
        
        before = course;
    }
    
    return answer;
}