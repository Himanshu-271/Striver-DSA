#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cout << "the val of n:";
    cin >> n;
    cout << "the val of k:";
    cin >> k;

    int arr[n] = {0};
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // brutte-- >

    /*  int subarray = 0;
      int flag = 0;

      for (int i = 0; i < n; i++)
      {

          int sum = arr[i];
          if (sum == k)
          {
              subarray++;
              flag = 1;
          }
          for (int j = i + 1; j < n; j++)
          {
              sum = sum + arr[j];
              if (sum == k)
              {
                  subarray++;
                  flag = 1;
              }
          }
      }
      if (flag == 1)
          cout << subarray;
      else
          cout << "no subarray exist";
  */

    // optimal -->

    unordered_map<int, int> fs;
    fs[0] = 1; // (empty prefix) // subarray start from 0 we need
    int i = 0;
    int sum = 0;
    int subarray = 0; // <sum,freq>
    while (i < n)
    {
        sum = sum + arr[i];
        int ps = sum - k;

        // we need remove ps from sum so we need sum k;
        // no of ps remove utna sub array come-->

        if (fs.find(ps) != fs.end())
        {
            subarray = subarray + fs[ps];
        }
        fs[sum]++;
        i++;
    }

    if (subarray > 0)
        cout << subarray;
    else
        cout << " not exist ";
    return 0;
}