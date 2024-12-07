#include <iostream>
#include <iomanip>
using namespace std;

int X[100];
int m, n;
int f[100], g[100];
int fopt = -1e9, Xopt[100];

void init()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        cin >> g[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        cin >> f[i];
    }
}

void solve()
{
    int tmp1 = 0;
    for (int k = 1; k <= n; ++k)
    {
        tmp1 += X[k] * g[k];
    }
    if (tmp1 <= m)
    {
        int tmp2 = 0;
        for (int k = 1; k <= n; ++k)
        {
            tmp2 += X[k] * f[k];
        }
        if (tmp2 > fopt)
        {
            fopt = tmp2;
            for (int k = 1; k <= n; ++k)
            {
                Xopt[k] = X[k];
            }
        }
    }
}

void backtracking(int i)
{
    for (int j = 0; j <= 1; ++j)
    {
        X[i] = j;
        if (i == n)
        {
            solve();
        }
        else
        {
            backtracking(i + 1);
        }
    }
}

int main()
{
    init();
    backtracking(1);
    cout << fixed << setprecision(1) << 1.0 * fopt << endl;
    for (int i = 1; i <= n; ++i)
    {
        cout << Xopt[i] << " ";
    }
    return 0;
}