#include <bits/stdc++.h>
using namespace std;

void Permutation(vector<int> &arr, vector<vector<int>> &ans, vector<int> &ls, vector<int> &vis)
{

    if (ls.size() == arr.size())
    {
        ans.push_back(ls);
        return;
    }

    for (int i = 0; i < arr.size(); i++)
    {
        if (vis[i] == 0)
        {
            ls.push_back(arr[i]);
            vis[i] = 1;

            Permutation(arr, ans, ls, vis);
            vis[i] = 0;
            ls.pop_back();
        }
    }
}

void Permutation2(int idx, vector<int> &arr, vector<vector<int>> &ans)
{

    if (idx >= arr.size())
    {
        ans.push_back(arr);
        return;
    }

    for (int i = idx; i < arr.size(); i++)
    {
        swap(arr[idx], arr[i]);
        Permutation2(idx + 1, arr, ans);
        swap(arr[idx], arr[i]);
    }
}

int main()
{

    int n;
    cout << "the val of n:";
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << endl;

    //  visited array approch-->

    /*
    vector<vector<int>> ans;
    vector<int> ls;
    vector<int> vis(arr.size());

    Permutation(arr, ans, ls, vis);

    for (auto it : ans)
    {
        for (auto x : it)
            cout << x << " ";
        cout << endl;
    }
        */

    // Approach 2 swaping--->

    vector<vector<int>> ans;

    Permutation2(0, arr, ans);

    for (auto it : ans)
    {
        for (auto x : it)
            cout << x << " ";
        cout << endl;
    }

    return 0;
}