#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> indexSum;
vector<long long> block;

//indexSum 기준 index를 반환, start end도 그거 기준
long long binary_search_index(long long start, long long end, long long index)
{
    //3 2
    //3 5
    //~ 2라면 0 index 3넣었는데 
    while(start <= end)
    {
        long long mid = (start + end) / 2;
        
        if(indexSum[mid] < index)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return start;
}

//누적합임
//2) p누적합 index 갯수 => p(r) - p(l)
//index는 당연히 l, r같은 전체 index. sum_index는 indexSum
long long pref(vector<int>& arr, long long index)
{
    if (index <= 0) return 0;
    long long b = binary_search_index(0, indexSum.size() - 1, index);
    return block[b] - (indexSum[b] - index) * arr[b - 1];
}

long long value_at(vector<int> & arr, long long index)
{
    long long b = binary_search_index(0, indexSum.size() - 1, index);
    return arr[b - 1];
}

vector<long long> solution(vector<int> arr, long long l, long long r) 
{
    vector<long long> answer;
    indexSum = vector<long long>(arr.size() + 1, 0);
    block = vector<long long>(arr.size() + 1, 0); //value
    vector<long long> points;

    long long p_max;
    long long count = 0;
    long long length = r - l + 1;
    
    for(int i = 1; i <= arr.size(); i++)
    {
        indexSum[i] = arr[i - 1] + indexSum[i - 1];
        block[i] = (long long)arr[i - 1] * arr[i - 1]  + block[i - 1];
    }
    
    //2. k 구하는 식 : 이분탐색
    long long block_left = binary_search_index(0, indexSum.size() - 1, l);
    long long block_right = binary_search_index(0,indexSum.size() - 1, r);
    
    long long K = pref(arr, r) - pref(arr, l - 1);
    //left 값을 하나 빼야하나
    answer.push_back(K);
    
    p_max = indexSum[arr.size()] - length + 1;
    
    //3 - 1) 무조건 처음 값과 마지막 값을 넣어라
    points.push_back(1);
    points.push_back(p_max); //마지막 값은 length가 수용할 수 있는 맨 처음 값
        
    //3) 분기점 points를 구해라
    //ㄴ 가장 어려운듯
    for(int i = 0; i < indexSum.size(); i++)
    {
        //p1) 자 왼쪽 기준 값이 바뀌는 거
        //p2 자 오른쪽 기준 값이 바뀌는데 결국 p2의 값은 자의 맨 왼쪽
        long long left = indexSum[i] + 1;
        long long right = indexSum[i] + 2 - length;
        
        
        //3-2) 이것도 빠트렸네 => 대충 범위 안에 있는지
        if (left >= 1 && left <= p_max) points.push_back(left);
        if (right >= 1 && right <= p_max) points.push_back(right);
    }
    
    //4) 정렬 후 제거
    sort(points.begin(), points.end());
    points.erase(unique(points.begin(), points.end()), points.end());
    
    
    //5) 값이 바뀌는 분기점 모두 탐색
    for (size_t i = 0; i < points.size(); i++)
    {
        long long a = points[i];
        //다음 포인트가 없다면 \. 아니라면 다음 포인트의 전 값
        long long b = (i + 1 < points.size()) ? points[i+1] - 1 : p_max;

        long long fa = pref(arr, a + length - 1) - pref(arr, a - 1); //범위안 값의 합
        long long dis = value_at(arr, a + length - 1) - value_at(arr, a);

        if (dis == 0)
        {
            if (fa == K) count += b - a + 1;
        }
        else
        {
            long long diff = K - fa;
            if (diff % dis == 0)
            {
                long long k = diff / dis;
                if (k >= 0 && k <= b - a) count++;
            }
        }
    }
    
    
    answer.push_back(count);
    return answer;
}