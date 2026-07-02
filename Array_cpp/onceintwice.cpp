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
    // int maxi = -1;
    // for (int i = 0; i < n; i++)
    // {
    //     if (arr[i] > maxi)
    //         maxi = arr[i];
    // }

    /* int hs[maxi + 1] = {0};
       for (int i = 0; i < n; i++)
       {
           hs[arr[i]]++;
       }
       int flag = 0;
       for (int i = 0; i < maxi + 1; i++)
       {
           if (hs[i] == 1)
           {
               cout << i << " ";
               flag = 1;
           }
       }
       if (flag == 0)
           cout << "there is no single elm";
           */

    // better-->

    /*  map<int, int> mp;
      for (int i = 0; i < n; i++)
      {
          mp[arr[i]]++;
      }

      for (auto it : mp)
      {
          if (it.second == 1)
          {
              cout << it.first;
          }
      }*/

    // optimal-->

    //  XOR;  says (a xor a = 0 )and (a xor 0 = 1)
    int xorr = 0;
    for (int i = 0; i < n; i++)
    {
        xorr = xorr ^ arr[i];
    }
    cout << xorr;

    return 0;
}