#include <iostream>
using namespace std;

int a[100], k, n;

void print()
{
    for (int i = 1; i <= k; ++i)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

void backtracking(int j)
{
    for (int i = a[j - 1] + 1; i <= n - k + j; ++i)
    {
        a[j] = i;
        if (j == k)
        {
            print();
        }
        else
        {
            backtracking(j + 1);
        }
    }
}

int main()
{
    cin >> k >> n;
    backtracking(1);
}