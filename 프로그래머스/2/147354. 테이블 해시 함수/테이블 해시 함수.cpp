#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

struct Comp {
    int col;
    bool operator()(const vector<int> & a, const vector<int> & b) const{
        if(a[col] != b[col])
        {
            //오름차순
            return a[col] < b[col];
        }
        return a[0] > b[0];
    }
    
};

//
int solution(vector<vector<int>> data, int col, int row_begin, int row_end)
{
    int answer = 0;
    
    // col 단위로 정렬
    sort(data.begin(), data.end(), Comp{col - 1});
    
    // begin ~ end까지 
    //for(int i = 0; i < data.size(); i++)
    for(int i = row_begin - 1; i < row_end; i++)
    {
        int sum = 0;
        for(int j = 0; j < data[i].size(); j++)
        {
            //cout << data[i][j] % (i + 1) << ' ';
            sum += data[i][j] % (i + 1);
        }
        //cout << '\n';
        
        answer ^= sum;
    }
    
    return answer;
}