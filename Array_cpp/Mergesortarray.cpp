#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cout << "the val of n:";
    cin >> n;
    cout << "the val of m:";
    cin >> m;
    int arr[n] = {0};
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << endl;

    int brr[m] = {0};
    for (int i = 0; i < m; i++)
    {
        cin >> brr[i];
    }

    sort(arr, arr + n);
    sort(brr, brr + m);

    int ans[n + m] = {0};

    // brute -->
    // also take extra space-->

    /*  int left = 0;
      int right = 0;
      int idx = 0;
      while (left < n && right < m)
      {
          if (arr[left] < brr[right])
          {
              ans[idx] = arr[left];
              idx++;
              left++;
          }
          else if (arr[left] > brr[right])
          {
              ans[idx] = brr[right];
              idx++;
              right++;
          }
          else
          {
              ans[idx] = arr[left];
              left++;
              idx++;
              ans[idx] = brr[right];
              right++;
              idx++;
          }
      }

      while (left < n)
      {
          ans[idx] = arr[left];
          left++;
          idx++;
      }
      while (right < m)
      {
          ans[idx] = brr[right];
          right++;
          idx++;
      }

      for (int i = 0; i < m + n; i++)
      {
          cout << ans[i] << " ";
      }
          */

    // optimal 1-->

    /* int left = n - 1;
     int right = 0;
     while (left >= 0 && right < m)
     {
         if (arr[left] > brr[right])
         {
             swap(arr[left], brr[right]);
             left--;
             right++;
         }
         else
         {
             break;
         }
     }

     sort(arr, arr + n);
     sort(brr, brr + m);

     for (int i = 0; i < n; i++)
     {
         cout << arr[i] << " ";
     }

     for (int i = 0; i < m; i++)
     {
         cout << brr[i] << " ";
     }
 */

    // optimal 2--->
    // mine jumping pointer + seprate array-->

    int right = 0;
    int left = 0;

    int len = (n + m + 1) / 2;
    while (len > 0)
    {

        right = len; // right pointer ;
        left = 0;

        // all three posiblity-->
        if (len < n) // both pointer on arr;
        {
            while (right < n) // arr-arr comp;
            {
                if (arr[left] > arr[right])
                {
                    swap(arr[left], arr[right]);
                }
                left++;
                right++;
            }

            int idx1 = right; // right come out of arr(jump)
            if (idx1 >= n)
            {
                right = 0;                    // intitalise brr[0];  right poniter to brr;
                while (left < n && right < m) // arr-brr comp;
                {
                    if (arr[left] > brr[right])
                    {
                        swap(arr[left], brr[right]);
                    }
                    left++;
                    right++;
                }
            }
            int idx2 = left; // left come out arr(jump);

            if (idx2 >= n)
            {
                left = 0;         // left initlise at brr[0];
                while (right < m) // comp. brr-brr elm;
                {

                    if (brr[left] > brr[right])
                    {
                        swap(brr[left], brr[right]);
                    }
                    left++;
                    right++;
                }
            }
        }

        //  two posiblity arr-brr, brr-brr-->

        else // if right pointer brr start me hi;
        {
            right = len - n; // indexing  no go out of bound brr;
            if (left < n)    // left at arr so srr-brr comp ;
            {
                while (left < n && right < m)
                {
                    if (arr[left] > brr[right])
                        swap(arr[left], brr[right]);
                    left++;
                    right++;
                }
            }
            if (left >= n) // brr-brr comp now;
            {
                left = 0; // jump
                while (right < m)
                {
                    if (brr[left] > brr[right])
                        swap(brr[left], brr[right]);
                    left++;
                    right++;
                }
            }
        }
        if (len == 1)
            break;

        len = (len + 1) / 2;
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    for (int i = 0; i < m; i++)
    {
        cout << brr[i] << " ";
    }

    return 0;
}