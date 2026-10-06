#include <bits/stdc++.h>
using namespace std;

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

    int subsets = 1 << n;

    vector<vector<int>> ans;

    for (int i = 0; i < subsets; i++)
    {
        vector<int> ls;
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
                ls.push_back(arr[j]);
        }
        ans.push_back(ls);
    }

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