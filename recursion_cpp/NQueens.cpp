#include <bits/stdc++.h>
using namespace std;

bool Safe(int row, int clm, vector<string> &ls, int n)
{

    int r = row;
    int c = clm;

    while (row >= 0 && clm >= 0)
    {
        if (ls[row][clm] == 'Q')
            return false;
        clm--;
        row--;
    }

    row = r;
    clm = c;

    while (clm >= 0)
    {
        if (ls[row][clm] == 'Q')
            return false;
        clm--;
    }

    clm = c;

    while ((row < n && clm >= 0))
    {
        if (ls[row][clm] == 'Q')
            return false;
        row++;
        clm--;
    }

    return true;
}

void Queens(int clm, vector<string> &ls, vector<vector<string>> &ans, int n)
{

    if (clm == n)
    {
        ans.push_back(ls);
        return;
    }

    for (int row = 0; row < n; row++)
    {
        if (Safe(row, clm, ls, n))
        {
            ls[row][clm] = 'Q';
            Queens(clm + 1, ls, ans, n);
            ls[row][clm] = '.';
        }
    }
}

int main()
{

    int n;
    cout << "teh val of n:";
    cin >> n;

    // int m;
    // cout << "the val of m:";
    // cin >> m;

    // vector<int> arr(m);

    // for (int i = 0; i < m; i++)
    // {
    //     cin >> arr[i];
    // }

    vector<vector<string>> ans;
    vector<string> ls(n);
    string s(n, '.');

    for (int i = 0; i < n; i++)
    {
        ls[i] = s;
    }

    Queens(0, ls, ans, n);

    if (ans.empty())
    {
        cout << "No soln";
        return 0;
    }

    for (auto it : ans)
    {
        for (auto x : it)
        {
            cout << x << endl;
        }
        cout << endl;
    }
    return 0;
}