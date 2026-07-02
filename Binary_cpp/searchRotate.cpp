#include <bits/stdc++.h>
using namespace std;

int find(int arr[], int l, int h, int k)
{

    // int idx = -1;
    while (l <= h)
    {
        int mid = (l + h) / 2;
        if (arr[mid] == k)
            return mid;

        else
        {
            if (arr[mid] < arr[h])
            {
                if (arr[mid] <= k && k <= arr[h])
                {
                    l = mid + 1;
                }
                else
                {
                    h = mid - 1;
                }
            }

            else
            {
                if (arr[l] <= k && k <= arr[mid])
                {
                    h = mid - 1;
                }
                else
                    l = mid + 1;
            }
        }
    }
    return -1;
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

    // brute --> linear search ;

    int idx = find(arr, 0, m - 1, k);
    cout << idx;

    return 0;
}