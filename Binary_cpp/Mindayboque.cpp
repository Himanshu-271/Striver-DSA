#include <bits/stdc++.h>
using namespace std;

int fxn(vector<int> &bloomday, int y, int k, int z)
{
    if (k * z > bloomday.size())
        return -1;
    int cnt = 0;
    int m = 0;
    for (int i = 0; i < bloomday.size(); i++)
    {
        if (bloomday[i] <= y)
            cnt++;
        else
        {
            if (cnt >= k)
            {
                m = m + cnt / k;
            }
            cnt = 0;
            continue;
        }
    }
    m = m + cnt / k;
    return m;
}

int main()
{
    int boques;
    cout << "the boques:";
    cin >> boques;

    int k;
    cout << "adjesent flower k:";
    cin >> k;

    int n;
    cout << "the val of n:";
    cin >> n;

    vector<int> bloomday(n);

    for (int i = 0; i < n; i++)
    {
        cin >> bloomday[i];
    }

    // int flag = 0;
    // if (boques * k > n)
    // {
    //     cout << -1;
    //     flag = 1;
    // }

    int maxDay = *max_element(bloomday.begin(), bloomday.end());
    int minDay = *min_element(bloomday.begin(), bloomday.end());

    // brute --->

    /* int days = maxDay;

     if (flag == 0)
     {

         for (int i = minDay; i <= maxDay; i++)
         {
             int cnt = 0;
             int m = 0;
             for (int j = 0; j < n; j++)
             {
                 if (bloomday[j] <= i)
                 {
                     cnt++;
                 }
                 else
                 {
                     if (cnt >= k)
                     {
                         m = m + cnt / k;
                     }
                     cnt = 0;
                     continue;
                 }
             }

             m = m + cnt / k;

             if (m >= boques)
             {
                 days = i;
                 break;
             }
         }

         cout << days;
     }
         */

    // optimal --->

    int l = minDay;
    int h = maxDay;
    int days = maxDay;

    while (l <= h)
    {
        int mid = (l + h) / 2;
        int x = fxn(bloomday, mid, k, boques);
        if (x == -1)
        {
            days = -1;
            break;
        }
        else if (x >= boques)
        {
            days = mid;
            h = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }

    cout << days;

    return 0;
}