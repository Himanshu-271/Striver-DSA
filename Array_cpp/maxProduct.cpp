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

    // brute--->
    if (n == 0)
    {
        cout << "empty array";
        return 0;
    }
    /* long long pro = INT_MIN;

     for (int i = 0; i < n; i++)
     {
         long long mul = arr[i];
         pro = max(pro, mul);

         {
             for (int j = i + 1; j < n; j++)
             {
                 mul = mul * arr[j];
                 pro = max(pro, mul);
             }
         }
     }

     cout << pro;*/

    // optimal -->

    int maxpre = INT_MIN;
    int maxsuf = INT_MIN;
    int maxpro = INT_MIN;
    int i = 0;
    int pre = 1;
    int suf = 1;
    while (i < n)
    {
        pre = pre * arr[i];
        maxpre = max(maxpre, pre);
        if (pre == 0)
            pre = 1;

        suf = suf * arr[(n - 1) - i];
        maxsuf = max(maxsuf, suf);
        if (suf == 0)
            suf = 1;

        maxpro = max(maxpre, maxsuf);

        i++;
    }

    cout << maxpro;

    return 0;
}