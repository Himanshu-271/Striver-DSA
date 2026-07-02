#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "the val n :";
    cin >> n;
    int arr[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    // brute -->

    /* int ans[n][n];

     for (int i = 0; i < n; i++)
     {
         for (int j = 0; j < n; j++)
         {
             ans[j][n - 1 - i] = arr[i][j];
         }
     }
 */

    // optimal -->

    // Transpose-->

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue;
            else
            {
                if (i < j)
                    swap(arr[i][j], arr[j][i]);
            }
        }
    }

    // than swap-->

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j < n / 2)
                swap(arr[i][j], arr[i][n - 1 - j]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}