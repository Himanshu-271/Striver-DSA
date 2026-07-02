#include <bits/stdc++.h>
using namespace std;

int Minelm(int arr[], int l, int h)
{
    int ans = INT_MAX;
    while (l <= h)
    {

        int mid = (l + h) / 2;

        if (arr[l] <= arr[h])
        {
            ans = min(ans, arr[l]);
            break;
        }

        if (arr[mid] < arr[h])
        {
            ans = min(ans, arr[mid]);
            h = mid - 1;
        }
        else
        {
            ans = min(arr[l], ans);
            l = mid + 1;
        }
    }
    return ans;
}

int main()
{
    int m, k;
    cout << "the val of m:";
    cin >> m;

    int arr[m] = {0};
    for (int i = 0; i < m; i++)
    {
        cin >> arr[i];
    }

    int ans = Minelm(arr, 0, m - 1);
    cout << ans;
    return 0;
}