#include <bits/stdc++.h>
using namespace std;

static bool cmp(pair<int, int> &a, pair<int, int> &b)
{
    return a.first < b.first;
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

    vector<pair<int, int>> newIvl(1);
    cout << "the val of new interval:";
    cin >> newIvl[0].first >> newIvl[0].second;

    // Soln-->

    /*arr.push_back(newIvl[0]);

    sort(arr.begin(), arr.end(), cmp);

    // merging

    vector<pair<int, int>> ans;

    ans.push_back(arr[0]);

    for (auto it = arr.begin() + 1; it != arr.end(); it++)
    {
        if ((*it).first <= ans.back().second)
        {
            ans.back().second = max((*it).second, ans.back().second);
        }

        else
        {
            ans.push_back(*it);
        }
    }

    for (auto it : ans)
    {
        cout << it.first << " " << it.second;
        cout << endl;
    }*/

    // Optimal-->

    bool flag = false;
    vector<pair<int, int>> ans;
    int pos = -1;

    if (arr.empty())
    {
        ans.push_back(newIvl[0]);
        cout << ans[0].first << " " << ans[0].second;
        return 0;
    }

    else
    {
        for (auto it = arr.begin(); it != arr.end(); it++)
        {
            if ((*it).first > newIvl[0].first)
            {
                arr.insert(it, newIvl[0]);
                flag = true;
                break;
            }

            else if ((*it).first == newIvl[0].first)
            {

                if ((*it).second > newIvl[0].second)
                {
                    arr.insert(it, newIvl[0]);
                    flag = true;
                    break;
                }

                else
                {
                    arr.insert(it + 1, newIvl[0]);
                    flag = true;
                    break;
                }
            }
        }

        if (flag == false)
        {
            arr.push_back(newIvl[0]);
        }
    }

    ans.push_back(arr[0]);
    for (auto it = arr.begin() + 1; it != arr.end(); it++)
    {
        if ((*it).first <= ans.back().second)
        {
            ans.back().second = max((*it).second, ans.back().second);
        }

        else
        {
            ans.push_back(*it);
        }
    }

    for (auto it : ans)
    {
        cout << it.first << " " << it.second;
        cout << endl;
    }

    return 0;
}
