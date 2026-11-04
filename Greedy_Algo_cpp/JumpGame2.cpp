#include <bits/stdc++.h>
using namespace std;

void MINJUMPS(int idx, int jumps, vector<int> &arr, int &minjumps)
{

    if (idx >= arr.size() - 1)
    {
        minjumps = min(minjumps, jumps);
        return;
    }

    for (int i = 1; i <= arr[idx]; i++)
    {
        MINJUMPS(idx + i, jumps + 1, arr, minjumps);
    }
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

    // Recursion approch--->

    // int minjumps = INT_MAX;
    // MINJUMPS(0, 0, arr, minjumps);

    // cout << minjumps;

    // Greedy approch--->

    // take range from currrent step L = min jump from current idx , r = highest jump from current idx
    // than compute jumps l to max we go or right from max we go update range .. count total jumps

    int l = 0;
    int r = 0;

    int jumps = 0;

    while (r < arr.size() - 1)
    {
        int farthest = 0;
        for (int i = l; i <= r; i++)
        {
            farthest = max(farthest, arr[i] + i);
        }
        l = r + 1;
        r = farthest;
        jumps++;
    }

    cout << jumps;

    return 0;
}