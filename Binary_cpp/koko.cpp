#include <bits/stdc++.h>
using namespace std;

int hours(vector<int> &piles, int x)
{
    int thr = 0;
    for (int i = 0; i < piles.size(); i++)
    {
        if (piles[i] % x == 0)
            thr = thr + (piles[i]) / x;
        else
            thr = thr + (piles[i] / x + 1);
    }
    return thr;
}

int main()
{

    int hr;
    cout << "the hrs min:";
    cin >> hr;

    int n;
    cout << "the val of n:";
    cin >> n;

    vector<int> piles(n);

    for (int i = 0; i < n; i++)
    {
        cin >> piles[i];
    }

    // bnana / hr eat  -->

    int maxK = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (piles[i] > maxK)
            maxK = piles[i];
    }

    int k = maxK;

    // brute -->

    /* for (int i = maxK; i > 0; i--)
     { // 1 st loop-- eat bnana with max eat per hr than dec by time -1 bnana
         // check min bnana  -- eat / hr so eat all piles bunch in time limit
         int thr = 0;
         for (int j = 0; j < n; j++)
         {
             if (piles[j] % i == 0)
                 thr = thr + (piles[j]) / i;
             else
                 thr = thr + (piles[j] / i + 1);
         }
         if (thr > hr)
             break;
         else
         {
             k = min(k, i);
         }
     }

     cout << k;
     */

    // optimal -->

    int l = 1;
    int h = maxK;

    while (l <= h)
    {
        int mid = (l + h) / 2;
        int thr = hours(piles, mid);

        if (thr > hr)
            l = mid + 1;
        else
        {
            k = min(k, mid);
            h = mid - 1;
        }
    }

    cout << k;

    return 0;
}