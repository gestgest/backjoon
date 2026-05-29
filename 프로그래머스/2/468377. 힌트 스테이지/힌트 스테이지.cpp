#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

//49250 


//stage가 0이면 1라운드
//힌트를 쓸 때 마다 
int bf(vector<vector<int>> & cost, vector<vector<int>> & hint, vector<int> hint_count, int stage)
{
    //index == max_index
    if(cost.size() == stage)
    {
        return 0;
    }
    int left = 0, right = 0;
    
    //안산다면
    if(hint_count[stage] >= cost[stage].size())
        hint_count[stage] = cost[stage].size() - 1; //만약 힌트 갯수가 많으면 어떡하지
    right = cost[stage][hint_count[stage]]; 
    right += bf(cost, hint, hint_count, stage + 1);
    
    //산다면? => 마지막은 힌트권을 사지 않는다.
    if(stage == hint.size())
    {
        return right;
    }
    
    if(hint_count[stage] >= cost[stage].size())
        hint_count[stage] = cost[stage].size() - 1; //만약 힌트 갯수가 많으면 어떡하지
    left = cost[stage][hint_count[stage]]; 
    
    //구매
    left += hint[stage][0];
    
    //힌트 
    for(int i = 1; i < hint[stage].size(); i++) //개수 채우기
    {
        hint_count[hint[stage][i] - 1]++;
    }
    left += bf(cost, hint, hint_count, stage + 1);
    
    //무조건 left가 싸야함
    if(stage == 0)
        cout << " left가 싸야함 : " << left << ", " << right << '\n';
    
    //min 사는 경우, 안 사는 경우
    return min(left, right);
}

int solution(vector<vector<int>> cost, vector<vector<int>> hint) 
{
    int answer = 0;
    vector<int> hint_count = vector<int>(cost.size(), 0); //index는 stage
    
    answer = bf(cost, hint, hint_count, 0);
    
    return answer; //최소비용
}