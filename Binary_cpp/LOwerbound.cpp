#include <bits/stdc++.h>
using namespace std;

// Ceil == lower bound;
int lowerbound(int arr[], int l, int h, int k)
{
    int idx = -1;
    int flag = 0;
    while (l <= h)
    {
        int mid = (l + h) / 2;

        if (arr[mid] >= k) //  equality sign remove it bcom upper bound;
        {
            h = mid - 1;
            idx = mid;
            flag = 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    if (flag == 0)
        return h + 1;
    else
        return idx;
}

// floor -- largest no in array<=target;

int Floor(int arr[], int L, int H, int K)
{
    int idx = -1;
    int flag = 0;
    while (L <= H)
    {
        int mid = (L + H) / 2;

        if (arr[mid] <= K)
        {
            idx = mid;
            L = mid + 1;
            flag = 1;
        }
        else
        {
            H = mid - 1;
        }
    }
    if (flag == 0)
        return L - 1;
    else
        return idx;
}

int main()
{
    int m, k;
    cout << "the val of m:";
    cin >> m;
    cout << "the vla of k:";
    cin >> k;

    int arr[m] = {0};
    for (int i = 0; i < m; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + m);

    int idx1 = lowerbound(arr, 0, m - 1, k);
    int idx2 = Floor(arr, 0, m - 1, k);

    // stl fxn -->
    // int idx=lower_bound(arr.begin(),arr.end(),target)-arr.begin()
    // (start , end , target);
    cout << "Ceil:" << idx1 << endl;
    cout << "floor:" << idx2;

    return 0;
}