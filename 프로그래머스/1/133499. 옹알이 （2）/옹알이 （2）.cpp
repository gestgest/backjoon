#include <string>
#include <vector>

using namespace std;

vector<string> bb;

// bb[i]
bool isCheck2(string a, string b, int start_index)
{
    for(int i = 0; i < b.size() ; i++)
    {
        //a = ay, b = aya
        if(i + start_index >= a.size())
        {
            return false;
        }
        //단어가 다름
        if(b[i] != a[i + start_index])
        {
            return false;
        }
    }
    return true;
}
//bb
int isCheck1(string a, int start_index)
{
    for(int i = 0; i < 4; i++)
    {
        if(isCheck2(a, bb[i], start_index))
        {
            return i;
        }
    }
    return -1;
}


int solution(vector<string> babbling) 
{
    bb.push_back("aya");
    bb.push_back("ye");
    bb.push_back("woo");
    bb.push_back("ma");
    
    int answer = 0;
    
    for(int i = 0; i < babbling.size(); i++)
    {
        bool isAnswer = true;
        int count = 0;
        int before_index = -1;
        //woo woowoo
        while(true)
        {
            int index = isCheck1(babbling[i], count);
            //-1은 없는거
            if(index == -1)
            {
                break;
            }
            //yeye같은 반복
            if(before_index == index)
            {
                break;
            }
            count += bb[index].size();
            //전부 yema같은 옹알이가 있는 경우
            if(count == babbling[i].size())
            {
                answer++;
                break;
            }
            before_index = index;
        }
    }
    
    return answer;
}