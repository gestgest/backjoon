#include <iostream>
using namespace std;


//index, before은 전 숫자
void ppap(bool p[], int s[], int m, int n, int index, int before)
{
    if (n <= index + 1)
    {
        for (int i = 0; i < index; i++)
        {
            cout << s[i] <<" ";
        }
        cout << before + 1<<'\n';
    }
    else
    {
        int* copy_s = new int[n];
        bool* copy_p = new bool[m];
        for (int j = 0; j < n; j++)
            copy_s[j] = s[j];
        for (int j = 0; j < m; j++)
            copy_p[j] = p[j];
        
        copy_p[before] = true;
        copy_s[index] = before + 1;
        index++;

        for (int i = 0; i < m; i++)
        {
            if (!copy_p[i])
            {
                ppap(copy_p, copy_s, m, n, index, i);
            }
        }
        delete[] copy_s;
        delete[] copy_p;
    }
}

int main()
{
    int m, n, i, j;

    cin >> m >> n;

    int* s = new int[n];
    bool* p = new bool[m];
    for (int j = 0; j < n; j++)
        s[j] = 0;
    for (int j = 0; j < m; j++)
        p[j] = false;

    for (int i = 0; i < m; i++)
    {
        ppap(p ,s, m, n, 0, i);
    }

    delete[] s;

}