#include <iostream>
#include <iomanip>
#include <map>
#include <vector>

using namespace std;

int X[100], n;
int a[100][100];
int min_time = 1e9;
vector<vector<int>> v;
bool used[100] = {false};

void init()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cin >> a[i][j];
        }
    }
}

void calculate_min_time()
{
    int sum_of_time = 0;
    for (int i = 1; i <= n; ++i)
    {
        sum_of_time += a[i][X[i]];
    }
    if (sum_of_time < min_time)
    {
        min_time = sum_of_time;
        v.clear();
        v.push_back(vector<int>(X + 1, X + n + 1));
    }
    else if (sum_of_time == min_time)
    {
        v.push_back(vector<int>(X + 1, X + n + 1));
    }
}

void backtracking(int k)
{
    if (k > n)
    {
        calculate_min_time();
        return;
    }
    for (int j = 1; j <= n; ++j)
    {
        if (!used[j])
        {
            X[k] = j;
            used[j] = true;
            backtracking(k + 1);
            used[j] = false;
        }
    }
}

void print()
{
    for (auto x : v)
    {
        for (int i = 1; i <= n; ++i)
        {
            cout << "Man" << i << ">Job" << x[i - 1] << "||";
        }
        cout << endl;
    }
}

int main()
{
    init();
    backtracking(1);
    print();
    return 0;
}