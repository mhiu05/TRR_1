#include <iostream>
using namespace std;

int a[100], n, k, ok = 1;

int check_only_one_array_k_bit_1()
{
    int cnt = 0;
    for (int i = k; i <= n; ++i)
    {
        int check = 1;
        for (int j = 0; j < k; ++j)
        {
            if (a[i - j] == 0)
            {
                check = 0;
            }
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
    cin >> k >> n;
    init();
    while (ok)
    {
        if (check_only_one_array_k_bit_1())
            print();
        brute_force();
    }
    return 0;
}
