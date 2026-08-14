#include <bits/stdc++.h>
using namespace std;

void CombinationSum2(int idx, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ls, int k)
{

    // brute--->

    /*if (idx >= arr.size())
    {
        if (k == 0)
        {
            sort(ls.begin(), ls.end());

            st.insert(ls);
        }
        return;
    }

    if (arr[idx] <= k)
    {
        ls.push_back(arr[idx]);
        CombinationSum2(idx + 1, arr, st, ls, k - arr[idx]);
        ls.pop_back();
    }

    CombinationSum2(idx + 1, arr, st, ls, k);*/

    // otimal--->

    if (k == 0)
    {
        ans.push_back(ls);
        return;
    }

    for (int i = idx; i < arr.size(); i++)
    {
        if (i > idx && arr[i] == arr[i - 1])
            continue;
        if (arr[i] > k)
            break;

        ls.push_back(arr[i]);
        CombinationSum2(i + 1, arr, ans, ls, k - arr[i]);
        ls.pop_back();
    }
}

int main()
{
    int k;
    cout << "the val of k:";
    cin >> k;

    int n;
    cout << "the val of n:";
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    // set<vector<int>> st;
    vector<vector<int>> ans;

    vector<int> ls;

    CombinationSum2(0, arr, ans, ls, k);

    if (ans.empty())
        cout << "no combinations";

    else
    {
        for (auto it : ans)
        {
            for (auto x : it)
                cout << x << " ";
            cout << endl;
        }
    }
    return 0;
}