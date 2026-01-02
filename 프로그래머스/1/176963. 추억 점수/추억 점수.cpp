#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) 
{
    vector<int> answer;
    map<string, int> yearn_map;
    
    int n = name.size();
    for(int i = 0; i < n; i++)
    {
        yearn_map.insert(make_pair(name[i], yearning[i]));
    }
    
    for(int i = 0; i < photo.size(); i++)
    {
        int sum = 0;
        for(int j = 0; j < photo[i].size(); j++)
        {
            if(yearn_map.count(photo[i][j]) != 0)
            {
                sum += yearn_map[photo[i][j]];
            }
            
        }
        answer.push_back(sum);
    }
    
    return answer;
}