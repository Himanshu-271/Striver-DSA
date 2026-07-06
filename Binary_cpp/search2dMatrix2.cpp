#include <bits/stdc++.h>
using namespace std;

pair<int, int> FindTarget(vector<vector<int>> &arr, int k)
{
    pair<int, int> idx;

    int n = arr.size();
    int m = arr[0].size();

    if (arr.empty() || arr[0].empty())
        return {-1, -1};

    // optimal soln -->
    //  row and clm sorted matrix-->
    // idea row-clm in L shape fully sort so start corner check and remove clm or row ;

    int row = n - 1;
    int clm = 0;

    while (row >= 0 && clm < m)
    {
        if (arr[row][clm] > k)
        {
            row--;
        }
        else if (arr[row][clm] < k)
        {
            clm++;
        }
        else
            idx = {row, clm};
    }
    return idx;
}

int main()
{
    int k;
    cout << "target k:";
    cin >> k;

    int n, m;
    cout << "rows n:";
    cin >> n;

    cout << "clms m:";
    cin >> m;

    vector<vector<int>> arr(n, vector<int>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    pair<int, int> ans = FindTarget(arr, k);

    cout << ans.first << " " << ans.second;
    return 0;
}