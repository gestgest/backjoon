#include <string>
#include <vector>

using namespace std;

//v[0]이 더 커야함
void swap_wallet(vector<int> & v)
{
    if(v[0] < v[1])
    {
        int tmp = v[0];
        v[0] = v[1];
        v[1] = tmp;
    }
}

bool isCheck(vector<int> & a, vector<int> & b)
{
    if(a[0] > b[0])
    {
        return false;
    }
    if(a[1] > b[1])
    {
        return false;
    }
    return true;
}

//사이즈는 2
//지폐, bill {가로세로}
int solution(vector<int> wallet, vector<int> bill)  //
{
    swap_wallet(wallet);
    swap_wallet(bill);
    int answer = 0;
    
    while(true)
    {
        if(isCheck(bill, wallet))
        {
            break;
        }
        answer++;
        bill[0] /= 2;
        swap_wallet(bill);
    }
    
    return answer;
}