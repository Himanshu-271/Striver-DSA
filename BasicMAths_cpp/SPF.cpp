#include <bits/stdc++.h>
using namespace std;

void SPF(vector<int> &spf)
{

    for (int i = 1; i < spf.size(); i++)
        spf[i] = i;

    for (int i = 2; i * i < spf.size(); i++)
    {
        if (spf[i] == i)
        {
            for (int j = i * i; j < spf.size(); j += i)
            {
                if (spf[j] == j)
                    spf[j] = i;
            }
        }
    }
}

void PrimeFactors(vector<int> &arr, vector<vector<int>> &ans)
{

    vector<int> spf(1e5 + 1, 0);
    SPF(spf);

    for (int i = 0; i < arr.size(); i++)
    {
        vector<int> ls;

        while (arr[i] != 1)
        {
            ls.push_back(spf[arr[i]]);
            arr[i] /= spf[arr[i]];
        }
        ans.push_back(ls);
    }
}

int main()
{
    int query;
    cout << "the val of query:";
    cin >> query;

    vector<int> arr(query);

    for (int i = 0; i < query; i++)
    {
        cin >> arr[i];
    }

    vector<vector<int>> ans;

    PrimeFactors(arr, ans);

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