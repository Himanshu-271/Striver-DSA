#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "the val of n:";
    cin >> n;

    vector<int> arival(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arival[i];
    }

    vector<int> dep(n);

    for (int i = 0; i < n; i++)
    {
        cin >> dep[i];
    }

    // optimal soln

    vector<pair<int, char>> arv;

    sort(arival.begin(), arival.end());

    for (int i = 0; i < n; i++)
    {
        arv.push_back({arival[i], 'A'});
    }

    sort(dep.begin(), dep.end());
    vector<pair<int, char>> dept;

    for (int i = 0; i < n; i++)
    {
        dept.push_back({dep[i], 'D'});
    }

    int l = 0;
    int r = 0;
    int max_cnt = 0;
    int cnt = 0;

    while (l < n && r < n)
    {
        if (arv[l].first <= dept[r].first)
        {
            cnt++;
            max_cnt = max(max_cnt, cnt);
            l++;
        }

        else
        {
            cnt--;
            r++;
        }
    }

    while (l < n)
    {
        cnt++;
        l++;
    }

    while (r < n)
    {
        cnt--;
        r++;
    }

    max_cnt = max(cnt, max_cnt);

    cout << max_cnt;

    return 0;
}