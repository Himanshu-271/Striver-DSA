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

    /*int ans = 0;

    // idea -->

    // each no come thrice except one no  so each bit set multple of 3 mean repated no if not that bit set is our ans add;

    for (int bitidx = 0; bitidx < 31; bitidx++)
    {

        int cnt = 0;

        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] & (1 << bitidx))
                cnt++;
        }

        if (cnt % 3 == 1)
            ans |= (1 << bitidx);
    }

    cout << ans;*/

    // pointer approach --->

    // cluster of three we put pointer tp mid of ech cehck it previous elm compare--.

    // constrain size>3; or one elm  present single;

    /* sort(arr.begin(), arr.end());

     int ans = arr[arr.size() - 1];

     int i = 1;

     while (i < arr.size())
     {

         if (arr[i - 1] != arr[i])
         {
             ans = arr[i];
             break;
         }

         i += 2;
     }

     cout << ans;*/

    // Bucket soln-->

    int ones = 0;
    int twos = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        ones = (arr[i] ^ ones) & (~twos);
        twos = (arr[i] ^ twos) & (~ones);
    }

    cout << ones;
    return 0;
}