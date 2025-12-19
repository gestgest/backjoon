#include <string>
#include <vector>

using namespace std;

//w : width
int solution(int n, int w, int query_index) {
    query_index--;
    int query_w_index = -1;
    int w_index;
    int answer = 0;
    
    //vector<vector<int>> s = vector<vector<int>>(w);
    //         for(int j = 0; j < w; j++)
    //         {
    //             s[j].push_back(i + 1);
    //         }
    //         for(int j = w - 1; j >= w; j--)
    //         {
    //             s[j].push_back(i + 1);
    //         }
    
    for(int i = 0; i < n; i++)
    {
        //i == 12, w = 3
        //i == 5, w = 3
        //홀수층
        if((i / w) % 2 == 0)
        {
            w_index = i % w;
        }
        //짝수층
        else
        {
            w_index = w - 1 - (i % w);
        }
        
        //그 박스라면
        if(query_index == i)
        {
            query_w_index = w_index;
        }
        if(query_w_index == w_index)
        {
            answer++;
        }
    }
    
    return answer;
}