#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Seq{
public:
    int row = 0;
    int col = 0;
    bool isEmpty = false;
};

int solution(vector<int> mats, vector<vector<string>> park) 
{
    vector<vector<Seq>> v = vector<vector<Seq>>(park.size());
    int answer = -1;
    
    for(int i = 0; i < park.size(); i++)
    {
        v[i] = vector<Seq>(park[i].size());
        for(int j = 0; j < park[i].size(); j++)
        {
            if(park[i][j] == "-1")
            {
                v[i][j].isEmpty = true;
            }
            else{
                v[i][j].isEmpty = false;
            }
        }
    }
    for(int i = 0; i <  v.size(); i++)
    {
        for(int j = 0; j < v[i].size(); j++)
        {
            if(!v[i][j].isEmpty)
            {
                continue;
            }
            if(i == 0 && j == 0)
            {
                v[i][j].row = 1;
                v[i][j].col = 1;
            }
            else if(i == 0)
            {
                v[i][j].row = 1;
                v[i][j].col = v[i][j - 1].col + 1;
            }
            else if(j == 0)
            {
                v[i][j].col = 1;
                v[i][j].row = v[i - 1][j].row + 1;
            }
            else
            {
                v[i][j].col = min(v[i][j - 1].col, v[i - 1][j - 1].col) + 1;
                v[i][j].row = min(v[i - 1][j].row, v[i - 1][j - 1].row) + 1;
            }
            
        }
    }

    int max_value = 0;
    for(int i = 0; i <  v.size(); i++)
    {
        for(int j = 0; j < v[i].size(); j++)
        {
            int num = min(v[i][j].row, v[i][j].col);
            max_value = max(num, max_value);
        }
    }
    
    for(int i = 0; i < mats.size(); i++)
    {
        if(mats[i] > max_value)
        {
            continue;
        }
        if(answer < mats[i])
        {
            answer = mats[i];
        }
    }
    return answer;
}