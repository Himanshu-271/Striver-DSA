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

    // better -->
    // hashing array -->

    /*    int maxi = *max_element(arr, arr + n);
        int hs[maxi + 1] = {0};

        for (int i = 0; i < n; i++)
        {
            hs[arr[i]]++;
        }

        cout << "miss elm:";
        int flag = 0;

        for (int i = 1; i < maxi + 1; i++)
        {
            if (hs[i] == 0)
            {
                cout << i << " ";
                flag = 1;
            }
        }

        if (flag == 0)
            cout << " no miss elm";

        cout << endl;

        int flag2 = 0;

        cout << "repeated elm:";

        for (int i = 0; i < maxi + 1; i++)
        {
            if (hs[i] > 1)
            {
                cout << i << " ";
                flag2 = 1;
            }
        }
        if (flag2 == 0)
            cout << "no repeated elm";
            */

    // optimal soln---->
    // use maths-->

    /* int miss;
     int rep;
     int Sum = (n * (n + 1)) / 2;
     int sum = 0;
     for (int i = 0; i < n; i++)
     {
         sum = sum + arr[i];
     }

     int x = sum - Sum;

     int S2n = (n * (n + 1) * (2 * n + 1)) / 6;
     int s2 = 0;
     for (int i = 0; i < n; i++)
     {
         s2 = s2 + arr[i] * arr[i];
     }

     int y = (s2 - S2n) / x;

     rep = (x + y) / 2;
     miss = y - rep;

     cout << "repeated elm:" << rep << endl;
     cout << "miss elm :" << miss;
     */

    // XOR method ---->

    int xr = 0; // rep^miss=xr
    // imp  bcoz they ocuurance odd they left while xor with 1--n no.s;
    for (int i = 0; i < n; i++)
    {
        xr = xr ^ arr[i];
        xr = xr ^ (i + 1);
    }

    int bitno = 0;
    while ((xr & (1 << bitno)) == 0) // first bit diff kha hua from right-->l ;
    {
        bitno++;
    }

    // club no.s-- 0  1 bit me -->
    int onebit = 0;  // us bit positon par 0 bit h  jis no. ka
    int zerobit = 0; // jis ka 1
    for (int i = 0; i < n; i++)
    {
        if ((arr[i] & (1 << bitno)) != 0)
        {
            onebit = onebit ^ arr[i]; // xor one bit all;
        }
        else
        {
            zerobit = zerobit ^ arr[i]; // xor of zero bit all;
        }
    }

    // with 1---n numbers  also club 0 and 1 s--
    for (int i = 0; i < n; i++)
    {
        if ((i + 1) & (1 << bitno) != 0)
        {
            onebit = onebit ^ (i + 1);
        }
        else
        {
            zerobit = zerobit ^ (i + 1);
        }
    }

    // ans alwys zerobit or one bit ;  bcoz they ocuurance odd they left while xor;
    // check which our answer--> miss kon sa  or rep kon sa-->

    int cnt = 0;
    int cnt2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == onebit)
            cnt++;
        if (arr[i] == zerobit)
            cnt2++;
    }
    if (cnt > 1 && cnt2 == 0)
    {
        cout << " repeated elm" << onebit << endl
             << "miss elm" << zerobit;
    }
    if (cnt == 0 && cnt2 > 1)
    {
        cout << " repeated elm" << zerobit << endl
             << "miss elm" << onebit;
    }

    return 0;
}