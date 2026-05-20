#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class StageFail{
public:
    float rate;
    int index;
    
    bool operator < (const StageFail & stage) const
    {
        if(this->rate < stage.rate)
        {
            return false;
        }
        else if(this->rate > stage.rate)
        {
            return true;
        }
        if(this->index > stage.index)
        {
            return false;
        }
        return true;
    }
};

//스테이지 번호 배열 리턴 (맨 앞이 실패율 높은 거) => 같다면 작은 번호의 스테이지가 앞에
//n은 스테이지 갯수, stages는 유저 느낌인듯
vector<int> solution(int n, vector<int> users) 
{
    vector<int> answer;
    vector<int> stages = vector<int>(n + 2, 0);
    vector<StageFail> stagefails = vector<StageFail>(n); //1 ~ n - 1 알아서 잘 계산해라
    int sum = 0;
    // 스테이지
    
    for(int i = 0; i < users.size(); i++)
    {
        stages[users[i]]++;
    }
    
    //누적합
    for(int i = 1; i < stages.size() - 1; i++)
    {
        stages[i] += stages[i - 1];
        stagefails[i - 1].index = i;
        
        if(users.size() - stages[i - 1] != 0)
        {
            stagefails[i - 1].rate = (float)(stages[i] - stages[i - 1]) / (users.size() - stages[i - 1]);
        }
        else { //나눗셈 0 버그 
            stagefails[i - 1].rate = 0;
        }
        
    }
    
    // 한마디로 현재 stages의 유저 수  ([i] - [i - 1]) / (전체 값 - [i - 1])
    
    //이후 정렬
    sort(stagefails.begin(), stagefails.end());
    for(int i = 0; i < stagefails.size(); i++)
    {
        answer.push_back(stagefails[i].index);
    }
    
    return answer;
}