#include <bits/stdc++.h>
using namespace std;

// two pointer-->

/*pair<int, int> occurence(int arr[], int l, int h, int k)
{
    pair<int, int> ans;
    int flag1 = 0;
    int flag2 = 0;

    while (l <= h)
    {
        if (arr[l] < k && flag1 == 0)
        {
            l++;
            continue; // out of bound prblm arr[l]/arr[h]
        }
        if (arr[h] > k && flag2 == 0)
        {
            h--;
            continue;
        }
        if ((arr[l] == k && flag1 == 0) || (arr[h] == k && flag2 == 0))
        {
            if (l != h)
            {

                if (arr[l] == k && flag1 == 0)
                {
                    ans.first = l;
                    flag1 = 1;
                }
                else
                {
                    ans.second = h;
                    flag2 = 1;
                }
            }

            else
            {
                ans.first = l;
                ans.second = h;
                flag1 = 1;
                flag2 = 1;
            }
        }
        if (flag1 == 1 && flag2 == 1)
        {
            return ans;
            break;
        }
    }
    return {-1, -1};
}*/

// optimal by binary -->

vector<int> find(int arr[], int L, int H, int k)
{
    if (H == -1)
        return {-1, -1};

    int first = -1;
    int last = -1;
    int l = L;
    int h = H;
    vector<int> idx;

    while (L <= H)
    {
        int mid = (L + H) / 2;
        if (arr[mid] > k)
        {
            H = mid - 1;
        }
        else if (arr[mid] < k)
        {
            L = mid + 1;
        }
        else
        {
            first = mid;
            H = mid - 1;
        }
    }
    idx.push_back(first);

    while (l <= h)
    {
        int mid = (l + h) / 2;

        if (arr[mid] > k)
        {
            h = mid - 1;
        }
        else if (arr[mid] < k)
        {
            l = mid + 1;
        }
        else
        {
            last = mid;
            l = mid + 1;
        }
    }
    idx.push_back(last);

    return idx;
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

    // pair<int, int> ans = occurence(arr, 0, n - 1, k);
    //  cout << ans.first << " " << ans.second;

    vector<int> ans = find(arr, 0, n - 1, k);

    cout << "first occ:" << ans[0] << endl;
    cout << "last occ:" << ans[1];

    return 0;
}