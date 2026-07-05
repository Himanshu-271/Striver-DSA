#include <bits/stdc++.h>
using namespace std;

int fxn(vector<int> &arr, int y)
{
    int cnt = 1; // first cow sit 0 idx
    int idx = 0;
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] - arr[idx] >= y)
        {
            cnt++;
            idx = i;
        }
    }
    return cnt;
}

int main()
{
    int cows;
    cout << "cows:";
    cin >> cows;

    int n;
    cout << "the val of n:";
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    int minDist = 1;
    int maxdistance = arr[n - 1] - arr[0];

    int flag = 0;

    if (cows > n)
    {
        cout << "Invalid input";
        flag = 1;
    }

    // brute -->

    /*

     if (flag == 0)
     {

         for (int j = 1; j <= maxdistance; j++)
         {
             int idx = 0;
             int cnt = 1; // 1 cow arr 0 idx

             for (int i = 1; i < n; i++)
             {
                 if (arr[i] - arr[idx] >= j)
                 {
                     cnt++;
                     idx = i;
                 }

                 if (cnt == cows)
                 {
                     minDist = j;
                     break;
                 }
             }
             if (minDist < j)
                 break;
         }
         cout << minDist;
     }
         */

    // optimal -->

    if (flag == 0)
    {

        int l = 0;
        int h = maxdistance;

        while (l <= h)
        {
            int mid = (l + h) / 2;

            int x = fxn(arr, mid);

            if (x >= cows)
            {
                l = mid + 1;
                minDist = mid;
            }

            else if (x < cows)
            {
                h = mid - 1;
            }
        }

        cout << minDist;
    }

    return 0;
}