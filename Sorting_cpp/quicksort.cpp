#include <bits/stdc++.h>
using namespace std;
int fn(int arr[], int L, int H)
{
    int mid = (L + H) / 2;
    swap(arr[L], arr[mid]);
    int pivot = arr[L];
    // two pointer index ;
    int i = L;
    int j = H;

    while (i < j)
    {
        while (arr[i] <= pivot && i <= H - 1)
        {
            // left side bigger elm or not than pivot;
            i++;
        }
        while (arr[j] > pivot && j >= L + 1)
        {
            // right side smaller elm than pivot ; check
            j--;
        }
        if (i < j)
            swap(arr[i], arr[j]);
    }
    swap(arr[L], arr[j]);

    return j;
}
void QS(int arr[], int l, int h)
{
    if (l < h)
    {
        int Pindex = fn(arr, l, h); // partian index
        QS(arr, l, Pindex - 1);     //  left array
        QS(arr, Pindex + 1, h);     // right array
    }
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
    QS(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}

/// best becose in sorted array also remain tc=(nlogn );