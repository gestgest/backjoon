#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

class Number{
public:
    int index;
    int value;
    Number(int index, int value)
    {
        this->index = index;
        this->value = value;
    }
};

//7시 50분까지
//어...? 익숙하다? 오큰수 문제
vector<int> solution(vector<int> numbers) 
{
    //뒤 기준 가장 가까운 큰 수
    vector<int> answer = vector<int>(numbers.size(), -1);
    stack<Number> number_stack;
    
    for(int i = 0; i < numbers.size(); i++)
    {
        while(!number_stack.empty())
        {
            Number number = number_stack.top();
            if(number.value < numbers[i])
            {
                answer[number.index] = numbers[i];
                number_stack.pop();
            }
            else //어차피 자연스럽게 내림차순임
            {
                break;
            }
        }
        number_stack.push(Number(i, numbers[i]));
    }
    //이게 자연스럽게 자료는 내림차다.
    
    //진짜로 높은 값이 나오면 pop?
    // 그리고 나머지 끝났다면 죄다 -1
    
    
    return answer;
}