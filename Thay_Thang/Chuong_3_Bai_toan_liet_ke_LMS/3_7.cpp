#include <iostream>
#include <vector>
using namespace std;

int m, n;
int X[100], a[100];
vector<vector<int>> ans;
void init()
{
    cin >> m >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
}

void backtracking(int j)
{
    for (int i = 0; i <= 1; ++i)
    {
        X[j] = i;
        if (j == n)
        {
            int s = 0;
            for (int k = 1; k <= n; ++k)
            {
                if (X[k] == 1)
                    s += a[k];
            }
            if (s == m)
            {
                vector<int> tmp;
                for (int k = 1; k <= n; ++k)
                {
                    if (X[k])
                        tmp.push_back(a[k]);
                }
                ans.push_back(tmp);
            }
        }
        else
            backtracking(j + 1);
    }
}

int main()
{
    init();
    backtracking(1);
    for (int i = 0; i < ans.size(); ++i)
    {
        for (int j = 0; j < ans[i].size(); ++j)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}