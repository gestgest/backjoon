#include <string>
#include <vector>

using namespace std;

string second(string & new_id)
{
    string result = "";
    
    //
    for(int i = 0; i < new_id.size(); i++)
    {
        if('a' <= new_id[i] && new_id[i] <= 'z')
        {
            result += new_id[i];
        }
        else if('0' <= new_id[i] && new_id[i] <= '9')
        {
            result += new_id[i];
        }
        else if(new_id[i] == '_' || new_id[i] == '-' || new_id[i] == '.')
        {
            result += new_id[i];
        }
    }
    
    return result;
}

string third(string & new_id)
{
    string result = "";
    
    for(int i = 0; i < new_id.size(); i++)
    {
        if(i != 0 && new_id[i - 1] == '.' &&  new_id[i] == '.')
        {
            continue;
        }
        result += new_id[i];
    }
    
    return result;
}

string four(string & s)
{
    string result = "";
    
    for(int i = 0; i < s.size(); i++)
    {
        if((i == 0 || i == s.size() - 1) && s[i] == '.')
        {
            continue;
        }
        result += s[i];
    }
    return result;
}
string six(string & s)
{
    string result = "";
    
    for(int i = 0; i < s.size() && i < 15; i++)
    {
        if((i == s.size() - 1 || i == 14) && '.' == s[i])
        {
            break; //마지막 .
        }
        result += s[i];
    }
    
    return result;
}

//3자 이상 15자 이하 (안되면 )
string solution(string new_id)
{
    string answer = "";
    
    //1단계
    for(int i = 0; i < new_id.size(); i++)
    {
        //대문자
        if('A'<= new_id[i] && new_id[i] <= 'Z')
        {
            new_id[i] = new_id[i] - 'A' + 'a';
        }
    }
    
    new_id = second(new_id); //2단계
    new_id = third(new_id);
    new_id = four(new_id);
    
    //5
    if(new_id.size() == 0)
    {
        new_id = "a";
    }
    new_id = six(new_id);
    
    //7
    while(new_id.size() < 3)
    {
        new_id += new_id[new_id.size() - 1]; //마지막 추가
    }
    answer = new_id;
    return answer;
}