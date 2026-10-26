#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> cards) 
{
    int a = 0;
    int index = 0;
    vector<bool> isCheck = vector<bool>(cards.size());
    vector<int> box;
    
    // 한번
    for(int i = 0; i < cards.size(); i++)
    {
        if(isCheck[i])
        {
            continue;
        }
        
        index = i;
        a = 0;
        
        while(true)
        {
            if(isCheck[index])
            {
                break;
            }
            isCheck[index] = true;
            index = cards[index] - 1;
            a++;
        }
        box.push_back(a);
    }
    if(box.size() == 1)
    {
        return 0;
    }
    sort(box.begin(), box.end());
    
    return box[box.size() - 1] * box[box.size() - 2];
}