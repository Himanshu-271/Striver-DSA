#include <bits/stdc++.h>
using namespace std;

int CountElms(vector<vector<int>> &arr, int y)
{

    int cnt = 0;
    int n = arr.size();
    int m = arr[0].size();

    for (int i = 0; i < n; i++)
    {

        int l = 0;
        int h = m - 1;
        int idx = m;

        while (l <= h)
        {
            int mid = l + (h - l) / 2;

            if (arr[i][mid] <= y)
                l = mid + 1;

            else
            {
                idx = mid;
                h = mid - 1;
            }
        }

        cnt += (idx);
    }

    return cnt;
}

int main()
{
    int n, m;
    cout << "rows:";
    cin >> n;

    cout << "clms:";
    cin >> m;

    vector<vector<int>> arr(n, vector<int>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    // brute-->

    // store array -->

    /*  vector<int> hs;

      for (int i = 0; i < n; i++)
      {
          for (int j = 0; j < m; j++)
          {
              hs.push_back(arr[i][j]);
          }
      }

      sort(hs.begin(), hs.end());

      int median = -1;

      median = hs[hs.size() / 2];

      cout << median;
      */

    // optimal -->
    // BS--->

    int mini = INT_MAX;
    int maxi = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        if (arr[i][0] < mini)
            mini = arr[i][0];

        if (arr[i][m - 1] > maxi)
            maxi = arr[i][m - 1];
    }

    int l = mini;
    int h = maxi;

    int median = n * m / 2;
    int ans = -1;

    while (l <= h)
    {

        int mid = l + (h - l) / 2;

        int x = CountElms(arr, mid);

        if (x <= median)
            l = mid + 1;

        else
        {
            ans = mid;
            h = mid - 1;
        }
    }

    cout << ans;

    return 0;
}
