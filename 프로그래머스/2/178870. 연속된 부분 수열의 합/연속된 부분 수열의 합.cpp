#include <string>
#include <vector>
#include <iostream>

using namespace std;

//    s e 
//1 1 2 2 3 
//    => 이때 값은 4
//seq는 오름차순
vector<int> solution(vector<int> seq, int k) 
{
    vector<int> answer;
    //k인 부분 수열이 가장 짧은 수열
    int start = 0, end = -1;
    int answer_start = -1, answer_end = -1;
    int min_count = seq.size() + 1;
    int sum = 0;
    
    
    //일단 되는 순간 순차적으로 투포인터로 하다가
    while(end < (int)seq.size())
    {   
        //cout << end << ", " << seq.size() << '\n';
        
        //맨 처음 or sum이 부족. 또는 같으면 그냥 end 값 
        if(k > sum)
        {
            end++;
            sum += seq[end];
        }
        //k == sum...?
        else if(k == sum)
        {
            //start == end라면 애초에 총 합은 0이다.
            if(end - start < min_count)
            {
                //cout << start << ", " << end << '\n';
                min_count = end - start;
                answer_start = start;
                answer_end = end;
            }
            
            //이후 end를 증가시켜서 초기화
            end++;
            sum += seq[end];
        }
        else
        {
            sum -= seq[start];
            start++;
        }
    }
    answer.push_back(answer_start);
    answer.push_back(answer_end);
    
    return answer;
}