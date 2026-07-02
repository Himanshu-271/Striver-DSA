#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "the val of n:";
    cin >> n;
    int k;
    cout << "the val of k:";
    cin >> k;
    int arr[n] = {0};
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // brute+better -->

    /*  int cnt = 0;
      for (int i = 0; i < n; i++)
      {
          int xr = arr[i];
          if (xr == k)
              cnt++;
          for (int j = i + 1; j < n; j++)
          {
              xr = xr ^ arr[j];
              if (xr == k)
                  cnt++;
          }
      }
      if (cnt > 0)
          cout << cnt;
      else
          cout << " no sub array";
          */

    // optimal--->

    unordered_map<int, int> xr;
    int i = 0;
    int Xr = 0;
    int cnt = 0;
    xr[0] = 1;
    while (i < n)
    {
        int Xr = Xr ^ arr[i];
        int psXr = Xr ^ k;
        if (xr.find(psXr) != xr.end())
        {
            cnt = cnt + xr[psXr];
        }
        xr[Xr]++;
        i++;
    }
    if (cnt > 0)
        cout << cnt;
    else
        cout << " no sub array";

    return 0;
}