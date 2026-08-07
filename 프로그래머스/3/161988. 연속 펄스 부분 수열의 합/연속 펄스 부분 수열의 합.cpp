#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//누적합 뒤틀린 버전
//펄스 수열 : 1 -1 또는 -1 1
long long solution(vector<int> sequence) 
{
    long long answer = 0;
    //1 -1을 디폴트로 해서 쭈욱 누적합 해보자
    //2 -1 -7 -8 -5 -4 -2 -6
    // -2한 기준 
    long long seq1 = 0;
    long long seq2 = 0;
    
    for(int i = 0; i < sequence.size(); i++)
    {
        int mu = 1;
        if(i % 2 == 1) mu = -1;
        seq1 += sequence[i] * mu;
        seq2 += sequence[i] * mu * -1;
        
        seq1 = max((long long)0, seq1);
        seq2 = max((long long)0, seq2);
        
        answer = max(answer, max(seq1, seq2));
    }
    
    return answer;
}