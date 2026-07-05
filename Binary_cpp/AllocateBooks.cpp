#include <bits/stdc++.h>
using namespace std;

int fxn(vector<int> &arr, int y)
{
    int cnt = 0;
    int sum = 0;
    for (int j = 0; j < arr.size(); j++)
    {
        sum = sum + arr[j];

        if (sum > y)
        {
            cnt++;
            sum = arr[j];
        }

        if (j == arr.size() - 1)
            cnt++;
    }
    return cnt;
}

int main()
{
    int students;
    cout << "no of std:";
    cin >> students;

    int n;
    cout << "the val of n:";
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int minPages = *max_element(arr.begin(), arr.end());
    int maxPages = accumulate(arr.begin(), arr.end(), 0);
    int pages = 0;

    int flag = 0;

    if (students > arr.size())
    {
        cout << "-1";
        flag = 1;
    }

    if (students == arr.size())
    {
        pages = *max_element(arr.begin(), arr.end());
        cout << pages;
        flag = 1;
    }

    // brute -->

    /* if (flag == 0)
     {
         for (int i = minPages; i <= maxPages; i++)
         {
             int cnt = 0;
             int sum = 0;
             for (int j = 0; j < n; j++)
             {
                 sum = sum + arr[j];

                 if (sum > i)
                 {
                     cnt++;
                     sum = arr[j];
                 }

                 if (j == n - 1)
                     cnt++;
             }
             if (cnt <= students)
             {
                 pages = i;
                 break;
             }
         }
         cout << pages;
     }
 */

     // optimal ---->

    int l = minPages;
    int h = maxPages;

    if (flag == 0)
    {
        while (l <= h)
        {
            int mid = l + (h - l) / 2;

            int x = fxn(arr, mid);

            if (x <= students)
            {
                pages = mid;
                h = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        cout << pages;
    }

    return 0;
}