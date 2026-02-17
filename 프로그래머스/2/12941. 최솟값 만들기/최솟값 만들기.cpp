#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> a, vector<int> b)
{
    int answer = 0;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    for(int i = 0; i < a.size(); i++)
    {
        answer += a[i] * b[b.size() - 1 - i];
    }
    
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "Hello Cpp" << endl;

    return answer;
}