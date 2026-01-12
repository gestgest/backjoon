#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> wallpaper) 
{
    //빈 파일은 . 파일이 있으면 #
    //vector<vector<bool>> s; //파일이 있으면 true
    //s = vector<vector<bool>>(wallpaper.size());
    vector<int> answer;
    
    int maxx = 0, maxy = 0, minx = wallpaper[0].size() + 1, miny = wallpaper.size() + 1;
    
    for(int i = 0; i < wallpaper.size(); i++)
    {
        //s = vector<bool>(wallpaper[i].size());
        for(int j = 0; j < wallpaper[i].size(); j++)
        {
            if(wallpaper[i][j] == '.')
            {
                //s[i][j] = false;
            }
            else //#
            {
                //s[i][j] = true;
                if(j < minx)
                {
                    minx = j;
                }
                if(maxx < j + 1)
                {
                    maxx = j + 1;
                }
                
                if(i < miny)
                {
                    miny = i;
                }
                if(maxy < i + 1)
                {
                    maxy = i + 1;
                }
            }
        }
    }
    
    answer.push_back(miny);
    answer.push_back(minx);
    answer.push_back(maxy);
    answer.push_back(maxx);
    return answer;
}