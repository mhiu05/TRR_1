#include <iostream>
using namespace std;

int n, a[100], xuoi[100], nguoc[100], cot[100];

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
        if (!cot[i] && !xuoi[j - i + n] && !nguoc[i + j - 1])
        {
            a[j] = i;
            cot[i] = 1;
            xuoi[j - i + n] = 1;
            nguoc[i + j - 1] = 1;
            if (j == n)
            {
                print();
            }
            else
                backtracking(j + 1);
            cot[i] = 0;
            xuoi[j - i + n] = 0;
            nguoc[i + j - 1] = 0;
        }
    }
}

int main()
{
    cin >> n;
    backtracking(1);
    return 0;
}