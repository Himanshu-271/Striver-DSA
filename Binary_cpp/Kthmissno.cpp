#include <bits/stdc++.h>
using namespace std;

int main()
{

    int k;
    cout << " miss no kth:";
    cin >> k;

    int n;
    cout << "the val of n:";
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // brute-->

    /*  int cnt = 0;
      int ans = -1;
      int x = *max_element(arr.begin(), arr.end());

      for (int i = 0; i < n; i++)
      {
          if (arr[i] <= k)
              k++;
          else
              break;
      }
      ans = k;
      cout << ans;
      */

    // optimal -->

    int idx1 = -1;
    int idx2 = -1;
    int l = 0;
    int h = n - 1;
    int misselm = -1;

    while (l <= h)
    {
        int mid = (l + h) / 2;

        int missnos = arr[mid] - mid - 1;

        if (k > missnos)
        {
            idx1 = mid;
            l = mid + 1;
        }
        else
        {
            idx2 = mid;
            h = mid - 1;
        }
    }

    //  lies b/w-->
    //  cout << idx1 << " " << idx2;

    if (idx1 == -1)
    {
        misselm = k;
    }

    else
    {

        int miss = arr[idx1] - idx1 - 1;

        misselm = arr[idx1] + (k - miss);
    }

    cout << misselm;

    return 0;
}