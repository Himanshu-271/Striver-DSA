#include <bits/stdc++.h>
using namespace std;

int DivisonFxn(int n, int m)
{

    if (n == m)
        return 1;

    int sign = 1;
    if ((n >= 0 && m < 0) || (n < 0 && m > 0))
        sign = -1;

    long long x = abs((long long)n);
    long long y = abs((long long)(m));

    long long ans = 0;

    while (x >= y)
    {
        int cnt = 0;

        while (x >= (1LL * y << (cnt + 1)))
        {
            cnt++;
        }

        x -= (1LL * y * (1 << cnt));
        ans += (1LL * 1 << cnt);
    }

    if (ans >= (1LL << 31) && sign == 1)
        return INT_MAX;
    else if (ans >= (1LL << 31) && sign == -1)
        return INT_MIN;

    else
        return sign * (int)ans;
}

int main()
{
    int n;
    cout << "the val of n -divident:";
    cin >> n;

    int m;
    cout << "the val of m -divisor:";
    cin >> m;

    int ans = 1;

    if (m != 0)
    {
        ans = DivisonFxn(n, m);
        cout << ans;
    }

    else
        cout << "no possible divison";

    return 0;
}