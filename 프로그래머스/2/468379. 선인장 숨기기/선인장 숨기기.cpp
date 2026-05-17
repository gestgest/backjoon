#include <string>
#include <vector>
#include <deque>

using namespace std;
#define INF 2147483647

//x 윈도우 슬라이드
vector<vector<int>> setDropWaterX(vector<vector<int>>& desert,
                  int cactus_width)
{
    vector<vector<int>> result = vector<vector<int>>(desert.size());
    //사이즈 할당 => desert_x - cactus_width + 1
    
    for(int i = 0; i < desert.size(); i++)
    {
        result[i] = vector<int>(desert[i].size() - cactus_width + 1, INF); //x 할당
        deque<int> dq; //index값을 가짐
        
        //x 압축
        for(int j = 0; j < desert[i].size(); j++)
        {
            //dq값이 있고 디큐 값이 현재 값보다 큰 경우
            while(!dq.empty() && desert[i][dq.back()] > desert[i][j])
            {
                dq.pop_back();
            }
            
            //push
            dq.push_back(j);
            
            //범위에서 벗어난 경우
            if(dq.front() <= j - cactus_width)
            {
                dq.pop_front();
            }
            
            //마지막에 result 값 넣기
            if(!dq.empty() && j >= cactus_width - 1)
            {
                result[i][j - cactus_width + 1] = desert[i][dq.front()];
            }
        }
    }
    
    return result;
}


vector<int> setDropWaterY(vector<vector<int>>& desert,int cactus_width, int cactus_height)
{
    vector<int> result;
    int max_value = 0;
    int max_index_y = 0;
    int max_index_x = 0;
    
    //반대로 x를 y처럼, y를 x처럼
    for(int j = 0; j < desert[0].size(); j++) //x임
    {
        deque<int> dq; //인덱스 저장용
        for(int i = 0; i < desert.size(); i++) //y임
        {
            //dq값이 있고 디큐 값이 현재 값보다 큰 경우
            while(!dq.empty() && desert[dq.back()][j] > desert[i][j])
            {
                dq.pop_back();
            }
            
            dq.push_back(i);
            
            //범위에서 벗어난 경우
            if(dq.front() <= i - cactus_height)
            {
                dq.pop_front();
            }
            
            //마지막에 비교 하기
            if(!dq.empty() && i >= cactus_height - 1)
            {
                if(max_value < desert[dq.front()][j])
                {
                    max_value = desert[dq.front()][j];
                    max_index_y = i - cactus_height + 1;
                    max_index_x = j;
                }
                else if(max_value == desert[dq.front()][j])
                {
                    //2 > 1 => 
                    if(max_index_y > i - cactus_height + 1)
                    {
                        max_index_y = i - cactus_height + 1;
                        max_index_x = j;
                    }
                    //같다면 x 비교
                    else if(max_index_y == i - cactus_height + 1 && max_index_x > j)
                    {
                        max_index_y = i - cactus_height + 1;
                        max_index_x = j;
                    }
                }
            }
        }
    }
    result.push_back(max_index_y);
    result.push_back(max_index_x);
    return result;
}

vector<int> printDebug(vector<vector<int>> & desert)
{
    vector<int> result;
    for(int i = 0; i < desert.size(); i++)
    {
        for(int j = 0; j < desert[i].size(); j++)
        {
            result.push_back(desert[i][j]);
        }
        
        result.push_back(-1);
    }
    return result;
}

//n, m은 사막 w h는 선인장
//최대한 선인장이 비를 맞으면 안된다. 비슷하면 위 > 왼쪽
vector<int> solution(int desert_height, int desert_width,
                     int cactus_height, int cactus_width,
                     vector<vector<int>> drops)
{
    vector<int> answer; //좌표
    vector<vector<int>> desert = vector<vector<int>>(desert_height);
    
    //for문 하나 두 개 만으로 해결해야함
    for(int i = 0; i < desert.size(); i++)
    {
        desert[i] = vector<int>(desert_width, INF);
    }
    
    //desert 셋팅
    for(int i = 0; i < drops.size(); i++)
    {
        desert[drops[i][0]][drops[i][1]] = i + 1;
    }
    
    
    vector<vector<int>> xx = setDropWaterX(desert, cactus_width);
    answer = setDropWaterY(xx, cactus_width, cactus_height);
    //answer = printDebug(xx);
    
    
    //answer.push_back(max_index_y); //y
    //answer.push_back(max_index_x);
    
    
    //answer = desert[1]; //5, 5,  3, 8, 
    
    return answer;
}