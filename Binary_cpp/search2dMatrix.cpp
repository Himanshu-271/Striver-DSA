#include <bits/stdc++.h>
using namespace std;

bool FindTarget(vector<vector<int>> &arr, int k)
{

    int n = arr.size();
    int m = arr[0].size();

    if (arr.empty() || arr[0].empty())
        return false;

    // brute -->

    /* for (int i = 0; i < n; i++)
     {
         for (int j = 0; j < m; j++)
         {
             if (arr[i][j] == k)
                 return true;
         }
     }
     return false;
     */

    // better-->

    /* for (int i = 0; i < n; i++)
     {
         if (arr[i][0] <= k && k <= arr[i][m - 1])
         {
             int l = 0;
             int h = m - 1;

             while (l <= h)
             {
                 int mid = l + (h - l) / 2;

                 if (arr[i][mid] < k)
                     l = mid + 1;
                 else if (arr[i][mid] > k)
                     h = mid - 1;
                 else
                     return true;
             }
         }
     }
     return false;*/

    // optimal BS -->
    // whole matrix sorted
    // asuume flat the 2 d matrix -- in 1 d array hypoth.
    //----> approch-- indx 1d convert in 2d :row no = 1d-idx/colm no ; clm no = 1d-idx % colm no;

    int l = 0;
    int h = n * m - 1;

    while (l <= h)
    {
        int mid = l + (h - l) / 2;

        int row = mid / m;
        int clm = mid % m;

        if (arr[row][clm] < k)
            l = mid + 1;

        else if (arr[row][clm] > k)
            h = mid - 1;

        else
            return true;
    }
    return false;
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

    cout << FindTarget(arr, k);

    return 0;
}