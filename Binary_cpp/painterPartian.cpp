#include <bits/stdc++.h>
using namespace std;

int fxn(vector<int> &arr, int y)
{
    int cnt = 0;
    int sum = 0;
    for (int j = 0; j < arr.size(); j++)
    {
        sum = sum + arr[j];

        if (sum > y)
        {
            cnt++;
            sum = arr[j];
        }

        if (j == arr.size() - 1)
            cnt++;
    }
    return cnt;
}

int main()
{
    int painter;
    cout << "painters:";
    cin >> painter;

    int n;
    cout << "the val of n:";
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int mintime = *max_element(arr.begin(), arr.end());
    int maxtime = accumulate(arr.begin(), arr.end(), 0);
    int time = 0;

    int flag = 0;

    if (painter > arr.size())
    {
        cout << "-1";
        flag = 1;
    }

    if (painter == arr.size())
    {
        time = *max_element(arr.begin(), arr.end());
        cout << time;
        flag = 1;
    }

    // brute -->

    /* if (flag == 0)
     {
         for (int i = mintime; i <= maxtime; i++)
         {
             int cnt = 0;
             int sum = 0;
             for (int j = 0; j < n; j++)
             {
                 sum = sum + arr[j];

                 if (sum > i)
                 {
                     cnt++;
                     sum = arr[j];
                 }

                 if (j == n - 1)
                     cnt++;
             }
             if (cnt <= painter)
             {
                 pages = i;
                 break;
             }
         }
         cout << time;
     }
 */

    // optimal ---->

    int l = mintime;
    int h = maxtime;

    if (flag == 0)
    {
        while (l <= h)
        {
            int mid = l + (h - l) / 2;

            int x = fxn(arr, mid);

            if (x <= painter)
            {
                time = mid;
                h = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        cout << time;
    }

    return 0;
}
