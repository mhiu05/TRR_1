#include <iostream>
using namespace std;

int n, k, a[100], ok = 1;

void init()
{
    for (int i = 1; i <= k; ++i)
    {
        a[i] = i;
    }
}

void print()
{
    for (int i = 1; i <= k; ++i)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

void brute_force()
{
    int i = k;
    while (i > 0 && a[i] == n - k + i)
        --i;
    if (i == 0)
        ok = 0;
    else
    {
        a[i]++;
        for (int j = i + 1; j <= k; ++j)
        {
            a[j] = a[j - 1] + 1;
        }
    }
}

int main()
{
    cin >> k >> n;
    init();
    while (ok)
    {
        print();
        brute_force();
    }
    return 0;
}