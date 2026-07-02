#include <bits/stdc++.h>
using namespace std;

void selection_sort(int arr[], int n)
{
    for (int i = 0; i <= n - 2; i++)
    {
        // int mini = i;
        for (int j = i + 1; j <= n - 1; j++)
        { // two method-->

            if (arr[j] < arr[i])
            {
                //   mini = j;
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
            // int temp = arr[i];
            // arr[i] = arr[mini];
            // arr[mini] = temp;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
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
    selection_sort(arr, n);
    return 0;
}