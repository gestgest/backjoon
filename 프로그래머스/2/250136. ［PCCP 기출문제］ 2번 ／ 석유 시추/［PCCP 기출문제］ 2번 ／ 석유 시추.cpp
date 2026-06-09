#include <string>
#include <vector>
#include <iostream>

using namespace std;

int dir[4][2] = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
//이거를 뭐라하지 2차 배열 유니온?

bool isRange(vector<vector<int>> & land, int y, int x)
{
    if(0 > y || y >= land.size())
    {
        return false;
    }
    if(0 > x || x >= land[y].size())
    {
        return false;
    }
    return true;
}

int setLand(vector<vector<int>> & land, int start_y, int start_x, int index)
{
    int result = 1;
    land[start_y][start_x] = index;
    
    for(int i = 0; i < 4; i++)
    {
        int y = start_y + dir[i][1];
        int x = start_x + dir[i][0];
        if(isRange(land, y, x))
        {
            if(land[y][x] == 1) //없거나 이미 차지한 경우는 제외
            {
                result += setLand(land, y, x, index);
            }
        }
    }
    return result;
}

//500 x 500
int solution(vector<vector<int>> land)
{
    int answer = 0;
    int index = 2;
    vector<int> sichoo;
    
    sichoo.push_back(0);
    sichoo.push_back(0);
    
    //석유를 영토로 변환
    for(int i = 0; i < land.size(); i++)
    {
        for(int j = 0; j < land[i].size(); j++)
        {
            if(land[i][j] == 1)
            {
                sichoo.push_back(setLand(land, i, j, index)); 
                index++;
            }
            //cout << land[i][j];
        }
        //cout << '\n';
    }
    
    for(int j = 0; j < land[0].size(); j++) //x탐색
    {
        int result = 0;
        vector<bool> isCheck = vector<bool>(sichoo.size(), false);
        for(int i = 0; i < land.size(); i++)
        {
            if(isCheck[land[i][j]])
            {
                continue;
            }
            result += sichoo[land[i][j]];
            isCheck[land[i][j]] = true;
        }
        answer = max(result, answer);
    }
    
    return answer;
}