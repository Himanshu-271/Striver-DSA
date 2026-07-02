#include <bits/stdc++.h>
using namespace std;

vector<int> peakelm(int arr[], int l, int h, int size)
{
    vector<int> ans;

    if (size == 0)
        return {-1};
    if (size == 1)
        return {0};

    // edge cases -->

    if (arr[0] > arr[1])
        ans.push_back(0);

    if (arr[size - 1] > arr[size - 2])
        ans.push_back(size - 1);

    while (l <= h)
    {
        int mid = (l + h) / 2;

        if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
        {
            ans.push_back(mid);
        }

        else if (arr[mid] > arr[mid - 1])
        {
            l = mid + 1;
        }
        else
            h = mid - 1;
    }
    return ans;
}

int main()
{
    int m;
    cout << "the val of m:";
    cin >> m;

    int arr[m] = {0};
    for (int i = 0; i < m; i++)
    {
        cin >> arr[i];
    }

    vector<int> idx = peakelm(arr, 1, m - 2, m);

    for (auto it : idx)
    {
        cout << it << " ";
    }

    // brute -->

    /* int flag = 0;

     if (m == 0)
     {
         cout << -1;
         flag = 1;
     }

     if (m == 1)
     {
         cout << 0;
         flag = 1;
     }

     vector<int> idx1;

     if (flag == 0)
     {
         for (int i = 0; i < m; i++)
         {
             if (i == 0)
             {
                 if (arr[i] > arr[i + 1])
                     idx1.push_back(i);
             }

             else if (i > 0 && i < m - 1)
             {
                 if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1])
                     idx1.push_back(i);
             }

             else
             {
                 if (arr[i] > arr[i - 1])
                     idx1.push_back(i);
             }
         }
     }

     for (auto it : idx1)
     {
         cout << it << " ";
}
     */

    return 0;
}