#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "the val of n:";
    cin >> n;
    int M = n / 2;
    int arr[n] = {0};
    // map use-->

    //  unordered_map<int, int> mp;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        //  mp[arr[i]]++;
    }
    // int flag = 0;
    // for (auto it : mp)
    // {
    //     if (it.second > M)
    //     {
    //         cout << it.first;
    //         flag = 1;
    //     }
    // }
    // if (flag == 0)
    //     cout << "no majority elm ";

    // by hashing--->
    /*
        int maxi = *max_element(arr, arr + n);

        int hs[maxi + 1] = {0};
        for (int i = 0; i < n; i++)
        {
            hs[arr[i]]++;
        }
        int flag = 0;
        for (int i = 0; i < maxi + 1; i++)
        {
            if (hs[i] > M)
            {
                cout << i;
                flag = 1;
            }
        }
        if (flag == 0)
            cout << "no majority elm ";
            */

    // optimal soln-->
    // more voting algo-->

    int cnt = 0;

    int Melm = arr[0];
    int i = 0;
    while (i < n)
    {
        if (arr[i] == Melm)
        {
            cnt++;
            i++;
        }
        else
        {
            cnt--;
            i++;
        }

        if (cnt == 0)
        {
            if (i < n)
                Melm = arr[i];
            else
                cout << " not found";
        }
    }

    int cnt2 = 0;

    if (cnt > 0)
    {
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == Melm)
                cnt2++;
        }
    }
    if (cnt2 > M)
        cout << Melm;

    return 0;
}