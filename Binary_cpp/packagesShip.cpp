#include <bits/stdc++.h>
using namespace std;

int fxn(int y, vector<int> &weight)
{
    int cnt = 0;
    int Weg = 0;
    for (int i = 0; i < weight.size(); i++)
    {
        Weg += weight[i];
        if (Weg > y)
        {
            cnt++;
            Weg = weight[i];
        }
        if (i == weight.size() - 1)
            cnt++;
    }
    return cnt;
}

int main()
{
    int Days;
    cout << "the days are:";
    cin >> Days;

    int n;
    cout << "the vl of n :";
    cin >> n;

    vector<int> weight(n);

    for (int i = 0; i < n; i++)
    {
        cin >> weight[i];
    }

    int Mincap = *max_element(weight.begin(), weight.end());

    int totalweight = 0;
    for (int i = 0; i < n; i++)
    {
        totalweight += weight[i];
    }

    int leastCap = -1;

    // brute--->

    /* for (int i = Mincap; i <= totalweight; i++)
     {
         int Weg = 0;
         int cnt = 0;

         for (int j = 0; j < n; j++)
         {
             Weg += weight[j];

             if (Weg > i)
             {
                 cnt += 1;
                 Weg = weight[j];
             }
             if (j == n - 1)
                 cnt += 1;
         }

         if (cnt <= Days)
         {
             leastCap = i;
             break;
         }

         cout << leastCap;
     }
         */

    // optimal soln--->

    int l = Mincap;
    int h = totalweight;

    while (l <= h)
    {
        int mid = (l + h) / 2;
        int x = fxn(mid, weight);

        if (x <= Days)
        {
            leastCap = mid;
            h = mid - 1;
        }
        else
            l = mid + 1;
    }

    cout << leastCap;

    return 0;
}