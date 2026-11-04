#include <bits/stdc++.h>
using namespace std;

static bool cmp(pair<int, pair<int, int>> &a, pair<int, pair<int, int>> &b)
{

    return a.second.second > b.second.second;
}

int main()
{

    int n;
    cout << "the val of n:";
    cin >> n;

    vector<pair<int, pair<int, int>>> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].first >> arr[i].second.first >> arr[i].second.second;
    }

    sort(arr.begin(), arr.end(), cmp);

    auto it = max_element(arr.begin(), arr.end(),
                          [](auto &a, auto &b)
                          {
                              return a.second.first < b.second.first;
                          });

    int m = it->second.first;

    vector<int> deadline(m + 1, -1);

    int profit = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = arr[i].second.first; j >= 1; j--)
        {
            if (deadline[j] == -1)
            {
                deadline[j] = arr[i].first;
                profit += arr[i].second.second;
                break;
            }
        }
    }

    cout << profit;

    return 0;
}