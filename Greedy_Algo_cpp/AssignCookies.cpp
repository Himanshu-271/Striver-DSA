#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "the val of n:";
    cin >> n;

    vector<int> greed(n);

    for (int i = 0; i < n; i++)
    {
        cin >> greed[i];
    }

    int m;
    cout << "the val of m:";
    cin >> m;

    vector<int> size(m);

    for (int i = 0; i < m; i++)
    {
        cin >> size[i];
    }

    sort(greed.begin(), greed.end());
    sort(size.begin(), size.end());

    int l = 0;
    int r = 0;

    int ans = 0;

    while (l < size.size() && r < greed.size())
    {

        if (greed[r] <= size[l])
        {
            ans++;
            l++;
            r++;
        }

        else
            l++;
    }

    cout << ans;

    return 0;
}