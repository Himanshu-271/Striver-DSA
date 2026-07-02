#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "the val of n:";
    cin >> n;
    int arr[n] = {0};

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // brute--->

    if (n == 1)
        return arr[n];

    /*  int j = -1;

      for (int i = 0; i < n; i++)
      {
          if (i == 0)
          {
              if (arr[i] != arr[i + 1])
              {
                  j = i;
              }
          }
          else if (i > 0 && i < n - 1)
          {
              if (arr[i - 1] != arr[i] && arr[i] != arr[i + 1])
              {
                  j = i;
                  break;
              }
          }
          else
          {
              j = i;
          }
      }
      if (j == -1)
          cout << "not found";
      else
          cout << arr[j];
          */

    // optimal -->

    int l = 1;
    int h = n - 2;
    int j = -1;

    int flag = 0;

    // edge cases --

    if (arr[0] != arr[1])
    {
        j = 0;
        flag = 1;
    }
    if (arr[n - 1] != arr[n - 2])
    {
        j = n - 1;
        flag = 1;
    }

    if (flag == 0)
    {
        while (l <= h)
        {
            int mid = (l + h) / 2;

            if (arr[mid - 1] != arr[mid] && arr[mid] != arr[mid + 1])
            {
                j = mid;
                flag = 1;
                break;
            }

            if (mid % 2 == 0)
            {
                if (arr[mid] == arr[mid + 1])
                {
                    l = mid + 1;
                }
                else
                    h = mid - 1;
            }
            else
            {
                if (arr[mid] == arr[mid + 1])
                {
                    h = mid - 1;
                }
                else
                    l = mid + 1;
            }
        }
    }

    cout << arr[j];

    return 0;
}