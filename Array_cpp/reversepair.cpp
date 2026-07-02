#include <bits/stdc++.h>
using namespace std;

int merge(int arr[], int L, int M, int H)
{
    int cnt = 0;
    int left = L;
    int right = M + 1;
    vector<int> temp;
    int Right = M + 1;
    for (int i = L; i <= M; i++)
    {
        while (Right <= H && arr[i] > 2 * arr[Right])
        {
            Right++;
        }
        cnt += (Right - (M + 1));
    }
    while (left <= M && right <= H)
    {

        //  danger  miss kare ga arr start -10,5   right -7 , 4  mis kar de ga pairs
        // if (arr[left] >= arr[right])
        // {
        //     int x = left;

        //     while (x <= M)
        //     {
        //         if ((long long)arr[x] > 2LL * arr[right])
        //         {
        //             cnt += M - x + 1;
        //             break;
        //         }
        //         x++;
        //     }

        //     temp.push_back(arr[right]);
        //     right++;
        // }
        if (arr[left] >= arr[right])
        {
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

int revPairs(int arr[], int l, int h)
{
    int cnt = 0;
    int mid = (l + h) / 2;
    if (l >= h)
        return 0;
    // division
    cnt += revPairs(arr, l, mid);
    cnt += revPairs(arr, mid + 1, h);
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

    // optimal soln-->

    int pairs = revPairs(arr, 0, n - 1);
    cout << pairs;

    return 0;
}

// brute-->

/*vector<pair<int, int>> ans;
int cnt = 0;
for (int i = 0; i < n; i++)
{
    for (int j = i + 1; j < n; j++)
    {
        if (arr[i] > 2 * arr[j])
        {
            ans.emplace_back(arr[i], arr[j]);
            cnt++;
        }
    }
}

if (ans.empty())
    cout << "no pair exist";
else
{
    for (auto it : ans)
    {
        cout << it.first << " " << it.second;
        cout << endl;
    }
    cout << "no of pairs are:" << cnt;
}*/

//
// int Right = M + 1;
// for (int i = L; i <= M; i++)
// {
//     while (Right <= H && arr[i] > 2 * arr[Right])
//     {
//         Right++;
//     }
//     cnt += (Right - (M + 1));
// }