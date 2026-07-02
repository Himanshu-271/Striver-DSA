#include <bits/stdc++.h>
using namespace std;
// Brute approach -->
void bubblesort(int arr[], int a, int b)
{
    for (int i = b; i >= a; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
}
/*int main()
{
    int n;
    cout << "tje val of n:";
    cin >> n;
    int arr[n] = {0};
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    bubblesort(arr, 0, n - 1);
    int maxi = arr[n - 1];
    int secmaxi = arr[n - 2];
    for (int i = n - 2; i >= 0; i--)
    {
        if (maxi > arr[i])
        {
            secmaxi = arr[i];
            break;
        }
    }
    cout << secmaxi;
    return 0;
}*/
// tc= O(n2+n)my case  or(nlogn+n)

// best-->
/*int main()
{
    int n;
    cout << "tje val of n:";
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
    int secmax = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > secmax && arr[i] < maxi)
        {
            secmax = arr[i];
        }
    }
    if (secmax == INT_MIN)
        cout << " no sec large elm";

    else
        cout << secmax;
    return 0;
}*/
//  tc=O(2n);

// optimal-->
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
    int maxi = arr[0];
    int secmax = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > maxi)
        {
            secmax = maxi;
            maxi = arr[i];
        }
        else if (arr[i] < maxi && arr[i] > secmax)
        {
            secmax = arr[i];
        }
    }

    cout << secmax;

    return 0;
}
// tc=O(n)