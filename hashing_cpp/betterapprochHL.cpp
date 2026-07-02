#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    unordered_map<int, int> mpp;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        mpp[arr[i]]++;
    }
    int maxi = 0, mini = n;
    for (auto it : mpp)
    {
        if (it.second > maxi)
        {
            maxi = it.second;
        }

        if (it.second < mini)
        {
            mini = it.second;
        }
    }
    for (auto it : mpp)
    {
        if (maxi == it.second)
            cout << it.first << " ";
    }
    cout << endl;
    for (auto it : mpp)
    {
        if (mini == it.second)
            cout << it.first << " ";
    }

    return 0;
}