#include <iostream>
using namespace std;

int n, m, k, a[100], ok = 1;

int check1()
{
    int cnt = 0;
    for (int i = k; i <= n; ++i)
    {
        int check = 1;
        for (int j = 0; j < k; ++j)
        {
            if (a[i - j] == 1)
                check = 0;
        }
        if (check)
            ++cnt;
    }
    return cnt == 1;
}

int check2()
{
    int cnt = 0;
    for (int i = m; i <= n; ++i)
    {
        int check = 1;
        for (int j = 0; j < m; ++j)
        {
            if (a[i - j] == 0)
                check = 0;
        }
        if (check)
            ++cnt;
    }
    return cnt == 1;
}

void init()
{
    for (int i = 1; i <= n; ++i)
    {
        a[i] = 0;
    }
}

void print()
{
    for (int i = 1; i <= n; ++i)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

void brute_force()
{
    int i = n;
    while (i > 0 && a[i] == 1)
    {
        a[i] = 0;
        --i;
    }
    if (i == 0)
        ok = 0;
    else
        a[i] = 1;
}

int main()
{
    cin >> k >> m >> n;
    init();
    while (ok)
    {
        if (check1() && check2())
            print();
        brute_force();
    }
    return 0;
}