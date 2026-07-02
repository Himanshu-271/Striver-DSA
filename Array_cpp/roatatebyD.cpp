#include <bits/stdc++.h>
using namespace std;

// Brute -->
/*int main()
{

    int n;
    cout << "the val of n:";
    cin >> n;
    int D;
    cout << "the val of D:";
    cin >> D;
    int arr[n] = {0};
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int temp[D] = {0};
    // store
    for (int i = 0; i < D; i++)
    {
        temp[i] = arr[i];
    }
    // shift
    for (int i = D; i < n; i++)
    {
        arr[i - D] = arr[i];
    }
    // puting
    for (int j = n - D; j < n; j++)
    {
        arr[j] = temp[j - (n - D)];
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}*/

// TC=O(n+D); SC=O(D)

// optimal soln-->
int main()
{

    int n;
    cout << "the val of n:";
    cin >> n;
    int D;
    cout << "the val of D:";
    cin >> D;
    int arr[n] = {0};
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    reverse(arr, arr + D);
    reverse(arr + D, arr + n);
    reverse(arr, arr + n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}