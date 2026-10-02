#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


int solution(int k, vector<int> tangerine) 
{
    int answer = 0;
    int count = 0; // k 비교용
    vector<int> v = vector<int>(10000000, 0);
    
    for(int i = 0; i < tangerine.size(); i++)
    {
        v[tangerine[i] - 1]++;
    }
    sort(v.begin(), v.end());
    for(int i = v.size() - 1; i > 0; i--)
    {
        if(count >= k)
        {
            break;
        }
        count += v[i];
        answer++;
        //cout << count << ", " << answer << '\n';
        
    }
    
    return answer;
}