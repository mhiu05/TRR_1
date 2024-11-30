#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <vector>
using namespace std;

int n, m, max_ans = 0, ok = 1;
int X[100], a[100][100];
vector<vector<int>> v;

void init()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        X[i] = 0;
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            cin >> a[i][j];
        }
    }
}

void brute_force()
{
    int i = n;
    while (i > 0 && X[i] == 1)
    {
        X[i] = 0;
        --i;
    }
    if (i == 0)
        ok = 0;
    else
    {
        X[i] = 1;
    }
}

void find_max_ans()
{
    int cnt = 0;
    int cot[100] = {0};
    for (int i = 1; i <= n; ++i)
    {
        if (X[i])
        {
            for (int j = 1; j <= m; ++j)
            {
                if (a[i][j] && cot[j])
                {
                    return;
                }
                if (a[i][j])
                {
                    cot[j] = 1;
                }
            }
        }
    }
    for (int i = 1; i <= m; ++i)
    {
        if (cot[i])
            ++cnt;
    }
    max_ans = max(max_ans, cnt);
}

void for_loop()
{
    while (ok)
    {
        find_max_ans();
        brute_force();
    }
}

void solve_main_problem()
{
    int cnt = 0;
    int cot[100] = {0};
    for (int i = 1; i <= n; ++i)
    {
        if (X[i])
        {
            for (int j = 1; j <= m; ++j)
            {
                if (a[i][j] && cot[j])
                {
                    return;
                }
                if (a[i][j])
                {
                    cot[j] = 1;
                }
            }
        }
    }
    for (int i = 1; i <= m; ++i)
    {
        if (cot[i])
            ++cnt;
    }
    if (cnt == max_ans)
    {
        vector<int> tmp(n + 5);
        for (int i = 1; i <= n; ++i)
        {
            tmp[i] = X[i];
        }
        v.push_back(tmp);
    }
}

void solve()
{
    for (int i = 1; i <= n; ++i)
    {
        X[i] = 0;
    }
    ok = 1;
    while (ok)
    {
        solve_main_problem();
        brute_force();
    }
}

void print()
{
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    init();
    for_loop();
    solve();
    print();
    return 0;
}