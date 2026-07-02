#include <bits/stdc++.h>
using namespace std;

int main()
{

    int k;
    cout << " miss no k:";
    cin >> k;

    int n;
    cout << "the val of n:";
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // brute;

    int cnt = 0;
    int ans = -1;
    int x = *max_element(arr.begin(), arr.end());

    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= k)
            k++;
        else
            break;
    }
    ans = k;
    cout << ans;

    return 0;
}