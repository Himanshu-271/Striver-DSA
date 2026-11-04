#include <bits/stdc++.h>
using namespace std;

static bool cmp(pair<int, int> &a, pair<int, int> &b)
{
    return a.second < b.second;
}

int main()
{
    int n;
    cout << "the val of n:";
    cin >> n;

    vector<pair<int, int>> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].first >> arr[i].second;
    }

    sort(arr.begin(), arr.end(), cmp);

    int cnt = 1;
    int last = arr[0].second;

    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i].first >= last)
        {
            cnt++;
            last = arr[i].second;
        }
    }

    return 0;
}