#include <iostream>
using namespace std;

typedef struct Data {
    int m;
    int n;
    int before;
    int index;
}Data;

void seq(Data data, int s[])
{
    if (data.index == data.n - 1)
    {
        s[data.index] = data.before;
        for (int i = 0; i < data.n; i++)
            cout << s[i] << " ";
        cout << '\n';
    }
    else
    {
        s[data.index++] = data.before;
        for (int i = 0; i < data.m - data.n + 1; i++)
        {
            if (data.before + 1 <= data.m)
            {
                data.before = data.before + 1;
                seq(data, s);
            }
        }

    }

}

int main()
{
    Data data;
    cin >> data.m >> data.n;
    int* s = new int [data.n];

    data.index = 0;
    for (int i = 1; i <= data.m - data.n + 1; i++)
    {
        data.before = i;
        seq(data, s);
    }

    delete[]s;
}