#include <bits/stdc++.h>
using namespace std;

int binaryS(int arr[], int l, int h, int k)
{

    // loop use-->

    /*  while (l <= h)
      {
          if (l <= h)
          {
              int mid = (l + h) / 2;
              if (arr[mid] == k)
                  return mid;

              else if (arr[mid] > k)
              {
                  h = mid - 1;
              }
              else+
              {
                  l = mid + 1;
              }
          }
      }
      return h + 1;
      */

    // recursion -->
    int mid = (l + h) / 2;

    if (l > h)
        return h + 1;

    if (arr[mid] == k)
        return mid;

    else if (arr[mid] > k)
        return binaryS(arr, l, mid - 1, k);

    else
        return binaryS(arr, mid + 1, h, k);
}

int main()
{
    int n, k;
    cout << "the val of n:";
    cin >> n;
    cout << "the vla of k:";
    cin >> k;

    int arr[n] = {0};
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);

    int idx = binaryS(arr, 0, n - 1, k);
    cout << idx;
    return 0;
}