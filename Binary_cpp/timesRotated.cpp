#include <bits/stdc++.h>
using namespace std;

int main()
{

    int m;
    cout << "the val of m:";
    cin >> m;

    int arr[m] = {0};
    for (int i = 0; i < m; i++)
    {
        cin >> arr[i];
    }

    int rotate = 0;

    // brute-->

    /*  for (int i = 0; i < m - 1; i++)
      {
          if (arr[i] > arr[i + 1])
          {
              rotate = i + 1;
              break;
          }
      }

      if (rotate == 0)
          cout << "no rotation";
      else
          cout << rotate;
          */

    // optimal --->

    int l = 0;
    int h = m - 1;
    int idx = -1;
    int ans = INT_MAX;
    while (l <= h)
    {

        int mid = (l + h) / 2;

        if (arr[l] == arr[mid] && arr[mid] == arr[h])
        {
            l++;
            h--;
            continue;
        }

        if (arr[l] < arr[h])
        {
            ans = min(ans, arr[l]);
            if (arr[l] == ans)
            {
                idx = l;
            }
            break;
        }

        if (arr[mid] < arr[h])
        {
            ans = min(ans, arr[mid]);
            if (arr[mid] == ans)
            {
                idx = mid;
            }
            h = mid - 1;
        }
        else
        {
            ans = min(arr[l], ans);
            if (arr[l] == ans)
            {
                idx = l;
            }
            l = mid + 1;
        }
    }

    cout << idx;

    return 0;
}
