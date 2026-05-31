#include <vector>
#include <iostream>
using namespace std;

#define MAX_SIZE 3000

//3 ~ 50 
// 3000 이하
int solution(vector<int> nums) 
{
    int answer = 0;

    //3000이하까지 소수를 판단하는 배열을 만든다.
    vector<bool> prime = vector<bool>(MAX_SIZE + 1, true);
    prime[0] = false;
    prime[1] = false;
    
    for(int i = 2; i < MAX_SIZE; i++)
    {
        if(!prime[i]) //이미 소수가 아니라면
        {
            continue;
        }
       for(int j = i + i; j <= MAX_SIZE; j += i)  //4 6 8 ... false로 넣기
       {
           prime[j] = false;
       }
    }
    
   // for(int i = 1; i < 20; i++)  //4 6 8 ... false로 넣기
   // {
   //     cout << i <<" : " << prime[i] << '\n';
   // }
    
    for(int i = 0; i < nums.size(); i++)
    {
        for(int j = i + 1; j < nums.size(); j++)
        {
            for(int k = j + 1; k < nums.size(); k++)
            {
                if(nums[i] + nums[j] + nums[k] > MAX_SIZE) //범위 안에 없다면
                {
                    continue;
                }
                if(prime[nums[i] + nums[j] + nums[k]]) //소수라면
                {
                    answer++;
                }
            }
        }
    }
    

    return answer;
}