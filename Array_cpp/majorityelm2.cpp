#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    cout << "the val of n:";
    cin >> n;
    int M = n / 3;
    int arr[n] = {0};

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    //  better-- >

    // map use-->

    /*    unordered_map<int, int> mp;

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            mp[arr[i]]++;
        }

        for (auto it : mp)
        {
            if (it.second > M)
                cout << it.first << " ";
        }
                */

    // optimal soln--->

    int cnt1 = 0;
    int cnt2 = 0;
    int Melm1, Melm2;
    int i = 0;
    while (i < n)
    {
        if (cnt1 == 0 && arr[i] != Melm2)
        {
            Melm1 = arr[i];
            cnt1 = 1;
        }
        else if (cnt2 == 0 && arr[i] != Melm1)
        {
            Melm2 = arr[i];
            cnt2 = 1;
        }

        else if (arr[i] == Melm1)
            cnt1++;
        else if (arr[i] == Melm2)
            cnt2++;
        else
        {
            cnt1--;
            cnt2--;
        }
        i++;
    }

    int c1 = 0, c2 = 0;
    if (cnt1 > 0 || cnt2 > 0)
    {

        for (int i = 0; i < n; i++)
        {
            if (cnt1 > 0 && arr[i] == Melm1)
                c1++;
            if (cnt2 > 0 && arr[i] == Melm2)
                c2++;
        }
    }

    if (c1 > n / 3 && c2 > n / 3)
        cout << Melm1 << " " << Melm2;
    else if (c1 > n / 3)
        cout << Melm1;
    else if (c2 > n / 3)
        cout << Melm2;
    else
        cout << "no major elm";
    return 0;
}