#include <bits/stdc++.h>
using namespace std;

static bool cmp(pair<int, int> &a, pair<int, int> &b)
{

    return ((double)a.first / a.second) > ((double)b.first / b.second);
}

int main()
{

    int weight;
    cout << "the val of max weight:";
    cin >> weight;

    int n;
    cout << "the val of n:";
    cin >> n;

    vector<pair<int, int>> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].first >> arr[i].second;
    }

    sort(arr.begin(), arr.end(), cmp);

    vector<double> ans;

    for (int i = 0; i < n; i++)
    {
        if (arr[i].second <= weight)
            ans.push_back(arr[i].first);

        else
        {
            double x = ((double)arr[i].first / arr[i].second) * weight;

            ans.push_back(x);

            break;
        }

        weight -= arr[i].second;
    }

    double total_val = accumulate(ans.begin(), ans.end(), 0.0);

    cout << total_val;

    return 0;
}