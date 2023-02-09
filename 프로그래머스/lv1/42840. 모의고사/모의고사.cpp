#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    int SIZE[3] = {5,8,10};
    
    int ans[3][10] = {{1,2,3,4,5,1,2,3,4,5}, {2,1,2,3,2,4,2,5,2,1}, {3,3,1,1,2,2,4,4,5,5} };
    int ans_score[3] = {0,0,0};
    
    for(int i = 0; i < answers.size(); i++)
    {
        for(int j = 0; j < 3; j++)
        {
            int n = i % SIZE[j];
            if(answers[i] == ans[j][n])
            {
                ans_score[j]++;
            }
        }
    }
    int max = ans_score[0];
    answer.push_back(1);
    for(int i = 1; i < 3; i++)
    {
        if(max < ans_score[i])
        {
            max = ans_score[i];
            answer.clear();
            answer.push_back(i + 1);
        }
        else if(max == ans_score[i])
        {
            answer.push_back(i + 1);
        }
    }
    
    return answer;
}