#include <bits/stdc++.h>
using namespace std;

int merge(int arr[], int L, int M, int H)
{
    int cnt = 0;
    // int total=0;
    int left = L;
    int right = M + 1;
    vector<int> temp;
    while (left <= M && right <= H)
    {
        if (arr[left] > arr[right])
        {
            // int x = left;
            // while (x <= M)
            // {
            //     cnt++;
            //     x++;
            // }

            cnt += M - left + 1; // better

            temp.push_back(arr[right]);
            right++;
        }
        else
        {
            temp.push_back(arr[left]);
            left++;
        }
    }
    while (left <= M)
    {
        temp.push_back(arr[left]);
        left++;
    }
    while (right <= H)
    {
        temp.push_back(arr[right]);
        right++;
    }

    for (int i = L; i <= H; i++)
    {
        arr[i] = temp[i - L];
    }
    return cnt;
}

int countI(int arr[], int l, int h)
{
    int cnt = 0;
    int mid = (l + h) / 2;
    if (l >= h)
        return 0;
    // division
    cnt += countI(arr, l, mid);
    cnt += countI(arr, mid + 1, h);
    // merge +cnt-->
    cnt += merge(arr, l, mid, h);
    return cnt;
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

    // brute-->  // i<j  arr[i]>arr[j]  count inversion

    /* vector<pair<int, int>> ans;
     int flag = 0;
     int cnt = 0;
     for (int i = 0; i < n; i++)
     {
         for (int j = i + 1; j < n; j++)
         {
             if (arr[i] > arr[j])
             {
                 ans.emplace_back(arr[i], arr[j]);
                 flag = 1;
                 cnt++;
             }
         }
     }

     if (flag == 1)
     {
         for (auto it : ans)
         {
             cout << it.first << " " << it.second;
             cout << endl;
         }
         cout << " no of pairs:" << cnt;
     }
     else
         cout << "no pair exist";
         */

    // optimal --.

    int pairs = countI(arr, 0, n - 1);
    cout << pairs;

    return 0;
}