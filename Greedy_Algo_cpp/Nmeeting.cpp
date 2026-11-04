#include <bits/stdc++.h>
using namespace std;

static bool cmp(pair<int, int> &a, pair<int, int> &b)
{

    return a.second < b.second;
}

int main()
{
    int n; // n!=0
    cout << "the val of n:";
    cin >> n;

    vector<int> start(n);

    for (int i = 0; i < n; i++)
    {
        cin >> start[i];
    }

    vector<int> end(n);

    for (int i = 0; i < n; i++)
    {
        cin >> end[i];
    }

    vector<pair<int, int>> v;

    for (int i = 0; i < start.size(); i++)
    {
        v.push_back({start[i], end[i]});
    }

    sort(v.begin(), v.end(), cmp);

    int cnt = 1;
    int last = v[0].second;

    for (int i = 1; i < v.size(); i++)
    {
        if (v[i].first > last)
        {
            cnt++;
            last = v[i].second;
        }
    }

    cout << cnt;

    return 0;
}