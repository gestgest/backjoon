#include <iostream>
#include <string>
using namespace std;

int main ()
{
    string number;
    int n;
    int sum = 0;
    cin >> n;
    cin >> number;
    for(int i = 0; i < n; i++)
    {
        sum += (int)number[i]-48;
    }
    cout<<sum<<endl;
}