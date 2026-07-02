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

    int maxi = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > maxi)
            maxi = arr[i];
    }

    cout << maxi;
    return 0;
}