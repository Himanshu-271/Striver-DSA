#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "the val of n:";
    cin >> n;

    // brute -->

    int ans;

    /*  for (int i = 1; i < n; i++)
      {
          if (i * i == n)
          {
              ans = i;
              break;
          }

          else if (i * i < n)
              continue;

          else
          {
              ans = i - 1;
              break;
          }
      }

      cout << ans;
      */

    // optimal -->

    // when to search no b/w fix no.s like eg 1-->n
    // need max , min val  use binary search;

    int l = 0;
    int h = n;
    while (l <= h)
    {
        long long mid = (l + h) / 2;

        if (mid * mid > n)
            h = mid - 1;

        else if (mid * mid < n)
        {
            ans = mid;
            l = mid + 1;
        }

        else
        {
            ans = mid;
            break;
        }
    }

    cout << ans;

    return 0;
}
