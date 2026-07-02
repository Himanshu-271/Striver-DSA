#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    cout << "the val of n:";
    cin >> n;
    int M;
    cout << "the val of M:";
    cin >> M;
    int arr[n] = {0};
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    /* int Len = 0;
     for (int i = 0; i < n; i++)
     {
         int sum = 0;
         for (int j = i; j < n; j++)
         {

             sum = sum + arr[j];
             if (sum == M)
                 Len = max(Len, j - i + 1);
         }
     }
     cout << Len;*/

    // two pointer ;  for positive no only -->
    /*
    int i = 0, j = 0;
    int len = 0;
    int sum = 0;
    while (i < n && j < n)
    {

        sum = sum + arr[j];
        if (sum > M)
        {
            //  pura rest or waps check again  -->

            sum = 0;
            i++;
            j = i;
        }
        else if (sum < M)
        {
            j++;
        }
        else
        {
            len = max(len, j - i + 1);
            if (j == n - 1)
                break;
            sum = 0;
            i++;
            j = i;
        }
    }
    cout << len;
    */

    // by hasing map -->
    int i = 0;
    int sum = 0;
    int maxLen = 0;
    int ps = 0;
    map<int, int> fs; //<sum,index up to>
    while (i < n)
    {
        sum = sum + arr[i];
        ps = sum - M;
        // handel 0s--

        if (fs.find(sum) == fs.end())
        {
            fs[sum] = i;
        }
        // if happen 0 to that index is len
        if (sum == M)
        {
            maxLen = max(maxLen, i + 1);
        }
        // if ps exist present sum -ps.sum indexs is over subarray handel-->

        if (fs.find(ps) != fs.end())
        {
            maxLen = max(maxLen, i - fs[ps]);
        }
        i++;
    }
    cout << maxLen;

    return 0;
}