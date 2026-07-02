#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "the val of n:";
    cin >> n;
    int arr[n] = {0};
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    /* set<int> s;
     for (int i = 0; i < n; i++)
     {
         s.insert(arr[i]);
     }
     int flag = 0;
     for (int i = 1; i <= s.size(); i++)
     {
         if (s.find(i) == s.end())
         {
             cout << i << " ";
             flag = 1;
         }
     }
     if (flag == 0)
         cout << " no miss elm";
         */

    //  by hashing-->

    int maxi = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > maxi)
            maxi = arr[i];
    }

    int hs[maxi + 1] = {0};
    for (int i = 0; i < n; i++)
    {
        hs[arr[i]]++;
    }

    for (int i = 1; i <= maxi + 1; i++)
    {
        if (hs[i] == 0)
            cout << i << " ";
    }

    // otimal soln--> just for one missing no no duplicate
    //     int sum = maxi * (maxi + 1) / 2;
    //     int sum2 = 0;
    //     for (int i = 1; i <= n; i++)
    //     {
    //         sum = sum + i;
    //     }
    //     cout << "the miss no is " << sum - sum2;
    return 0;
}