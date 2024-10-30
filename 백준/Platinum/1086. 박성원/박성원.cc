#include <iostream>
#include <vector>
#include <algorithm>

#define INF 2147483647
#define MAX_STRING_SIZE 51

using namespace std;
typedef long long ll;
ll n, k;
string s_tmps[20];
int cache[55];
int value_string[55];
// 사용한 원소를 비트마스킹
// 나머지에 대해 저장
ll dp[1 << 16][100];
// 최대 공약수(기약분수로 만들기 위함)
ll GCD(ll a, ll b) {
    return b ? GCD(b, a % b) : a;
}

//문자열을 나머지 값으로
long long stringToValue(string s)
{
    long long sum = 0;
    for (int i = 0; i < s.size(); i++)
    {
        sum *= 10;
        sum += s[i] - '0';
        sum %= k;
    }
    return sum;
}

long long dp_park(int value, int status)
{
    //long long num = stringToValue(s);

    if (status == (1 << n) - 1)
    {
        return value == 0 ? 1 : 0; //나머지 값이 0이면 1, 나머지면 0
    }
    //나머지가 [101][2]인 애는 결국 똑같은 값이 나온다

    //한번이라도 지나갔다면 
    if (dp[status][value] != -1) {
        return dp[status][value];
    }

    dp[status][value] = 0; // 지나간 길 설정


    for (int i = 0; i < n; i++)
    {
        //이미 있다면
        if (status & (1 << i)) {
            continue;
        }
        //문자열 합체

        //value는 이미 k를 나눈 나머지 값
        int next_value = (value * cache[s_tmps[i].size()] % k + value_string[i]) % k;
        //7 + 008이라고 가정하면
        //value * cache[s_tmps[i].size()]는 (7 * (1000 % k))
        //+ value_string[i]는 8

        dp[status][value] += dp_park(next_value, status | (1 << i));
    }

    return dp[status][value];
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (ll i = 0; i < n; i++)
        cin >> s_tmps[i];
    cin >> k;
    for (int i = 0; i < (1 << n); i++)
    {
        for (int j = 0; j < k; j++)
        {
            dp[i][j] = -1;
        }
    }
    cache[0] = 1 % k;
    for (int i = 1; i < 51; i++)
        cache[i] = (cache[i - 1] * 10) % k;
    for (int i = 0; i < n; i++)
        value_string[i] = stringToValue(s_tmps[i]);
    // 집합의 모든 원소를 사용, 나머지가 0인 경우의 수 cnt
    // 전체 경우의 수(펙토리얼) all_cnt
    ll all_cnt = 1, cnt = dp_park(0, 0);
    for (int i = 1; i <= n; i++)
        all_cnt *= i;
    //최대 공약수
    ll gcd = GCD(cnt, all_cnt);
    cout << cnt / gcd << '/' << all_cnt / gcd;
    return 0;
}