#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "the val of n:";
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int m;
    cout << "the val of m:";
    cin >> m;

    vector<int> brr(m);

    for (int i = 0; i < m; i++)
    {
        cin >> brr[i];
    }

    // brute --->

    // merge them-->

    /* vector<int> mergearray;

     int p1 = 0;
     int p2 = 0;

     while (p1 < n && p2 < m)
     {
         if (arr[p1] < brr[p2])
         {
             mergearray.push_back(arr[p1]);
             p1++;
         }
         else
         {
             mergearray.push_back(brr[p2]);
             p2++;
         }
     }

     while (p1 < n)
     {
         mergearray.push_back(arr[p1]);
         p1++;
     }

     while (p2 < m)
     {
         mergearray.push_back(brr[p2]);
         p2++;
     }

     // median find-->

     double median = -1;

     if (mergearray.size() % 2 != 0)
     {
         median = mergearray[mergearray.size() / 2];
     }

     else
     {
         int x = mergearray[mergearray.size() / 2];
         int y = mergearray[(mergearray.size() / 2) - 1];
         median = (x + y) / 2.0;
     }

     cout << median;
     */

    // better -->

    int cnt = 0;
    int p1 = 0;
    int p2 = 0;
    int idx1 = -1;
    int idx2 = -1;
    int elm1 = -1;
    int elm2 = -1;

    if ((m + n) % 2 != 0)
    {
        idx1 = (m + n) / 2;
    }

    else
    {
        idx1 = (m + n) / 2;
        idx2 = (m + n) / 2 - 1;
    }

    while (p1 < n && p2 < m)
    {
        if (arr[p1] < brr[p2])
        {
            if (cnt == idx1)
            {
                idx1 = p1;
                elm1 = arr[p1];
            }
            if (cnt == idx2)
            {
                idx2 = p1;
                elm2 = arr[p1];
            }
            cnt++;
            p1++;
        }

        else
        {
            if (cnt == idx1)
            {
                idx1 = p2;
                elm1 = brr[p2];
            }
            if (cnt == idx2)
            {
                idx2 = p2;
                elm2 = brr[p2];
            }
            cnt++;
            p2++;
        }
    }

    while (p1 < n)
    {

        if (cnt == idx1)
        {
            idx1 = p1;
            elm1 = arr[p1];
        }
        if (cnt == idx2)
        {
            idx2 = p1;
            elm2 = arr[p1];
        }
        cnt++;
        p1++;
    }

    while (p2 < m)
    {

        if (cnt == idx1)
        {
            idx1 = p2;
            elm1 = brr[p2];
        }
        if (cnt == idx2)
        {
            idx2 == p2;
            elm2 = brr[p2];
        }
        cnt++;
        p2++;
    }

    if (idx2 == -1)
    {
        cout << elm1;
    }
    else
    {
        double ans = (elm1 + elm2) / 2.0;
        cout << ans;
    }

    return 0;
}