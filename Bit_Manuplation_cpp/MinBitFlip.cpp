#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "the val of n:";
    cin >> n;

    int m;
    cout << "the val of m:";
    cin >> m;

    // Brute--->

    /*vector<int> bitn(32);
    vector<int> bitm(32);

    int idx1 = 0;
    int idx2 = 0;

    while (n > 0)
    {
        bitn[idx1++] = n % 2;
        n /= 2;
    }

    while (m > 0)
    {
        bitm[idx2++] = m % 2;
        m /= 2;
    }

    int xr = 0;
    vector<int> ans;

    for (int i = 0; i < 31; i++)
    {
        xr = bitn[i] ^ bitm[i];
        ans.push_back(xr);
    }

    int cnt = 0;

    for (int i = 0; i < ans.size(); i++)
    {
        if (ans[i] == 1)
            cnt++;
    }

    cout << cnt;*/

    // optimal-->

    int ans = n ^ m;
    int cnt = 0;

    while (ans != 0)
    {
        ans = ans & (ans - 1);
        cnt++;
    }

    cout << cnt;

    return 0;
}
