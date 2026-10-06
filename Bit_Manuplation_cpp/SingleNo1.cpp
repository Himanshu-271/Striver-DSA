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

    int xr = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        xr = xr ^ arr[i];
    }

    cout << xr;

    return 0;
}