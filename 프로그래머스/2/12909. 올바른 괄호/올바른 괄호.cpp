#include <string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    int stack_size = 0;
    
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == '(')
        {
            stack_size++;
        }
        else //')'
        {
            stack_size--;
            if(stack_size < 0)
            {
                return false;
            }
        }
    }
    if(stack_size != 0)
    {
        return false;
    }

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "Hello Cpp" << endl;

    return answer;
}