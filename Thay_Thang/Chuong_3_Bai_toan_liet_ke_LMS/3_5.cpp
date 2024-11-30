#include <bits/stdc++.h>
using namespace std;

char a[100];
int m, n, ok = 1;

int check()
{
    int cnt = 0;
    for (int i = m; i <= n; ++i)
    {
        int check = 1;
        for (int j = 0; j < m; ++j)
        {
            if (a[i - j] == 'B')
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
        a[i] = 'B';
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
    while (i > 0 && a[i] == 'A')
    {
        a[i] = 'B';
        --i;
    }
    if (i == 0)
        ok = 0;
    else
        a[i] = 'A';
}

int main()
{
    cin >> m >> n;
    init();
    while (ok)
    {
        if (check())
            print();
        brute_force();
    }
    return 0;
}
