#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

int n, a[50][50], ok = 1;
int X[50];
int fopt = 1e9, Xopt[50];

void init()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        X[i] = i;
    }
}

void brute_force()
{
    int i = n - 1;
    while (i > 1)
    {
        if (X[i] < X[i + 1])
            break;
        else
            --i;
    }
    if (i == 1)
        ok = 0;
    else
    {
        int j = n;
        while (j > i)
        {
            if (X[j] > X[i])
                break;
            else
                --j;
        }
        swap(X[i], X[j]);
        reverse(X + i + 1, X + n + 1);
    }
}

void solve()
{
    int tmp = 0;
    for (int i = 2; i <= n; ++i)
    {
        tmp += a[X[i - 1]][X[i]];
    }
    tmp += a[X[n]][1];
    if (tmp < fopt)
    {
        fopt = tmp;
        for (int i = 1; i <= n; ++i)
        {
            Xopt[i] = X[i];
        }
    }
}

int main()
{
    init();
    while (ok)
    {
        solve();
        brute_force();
    }
    cout << fixed << setprecision(1) << 1.0 * fopt << endl;
    for (int i = 1; i <= n; ++i)
    {
        cout << Xopt[i] << " ";
    }
    cout << 1 << " ";
    return 0;
}