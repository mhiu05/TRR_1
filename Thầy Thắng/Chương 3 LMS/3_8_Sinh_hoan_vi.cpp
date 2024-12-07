#include <iostream>
#include <algorithm>
using namespace std;

int n, a[100], ok = 1;

void init()
{
    for (int i = 1; i <= n; ++i)
    {
        a[i] = i;
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
    int i = n - 1;
    while (i > 0)
    {
        if (a[i] < a[i + 1])
            break;
        --i;
    }
    if (i == 0)
        ok = 0;
    else
    {
        int j = n;
        while (a[i] > a[j])
            --j;
        swap(a[i], a[j]);
        reverse(a + i + 1, a + n + 1);
    }
}

int main()
{
    cin >> n;
    init();
    while (ok)
    {
        print();
        brute_force();
    }
    return 0;
}