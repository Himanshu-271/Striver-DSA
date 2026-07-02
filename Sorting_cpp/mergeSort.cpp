#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int l, int m, int h)
{
    // pointer bheave -->

    int left = l;      // left array pointer;
    int right = m + 1; // right array pointer;
    vector<int> temp;
    while (left <= m && right <= h)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
    }
    // right finish
    while (left <= m)
    {
        temp.push_back(arr[left]);
        left++;
    }
    // left finish
    while (right <= h)
    {
        temp.push_back(arr[right]);
        right++;
    }

    // org array elm add-->
    for (int i = l; i <= h; i++)
    {
        arr[i] = temp[i - l];
    }
}

void mergeSort(int arr[], int L, int H)
{
    // Division in left or right array-->
    if (L == H)
        return; // up to single elm;
    int M = (L + H) / 2;
    mergeSort(arr, L, M);     // left
    mergeSort(arr, M + 1, H); // right
    // Merge + sorting-->
    merge(arr, L, M, H);
}
int main()
{
    int n;
    cout << "the val of n:";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    mergeSort(arr, 0, n - 1);
    for (int i = 0; i <= n - 1; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
