#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int lowerIdx(vector<int>& w, int lo, int hi, int target)
{
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (w[mid] < target) lo = mid + 1;
        else                 hi = mid;      
    }
    return lo;
}

int upperIdx(vector<int>& w, int lo, int hi, int target)
{
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (w[mid] <= target) lo = mid + 1;
        else                  hi = mid;
    }
    return lo;
}

long long isSeesaw(vector<int>& weights, int start)
{
    long long result = 0;
    int n = weights.size();

    for (int i = 2; i <= 4; i++) {
        for (int j = 2; j <= i; j++) {
            if (i != 2 && i == j) continue;          
            if (weights[start] * i % j != 0) continue;

            int target = weights[start] * i / j;     
            int lo = lowerIdx(weights, start + 1, n, target);
            int hi = upperIdx(weights, start + 1, n, target);
            result += hi - lo;                       
        }
    }
    return result;
}

long long solution(vector<int> weights)
{
    long long answer = 0;
    sort(weights.begin(), weights.end());

    for (int i = 0; i < (int)weights.size(); i++)
        answer += isSeesaw(weights, i);

    return answer;
}