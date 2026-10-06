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

    // brute --> hashing

    // optimal--->

    long xr = 0; // overflow prblm

    for (int i = 0; i < arr.size(); i++)
    {
        xr = xr ^ arr[i];
    }

    int rightmost = (xr & (xr - 1)) ^ xr; //(xr&-xr) also // differnciate that two distnict no on i bit difference
    int b1_1 = 0;                         // make bucket atq to that postion o,s or 1,s which postion no go in which bucket
    int b2_0 = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        if ((rightmost & arr[i]) == 0) // if 0 at that postion
            b2_0 = b2_0 ^ arr[i];
        else
            b1_1 = b1_1 ^ arr[i];
    }

    cout << b1_1 << " " << b2_0;

    return 0;
}