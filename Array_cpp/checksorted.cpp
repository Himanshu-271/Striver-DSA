#include <bits/stdc++.h>
using namespace std;

bool Sortcheck(int arr[], int a, int b)
{
    for (int i = a; i < b; i++)
    {
        if (arr[i + 1] >= arr[i])
        {
        }

        else
            return false;
    }
    return true;
}
int main()
{
    int n;
    cout << "tje val of n:";
    cin >> n;
    int arr[n] = {0};
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    // check-->
    cout << Sortcheck(arr, 0, n - 1);

    return 0;
}