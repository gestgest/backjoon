#include <string>
#include <vector>

using namespace std;

//1 ~ k점, m개의 사과 포장
int solution(int k, int m, vector<int> score) 
{
    int answer = 0;
    //어차피 k는 9이하니 배열에 갯수를 넣어서 해결하자
    
    int s[10] = {0};
    int before = 0;
    
    //사과 넣기
    for(int i = 0; i < score.size(); i++)
    {
        s[score[i]]++;
    }
    
    for(int i = k; i >= 1; i--)
    {
        answer += (s[i] + before) / m * i * m;
        before = (s[i] + before) % m;
    }
    return answer;
    
    
}