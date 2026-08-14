#include <bits/stdc++.h>
using namespace std;

void SubsetSum2(int idx, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ls)
{

    ans.push_back(ls);

    for (int i = idx; i < arr.size(); i++)
    {
        if (i != idx && arr[i] == arr[i - 1])
            continue;
        ;
        ls.push_back(arr[i]);
        SubsetSum2(i + 1, arr, ans, ls);
        ls.pop_back();
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

    sort(arr.begin(), arr.end());

    vector<vector<int>> ans;
    vector<int> ls;

    SubsetSum2(0, arr, ans, ls);

    for (auto it : ans)
    {
        for (auto x : it)
        {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}