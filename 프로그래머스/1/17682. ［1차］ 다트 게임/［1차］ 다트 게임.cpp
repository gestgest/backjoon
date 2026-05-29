#include <string>

using namespace std;

bool addNumber(int & sum, int & current_score, int & before_score, char c, int type)
{
    //숫자라면
    if('0' <= c && c <= '9')
    {
        
        if(type != 0)
        {
            //예를 들어 type이 0이 아니라면 아래의 뭔가를 해야함
            sum += before_score;
            before_score = current_score;
            current_score = 0;
        }
        
        current_score *= 10;
        current_score += c - '0';
        return true;
    }
    
    return false;
}
bool addAlpha(int & number, char c)
{
    //알파벳이라면
    if('A' <= c && c <= 'Z')
    {
        switch(c) {
            case 'S':
                break;
                
            case 'D':
                number *= number;
                break;
                
            case 'T':
                number *= number * number;
                break;
        }
        return true;
    }
    return false;
}

void addSpecial(int & current_score, int & before_score, char c)
{
    //-
    if(c == '#')
    {
        current_score *= -1;
    }
    else ///c == '*'
    {
        before_score *= 2;
        current_score *= 2;
    }
}

//*는 전 점수 + 현재 점수 2배, #는 마이너스. 처음에 *나오면 현재만
int solution(string dartResult)
{
    //숫자 보너스 옵션
    int answer = 0;
    int current_score = 0;
    int before_score = 0;
    int before_type = 0; // 0 1 2
    
    for(int i = 0; i < dartResult.size(); i++)
    {
        //숫자인지 대문자인지 그 나머지(옵션)인지

        //숫자인지
        if(addNumber(answer, current_score, before_score, dartResult[i], before_type))
        {
            before_type = 0;
        }
        else if(addAlpha(current_score, dartResult[i]))
        {
            before_type = 1;
        }
        else //특수기호
        {
            addSpecial(current_score, before_score, dartResult[i]);
            before_type = 2;
        }
    }
    //마지막 다 했다면 
    answer += before_score;
    answer += current_score;
    
    return answer;
}