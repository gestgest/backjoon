#include <string>
#include <vector>

using namespace std;

//ABCDE
//FGHIJ
//KLMNO
//PQRST
//UVWXYZ
char addAlpha(char c, string & skip, int index)
{
    int a = c - 'a'; //0
    
    //index
    for(int i = 0; i < index; i++)
    {
        a++;
        a %= 26;
        
        //스킵
        for(int j = 0; j < skip.size(); j++)
        {
            //isPass
            if(a == skip[j] - 'a')
            {
                i--;
                break;
            }
        }
        
    }
    
    return a + 'a';
}
    

//스킵은 알파벳 셀때 카운트 안됨
string solution(string s, string skip, int index) 
{
    string answer = "";
    for(int i = 0; i < s.size(); i++)        
    {
        answer.push_back(addAlpha(s[i], skip, index));
    }
    
    return answer;
}