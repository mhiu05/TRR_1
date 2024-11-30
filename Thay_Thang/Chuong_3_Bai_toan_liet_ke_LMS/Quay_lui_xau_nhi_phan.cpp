#include <iostream>
using namespace std;

int a[100], n;

void print()
{
    for (int i = 1; i <= n; ++i)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

void backtracking(int j)
{
    for (int i = 0; i <= 1; ++i)
    {
        a[j] = i;
        if (j == n)
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
    cin >> n;
    backtracking(1);
}