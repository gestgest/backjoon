#include <iostream>
#include <cmath>
using namespace std;

void hanoi(int n, int a, int b, int c)
{
    if (n == 1)
        cout << a << " " << c << '\n';
    else
    {
        hanoi(n - 1, a, c, b);
        cout << a << " " << c << '\n';
        hanoi(n - 1, b, a, c);
    }
}

int main()
{

    int n;
    int count;
    cin >> n;

    //count 값 출력
    count = pow(2,n) - 1;


    cout << count << '\n';
    hanoi(n, 1, 2, 3);


}