#include <bits/stdc++.h>
using namespace std;

int addn(int arr[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {

        sum = arr[i] + sum;
    }
    return sum;
}

int main()
{
    int n;
    cout << "val of n:";
    cin >> n;
    int arr[n];
    cout << "give arr values: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int sum = addn(arr, n);
    cout << "the sum of array is:" << sum << endl;
    return 0;
}