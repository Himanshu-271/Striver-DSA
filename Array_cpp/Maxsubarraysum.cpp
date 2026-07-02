#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "the val of n:";
    cin >> n;
    int arr[n] = {0};
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int maxiSum = INT_MIN;

    //  brutte -->

    /* for (int i = 0; i < n; i++)
     {
         int sum = 0;
         for (int j = i; j < n; j++)
         {
             sum += arr[j];
         }
         maxiSum = max(sum, maxiSum);
     }

     cout << maxiSum;
     */

    // optimal
    // kadanes algo--->
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = sum + arr[i];
        if (sum < 0)
        {
            maxiSum = max(sum, maxiSum);
            sum = 0;
        }
        else
        {
            maxiSum = max(sum, maxiSum);
        }
    }

    cout << maxiSum;
    return 0;
}
