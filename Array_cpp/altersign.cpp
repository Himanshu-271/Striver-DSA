#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; // n is even
    cout << "the val of n:";
    cin >> n;
    int arr[n] = {0};
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // brute -->
    // for both variety unequal cases also

    vector<int> pos;
    vector<int> neg;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
            neg.push_back(arr[i]);
        else
            pos.push_back(arr[i]);
    }

    for (int i = 0; i < max(pos.size(), neg.size()); i++)
    {
        if (i < min(pos.size(), neg.size()))
            cout << pos[i] << " " << neg[i] << " ";
        else
        {
            if (pos.size() > neg.size())
                cout << pos[i] << " ";
            else
                cout << neg[i] << " ";
        }
    }
    // optimal -->

    /* vector<int> ans(n);
     int posIdx = 0;
     int negIdx = 1;

     for (int i = 0; i < n; i++)
     {
         if (arr[i] > 0)
         {
             ans[posIdx] = arr[i];
             posIdx = posIdx + 2;
         }
         else
         {
             ans[negIdx] = arr[i];
             negIdx = negIdx + 2;
         }
     }

     for (auto it : ans)
     {
         cout << it << " ";
     }
         */
    return 0;
}