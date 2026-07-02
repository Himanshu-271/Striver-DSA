#include <bits/stdc++.h>
using namespace std;

void sort(int arr[], int l, int m, int h)
{
    while (m <= h)
    {
        if (arr[m] == 0)
        {
            swap(arr[l], arr[m]);
            l++;
            m++;
        }
        else if (arr[m] == 1)
            m++;

        else
        {
            swap(arr[m], arr[h]);
            h--;
        }
    }
}
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

    // better-->

    /*   int cnt0 = 0, cnt1 = 0, cnt2 = 0;
       for (int i = 0; i < n; i++)
       {
           if (arr[i] == 0)
               cnt0++;
           else if (arr[i] == 1)
               cnt1++;
           else
               cnt2++;
       }
       for (int i = 0; i < cnt0; i++)
       {
           cout << "0" << " ";
       }
       for (int i = cnt0; i < cnt0 + cnt1; i++)
       {
           cout << "1" << " ";
       }
       for (int i = cnt0 + cnt1; i < cnt0 + cnt1 + cnt2; i++)
       {
           cout << "2" << " ";
       }
   */

    // optimal -->
    // Dutch national flag algo-->

    sort(arr, 0, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}