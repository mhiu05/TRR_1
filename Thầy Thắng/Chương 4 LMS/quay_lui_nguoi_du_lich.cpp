#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

int n, a[50][50];
int X[50];
int visited[50];
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
}

void solve()
{
    int tmp = 0;
    tmp += a[1][X[2]];
    for (int i = 3; i <= n; ++i)
    {
        tmp += a[X[i - 1]][X[i]];
    }
    tmp += a[X[n]][1];
    if (tmp < fopt)
    {
        fopt = tmp;
        for (int i = 2; i <= n; ++i)
        {
            Xopt[i] = X[i];
        }
    }
}

void backtracking(int i)
{
    for (int j = 2; j <= n; ++j)
    {
        if (!visited[j])
        {
            visited[j] = 1;
            X[i] = j;
            if (i == n)
            {
                solve();
            }
            else
            {
                backtracking(i + 1);
            }
            visited[j] = 0;
        }
    }
}

int main()
{
    init();
    backtracking(2);
    cout << fixed << setprecision(1) << 1.0 * fopt << endl;
    cout << 1 << " ";
    for (int i = 2; i <= n; ++i)
    {
        cout << Xopt[i] << " ";
    }
    cout << 1;
    return 0;
}
