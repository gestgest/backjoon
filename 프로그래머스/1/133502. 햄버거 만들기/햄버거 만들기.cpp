#include <string>
#include <vector>
#include <stack>

using namespace std;

//1 1 1 1 3 3 3 3 => 1 스택 다 제거
//스택
int solution(vector<int> ingredient) 
{
    //1 2 3 1
    int answer = 0;
    stack<int> s;
    
    for(int i = 0; i < ingredient.size(); i++)
    {
        if(s.empty())
        {
            //초반에 2 3이면 그냥 버려라
            if(ingredient[i] == 1)
            {
                s.push(2);
            }  
        }
        else //stack이 비어있지 않음
        {
            if(ingredient[i] == s.top())
            {
                s.pop();
                
                //소고기인 경우
                if(ingredient[i] == 3)
                {
                    //빵을 노리자
                    s.push(1);
                }
                else if(ingredient[i] == 1) //빵인 경우
                {
                    answer++;
                }
                else
                {
                    s.push(ingredient[i] + 1);
                }
            }   
            
            //초반에 2 3이면 그냥 버려라
            else if(ingredient[i] == 1)
            {
                s.push(2);
            }
            else if(ingredient[i] >= 2 ) //1 1 2 2 => 근데 이것도 결국 앞 경우가 불가능 하니까 스택초기화?
            {
                //s.clear()
                while(!s.empty())
                    s.pop();
                
            }
        }
    }
    
    return answer;
}