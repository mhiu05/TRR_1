#include <iostream>
using namespace std;

int n, a[100];
int check[100];

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
    for (int i = 1; i <= n; ++i)
    {
        if (!check[i])
        {
            check[i] = 1;
            a[j] = i;
            if (j == n)
                print();
            else
                backtracking(j + 1);
            check[i] = 0;
        }
    }
}

int main()
{
    cin >> n;
    backtracking(1);
    return 0;
}