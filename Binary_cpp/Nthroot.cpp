#include <bits/stdc++.h>
using namespace std;

int fxn(int y, int m)
{

    if (m == 0)
        return 1;
    else
        return y * fxn(y, m - 1);
}

int main()
{
    int n, m;
    cout << "the val of n:";
    cin >> n;
    cout << "the val of m mth root:";
    cin >> m;

    // brute -->

    int ans = -1;

    /* for (int i = 1; i <= n; i++)
     {
         int x = fxn(i, m);

         if (x == n)
         {
             ans = i;
             break;
         }
         else if (x > n)
             break;
     }

     cout << ans;
     */

    // optimal soln -->

    int l = 1;
    int h = n;
    while (l <= h)
    {
        int mid = (l + h) / 2;
        int x = fxn(mid, m);

        if (x == n)
        {
            ans = mid;
            break;
        }
        else if (x > n)
            h = mid - 1;

        else
        {
            l = mid + 1;
        }
    }

    cout << ans;

    return 0;
}