#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "the val of n:";
    cin >> n;

    vector<int> time(n);

    for (int i = 0; i < n; i++)
    {
        cin >> time[i];
    }

    sort(time.begin(), time.end());

    int ex_time = 0;
    int wait_time = 0;

    for (int i = 0; i < time.size(); i++)
    {
        wait_time += ex_time;
        ex_time += time[i];
    }

    int ans = wait_time / time.size();

    cout << ans;

    return 0;
}