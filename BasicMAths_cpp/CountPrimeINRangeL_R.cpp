#include <bits/stdc++.h>
using namespace std;

void SOE(vector<int> &ls, int n)
{
    for (int i = 2; i * i <= n; i++)
    {
        if (ls[i] == 1)
        {
            for (int j = i * i; j <= n; j += i)
            {
                ls[j] = 0;
            }
        }
    }
}

int main()
{

    int query;
    cout << "the val of query:";
    cin >> query;

    vector<pair<int, int>> arr;

    for (int i = 0; i < query; i++)
    {
        int l, r;
        cin >> l >> r;
        arr.push_back({l, r});
    }

    vector<int> ans;

    for (int i = 0; i < arr.size(); i++)
    {
        int cnt = 0;

        vector<int> ls(arr[i].second + 1, 1);
        ls[0] = 0;
        ls[1] = 0;

        SOE(ls, arr[i].second);

        int sum = 0;

        for (int k = 0; k < ls.size(); k++)
        {
            sum += ls[k];
            ls[k] = sum;
        }

        cnt += (ls[arr[i].second] - ls[arr[i].first - 1]);

        ans.push_back(cnt);
    }

    for (auto it : ans)
    {
        cout << it << endl;
    }

    return 0;
}