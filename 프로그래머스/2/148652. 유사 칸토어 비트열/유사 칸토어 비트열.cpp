#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;


//세그먼트 트리 비슷한데
//아예 싹다 겹치면 
long long bf(const int n, int index, 
             const long long start, const long long end,
             long long range_start, long long range_end)
{
    long long sum = 0;
    
    //만약 처음인데 start ~ end 범위가 내부에 있다면
    //               2 3 3 6
    if(start <= range_start && range_end <= end)
    {
        //cout << range_start << ' ' << range_end << ", " << index<< '\n';
        //목표가 2고 현재위치가 1이면 => 4^n만큼 리턴
        return pow(4, n - index);
    }
    
    //범위에 포함하지도 않는다면
    if(range_end < start || end < range_start)
    {
        return 0;
    }
    
    long long dis = range_end - range_start + 1;
    
    for(int i = 0; i < 5; i++)
    {
        //0을 의미
        if(i == 2)
        {
            continue;
        }
        sum += bf(n, index + 1, start, end,
            range_start + dis * i / 5,
            range_start + dis * (i + 1) / 5 - 1
        );
    }
    return sum;
}
    
int solution(int n, long long l, long long r) 
{
    //정해진 구역의 1의 개수
    
    //17개 + 8
    long long answer = bf(n, 0, l - 1, r - 1,
                          0, pow(5, n) - 1);
    
    //0 => 1
    //1 => 11011
    //2 => 1101111011000001101111011 => 1의 16개
    //125^5 => 
    
    
    return answer;
}