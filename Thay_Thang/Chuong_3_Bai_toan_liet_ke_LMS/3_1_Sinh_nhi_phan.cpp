#include <iostream>
using namespace std;

int n, a[100], ok = 1;

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
    cin >> n;
    init();
    while (ok)
    {
        print();
        brute_force();
    }
    return 0;
}