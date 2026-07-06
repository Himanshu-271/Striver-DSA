#include <bits/stdc++.h>
using namespace std;

int fxn(vector<int> &arr, long double y)
{
    int cnt = 0;
    for (int i = 0; i < arr.size() - 1; i++)
    {
        int reqStatbw = ((arr[i + 1] - arr[i]) / y);
        long double frac = ((arr[i + 1] - arr[i]) / y) - floor((arr[i + 1] - arr[i]) / y);
        if (fabsl(frac) < 1e-12)
        {
            reqStatbw--;
        }

        cnt += reqStatbw;
    }
    return cnt;
}

int main()
{

    int stations;
    cout << "no of stations:";
    cin >> stations;

    int n;
    cout << "the val of n:";
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // hash type -->

    vector<int> putStat(n - 1, 0);
    long double minGap = -1;

    // brute -->

    /*  for (int i = 1; i <= stations; i++)
    {
        long double maxgap = -1;
        int place = -1;
        for (int j = 0; j < n - 1; j++)
        {
            long double diff = arr[j + 1] - arr[j];
            long double seclen = diff / ((long double)(putStat[j] + 1));

            if (maxgap < seclen)
            {
                maxgap = seclen;
                place = j;
            }
        }
        putStat[place]++;
    }

    for (int i = 0; i < n - 1; i++)
    {
        long double diff = arr[i + 1] - arr[i];
        long double gaps = diff / (long double)(putStat[i] + 1);
        minGap = max(minGap, gaps);
    }

    cout << minGap;
    */

    // better -->
    // use priority qeue-->

    /* priority_queue<pair<long double, int>> pq;

     for (int j = 0; j < n - 1; j++)
     {
         pq.push({arr[j + 1] - arr[j], j});
     }
     for (int i = 1; i <= stations; i++)
     {
         auto tp = pq.top();
         pq.pop();
         int place = tp.second;
         putStat[place]++;

         long double inDiff = arr[place + 1] - arr[place];
         long double newSeclen = inDiff / (long double)(putStat[place] + 1);
         pq.push({newSeclen, place});
     }

     cout << pq.top().first;
     */

    // optimal -->

    long double highdiff = -1;

    for (int i = 0; i < n - 1; i++)
    {
        highdiff = max(highdiff, (long double)(arr[i + 1] - arr[i]));
    }

    long double l = 0;
    long double h = highdiff;

    while (h - l > 1e-6)
    {
        long double mid = (l + h) / 2.0;

        int x = fxn(arr, mid);

        if (x <= stations)
        {
            minGap = mid;
            h = mid;
        }
        else
            l = mid;
    }

    cout << minGap;

    return 0;
}