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

    // brute --->

    /*  vector<int> Ls;
      for (int i = 0; i < n; i++)
      {
          int flag = 1;
          for (int j = i + 1; j < n; j++)
          {
              if (arr[j] > arr[i])
              {
                  flag = 0;
                  break;
              }
          }
          if (flag == 1)
              Ls.push_back(arr[i]);
      }
      cout << "leaders are: ";
      for (auto it : Ls)
      {
          cout << it << " ";
      }
          */

    // optimal soln-->
    int maxi = INT_MIN;
    int i = n - 1;
    while (i >= 0)
    {
        if (arr[i] > maxi)
        {
            cout << arr[i] << " ";
            maxi = max(maxi, arr[i]);
        }
        i--;
    }
    return 0;
}