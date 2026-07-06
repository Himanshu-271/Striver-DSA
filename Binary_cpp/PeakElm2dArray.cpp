#include <bits/stdc++.h>
using namespace std;

int main()
{
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

    // optimal --->

    pair<int, int> ans = {-1, -1};

    int flag = 0;

    // edge case

    if (m == 1)
    {

        int maxi = INT_MIN;
        int row = -1;

        for (int i = 0; i < n; i++)
        {
            if (maxi < arr[i][0])
            {
                maxi = arr[i][0];
                row = i;
            }
        }
        ans = {row, 0};
        flag = 1;
        cout << ans.first << "," << ans.second;
    }

    // BS on Clms-->

    int l = 0;
    int h = m - 1;

    if (flag == 0)
    {
        while (l <= h)
        {
            int mid = l + (h - l) / 2;

            // find max of that clm  and in which row it is-->
            // after max find we only need to check left or it's right only-->

            int maxi = INT_MIN;
            int row = -1;

            for (int i = 0; i < n; i++)
            {
                if (maxi < arr[i][mid])
                {
                    maxi = arr[i][mid];
                    row = i;
                }
            }

            // edge cases-->

            if (mid == 0)
            {
                if (maxi > arr[row][mid + 1])
                {
                    ans = {row, mid};
                    break;
                }
            }

            else if (mid == m - 1)
            {
                if (maxi > arr[row][mid - 1])
                {
                    ans = {row, mid};
                    break;
                }
            }

            else
            {
                if (maxi > arr[row][mid + 1] && maxi > arr[row][mid - 1])
                {
                    ans = {row, mid};
                    break;
                }

                else if (maxi < arr[row][mid - 1])
                    h = mid - 1;

                else
                    l = mid + 1;
            }
        }

        cout << ans.first << "," << ans.second;
    }

    return 0;
}