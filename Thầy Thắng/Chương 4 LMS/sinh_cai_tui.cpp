#include <iostream>
#include <iomanip>
using namespace std;

int X[100], arr[100], ok = 1;
int max_ans = -1e9;
int n, b;
int f[100], g[100], ans[100];

void init()
{
    cin >> n >> b;
    for (int i = 1; i <= n; ++i)
    {
        cin >> g[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        cin >> f[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        arr[i] = 0;
    }
}

void brute_force()
{
    int i = n;
    while (i > 0 && arr[i] == 1)
    {
        arr[i] = 0;
        --i;
    }
    if (i == 0)
        ok = 0;
    else
    {
        arr[i] = 1;
        int tmp1 = 0;
        for (int i = 1; i <= n; ++i)
        {
            tmp1 += arr[i] * g[i];
        }
        if (tmp1 <= b)
        {
            int tmp2 = 0;
            for (int i = 1; i <= n; ++i)
            {
                tmp2 += arr[i] * f[i];
            }
            if (tmp2 > max_ans)
            {
                max_ans = tmp2;
                for (int i = 1; i <= n; ++i)
                {
                    ans[i] = arr[i];
                }
            }
        }
    }
}

int main()
{
    init();
    while (ok)
    {
        brute_force();
    }
    cout << fixed << setprecision(1) << 1.0 * max_ans << endl;
    for (int i = 1; i <= n; ++i)
    {
        cout << ans[i] << " ";
    }
    return 0;
}