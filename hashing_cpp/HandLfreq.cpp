#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int N = -1;
    for (int i = 0; i < n; i++)
    {
        if (N < arr[i])
            N = arr[i];
    }

    int hs[N + 1] = {0};
    for (int i = 0; i < n; i++)
    {
        hs[arr[i]]++;
    }
    int maxi = -1, mini = n;
    int M;
    int m;
    for (int i = 0; i < n; i++)
    {
        if (maxi < hs[arr[i]])
        {
            maxi = hs[arr[i]];
            M = arr[i];
        }
        if (mini > hs[arr[i]])
        {
            mini = hs[arr[i]];
            m = arr[i];
        }
    }
    // cout << "max freq elm:" << M << endl
    //   << "min freq elm:" << m;
    for (int i = 0; i <= N; i++)
    {
        if (hs[i] == maxi)
            cout << i << " ";
    }
    cout << endl;
    for (int i = 0; i <= N; i++)
    {
        if (hs[i] == mini)
            cout << i << " ";
    }

    return 0;
}