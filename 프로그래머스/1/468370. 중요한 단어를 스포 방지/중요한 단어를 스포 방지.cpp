#include <string>
#include <vector>
#include <map>

using namespace std;

class Word{
    bool isSpoiler = false;
    string word;
    Word(string word, bool isSpoiler)
    {
        this->word = word;
        this->isSpoiler = isSpoiler;
    }
};

int solution(string message, vector<vector<int>> spoiler_ranges) 
{
    int answer = 0;
    bool isSpoiler = false;
    string tmp = "";
    int sp_count = 0;
    
    map<string, bool> sp_words;
    
    for(int i = 0; i < message.size(); i++)
    {
        if(' ' == message[i])
        {
            if(tmp == "")
            {
                continue;
            }
            //이미 존재한다면
            if(sp_words.count(tmp))
            {
                //현재가 스포가 아닌데 과거는 스포 => 변경
                if(!isSpoiler && sp_words[tmp])
                {
                    sp_words[tmp] = false;
                }
                
                //현재가 스포, 과거는 스포아님 => 무시
                //현재가 스포, 과거도 스포 => 무시
                //현재가 스포가 아닌데 과거도 스포가 아닌거 => 무시
            }
            else{
                sp_words.insert(make_pair(tmp, isSpoiler));
            }
            tmp = "";
            isSpoiler = false;
        }
        else
        {
            tmp += message[i];
            
            //엄준식_준식
            if(sp_count < spoiler_ranges.size())
            {
                //끝 범위를 넘어선 경우
                if(spoiler_ranges[sp_count][1] < i)
                {
                    sp_count++;
                }
                //범위 안에 들었다면
                if(sp_count < spoiler_ranges.size() && spoiler_ranges[sp_count][0] <= i)
                {
                    isSpoiler = true;
                }
            }
        }
    }
    
    
    //마무리
    if(tmp != "")
    {
        //이미 존재한다면
        if(sp_words.count(tmp))
        {
            //현재가 스포, 과거는 스포아님 => 무시
            //현재가 스포, 과거도 스포 => 무시
            //현재가 스포가 아닌데 과거도 스포가 아닌거 => 무시
            //현재가 스포가 아닌데 과거는 스포 => 변경
            if(!isSpoiler && sp_words[tmp])
            {
                 sp_words[tmp] = false;
            }
        }
        else{
            sp_words.insert(make_pair(tmp, isSpoiler));
        }
    }
    
    for(auto it = sp_words.begin(); it != sp_words.end(); it++)
    {
        if(it->second)
        {
            answer++;
            // phone number is 01012345678 and may i have your phone number
            // 01234567890123456789012345678901
        }
    }
    
    
    return answer;
}