#include <bits/stdc++.h>
using namespace std;

int fxn(vector<int> &arr, int y)
{
    int cnt = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        cnt = cnt + ceil((double)arr[i] / (double)y);
    }

    if (cnt < arr.size())
        return -1;
    else
        return cnt;
}

int main()
{
    int thresold;
    cout << "the val of thres:";
    cin >> thresold;

    int n;
    cout << "the val of n:";
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // brute-->

    int maxdivisor = *max_element(arr.begin(), arr.end());
    int divisor = -1;

    /* for (int i = 1; i <= maxdivisor; i++)
     {
         int cnt = 0;

         for (int j = 0; j < n; j++)
         {
             cnt = cnt + ceil(arr[j] / i);
         }

         if (cnt <= thresold)
         {
             divisor = i;
             break;
         }
         else
             continue;
     }

     cout << divisor;
     */

    // optimal --->

    int l = 1;
    int h = maxdivisor;

    while (l <= h)
    {
        int mid = (l + h) / 2;

        int x = fxn(arr, mid);

        if (x == -1)
        {
            break;
        }

        if (x <= thresold)
        {
            divisor = mid;
            h = mid - 1;
        }
        else
            l = mid + 1;
    }

    cout << divisor;

    return 0;
}