#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << ":the val of n:";
    cin >> n;
    int arr[n] = {0};
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int j = -1; // pointer for break point;

    // loop check up to how much digits prefix same ;  eg  rax  rab  ra smae prefix
    // start me pura hi smae digit as prefixmatch leke chale ge then deduce-->
    // where break come up to back to that elm only prefix match,

    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] >= arr[i + 1])
            continue;
        else
        {
            //  break hoga j me store
            j = i;
            break;
        }
    }
    if (j >= 0)
    {
        for (int i = n - 1; i >= j + 1; i--)
        {
            if (arr[i] > arr[j])
            {
                // swap with least largest amog them but greater than break point that elm;
                // so no. just next to it come not far go;  eg 4 3 2 -->2 swap kare ge break point ko
                swap(arr[i], arr[j]);
                break;
            }
        }
    }

    if (j >= 0) // break point mila -->
        reverse(arr + (j + 1), arr + n);
    else // nhi mila-->
        reverse(arr, arr + n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}