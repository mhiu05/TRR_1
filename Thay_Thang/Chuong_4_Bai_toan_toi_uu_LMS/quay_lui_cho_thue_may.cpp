#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int n, m, max_ans = 0;
int a[100][100], X[100];
vector<vector<int>> v;

void init()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            cin >> a[i][j];
        }
    }
}

void check_solution()
{
    int cnt = 0;
    int cot[100] = {0};

    for (int i = 1; i <= n; ++i)
    {
        if (X[i])
        {
            for (int j = 1; j <= m; ++j)
            {
                if (a[i][j] && cot[j])
                {
                    return;
                }
                if (a[i][j])
                {
                    cot[j] = 1;
                }
            }
        }
    }

    for (int i = 1; i <= m; ++i)
    {
        if (cot[i])
            ++cnt;
    }

    if (cnt > max_ans)
    {
        max_ans = cnt;
        v.clear();
        vector<int> tmp;
        for (int k = 1; k <= n; ++k)
        {
            tmp.push_back(X[k]);
        }
        v.push_back(tmp);
    }
    else if (cnt == max_ans)
    {
        vector<int> tmp;
        for (int k = 1; k <= n; ++k)
        {
            tmp.push_back(X[k]);
        }
        v.push_back(tmp);
    }
}

void backtracking(int i)
{
    if (i > n)
    {
        check_solution();
        return;
    }

    X[i] = 0;
    backtracking(i + 1);

    X[i] = 1;
    backtracking(i + 1);
}

void print()
{
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    init();
    backtracking(1);
    print();
}