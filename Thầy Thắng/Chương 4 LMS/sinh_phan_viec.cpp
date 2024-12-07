#include <iostream>
#include <iomanip>
#include <algorithm>
#include <map>

using namespace std;

int X[100], n, ok = 1;
int a[100][100];
int min_time = 1e9;
map<int, int> ans;

void init()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        X[i] = i;
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cin >> a[i][j];
        }
    }
}

void brute_force()
{
    int i = n - 1;
    while (i > 0)
    {
        if (X[i] < X[i + 1])
            break;
        else
            --i;
    }
    if (i == 0)
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

void calculate_min_time()
{
    int sum_of_time = 0;
    for (int i = 1; i <= n; ++i)
    {
        sum_of_time += a[i][X[i]];
    }
    min_time = min(sum_of_time, min_time);
}

void find_min_time()
{
    while (ok)
    {
        calculate_min_time();
        brute_force();
    }
}

void solve()
{
    int sum_of_time = 0;
    for (int i = 1; i <= n; ++i)
    {
        sum_of_time += a[i][X[i]];
    }
    if (sum_of_time == min_time)
    {
        for (int i = 1; i <= n; ++i)
        {
            ans[i] = X[i];
        }
        for (auto it : ans)
        {
            cout << "Man" << it.first << "->"
                                         "Job"
                 << it.second << "||";
        }
        cout << endl;
    }
}

int main()
{
    init();
    find_min_time();

    ok = 1;
    for (int i = 1; i <= n; ++i)
    {
        X[i] = i;
    }

    while (ok)
    {
        solve();
        brute_force();
    }
    return 0;
}