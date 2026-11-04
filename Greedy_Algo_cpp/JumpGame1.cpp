#include <bits/stdc++.h>
using namespace std;

bool StoneGame(vector<int> &arr, int n)
{
    int max_idx = 0;

    for (int i = 0; i < n; i++)
    {
        max_idx = max(max_idx, (i + arr[i]));

        if (i >= max_idx)
            return false;

        if (max_idx >= n - 1)
            return true;
    }

    return false;
}

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

    bool ans = StoneGame(arr, n);

    cout << ans;

    return 0;
}