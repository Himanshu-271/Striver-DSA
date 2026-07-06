#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cout << "rows n:";
    cin >> n;

    cout << "clms m:";
    cin >> m;

    int arr[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    // brute -->

    /* int rowNo = -1;
     int max1s = INT_MIN;

     for (int i = 0; i < n; i++)
     {
         int cnt = 0;
         for (int j = 0; j < m; j++)
         {
             if (arr[i][j] == 1)
             {
                 cnt++;
             }
         }

         if (max1s < cnt)
         {
             max1s = cnt;
             rowNo = i;
         }
     }

     cout << rowNo;
     */

    // optimal -->

    int max1s = INT_MIN;
    int rowNo = -1;

    for (int i = 0; i < n; i++)
    {
        int l = 0;
        int h = m - 1;
        int idx = -1;
        int cnt = 0;

        // Bs for first occ of 1-->

        while (l <= h)
        {
            int mid = l + (h - l) / 2;

            if (arr[i][mid] == 0)
            {
                l = mid + 1;
            }
            else
            {
                idx = mid;
                h = mid - 1;
            }
        }

        // count no of 1s-->

        cnt = m - idx;

        if (cnt > max1s)
        {
            max1s = cnt;
            rowNo = i;
        }
    }

    cout << rowNo;

    return 0;
}