#include <string>
#include <vector>

#define MAX_INT_SIZE 2147483647
#define ALPHA_SIZE 26
using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) 
{
    vector<int> answer;
    
    int alpha[ALPHA_SIZE];
    for(int i = 0; i < ALPHA_SIZE; i++)
    {
        alpha[i] = MAX_INT_SIZE;
    }
    
    for(int i = 0; i < keymap.size(); i++)
    {
        for(int j = 0; j < keymap[i].length(); j++)
        {
            int index = keymap[i][j] - 'A';
            if(j + 1 < alpha[index])
            {
                alpha[index] = j + 1;
            }
        }
    }
    
    int sum;
    
    for(int i = 0; i < targets.size(); i++)
    {
        sum = 0;
        for(int j = 0; j < targets[i].size(); j++)
        {
            int index = targets[i][j] - 'A';

            if(alpha[index] == MAX_INT_SIZE)
            {
                sum = -1;
                break;
            }
            sum += alpha[index];
        }
        answer.push_back(sum);
    }
    
    return answer;
}