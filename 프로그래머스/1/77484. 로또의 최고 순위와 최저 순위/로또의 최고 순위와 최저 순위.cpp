#include <string>
#include <vector>

using namespace std;

//6 : 1등, 5 : 2등 4 : 3등, 3 : 4등, 2 : 5등 , 1과 0 : 6등
int getAnswer(int n) //n은 맞춘 횟수
{
    int answer = 7 - n;
    if(answer > 6) answer = 6;
    return answer;
}

vector<int> solution(vector<int> lottos, vector<int> win_nums)
{
    vector<int> answer;
    vector<bool> s = vector<bool> (45, false);
    int zero_count = 0;
    int answer_count = 0;
    
    for(int i = 0; i < win_nums.size(); i++)
    {
        s[win_nums[i] - 1] = true;
    }
    for(int i = 0; i < lottos.size(); i++)
    {
        if(lottos[i] == 0)
        {
            zero_count++;
        }
        else
        {
            //만약 있다면
            if(s[lottos[i] - 1])
            {
                answer_count++;
            }
        }
    }
    
    answer.push_back(getAnswer(answer_count + zero_count));
    answer.push_back(getAnswer(answer_count));
    //zero만 따로
    return answer;
}