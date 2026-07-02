#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "the pairs n:";
    cin >> n;
    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].first >> arr[i].second;
    }

    // brute -->

    sort(arr.begin(), arr.end());
    vector<pair<int, int>> ans;
    if (n == 0)
        return {};
    ans.push_back(arr[0]);
    for (auto it = arr.begin() + 1; it != arr.end(); it++)
    {

        if ((*it).first <= ans.back().second)
        {
            // ans.push_back({(*it).first, max((*it).first, (*(it + 1)).second)});
            ans.back().second = max((*it).second, ans.back().second);
        }
        else
            ans.push_back(*it);
    }

    for (auto it : ans)
    {
        cout << it.first << " " << it.second;
        cout << endl;
    }
    return 0;
}