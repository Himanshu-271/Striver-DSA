#include <bits/stdc++.h>
using namespace std;

void rev(int arr[], int i, int j, int n)
{
    if (i >= j)
    {
        for (int k = 0; k < n; k++)
        {
            cout << arr[k] << " ";
        }

        return;
    }
    else
    {
        swap(arr[i], arr[j]);
        rev(arr, i + 1, j - 1, n);
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
    rev(arr, 0, n - 1, n);

    return 0;
}