#include <bits/stdc++.h>
using namespace std;

void Power(long long x, int y, long long &ans)
{

    if (y == 0)
        return;

    else if (y % 2 == 0)
    {
        return Power(x * x, y / 2, ans);
    }

    else
    {
        ans *= x;
        return Power(x, y - 1, ans);
    }
}

int main()
{
    int n;
    cout << "the val of n:";
    cin >> n;

    int y;
    cout << "the val of y:";
    cin >> y;

    // STL FXN-->

    // long long ans = pow(n, y);

    // cout << ans;

    // optimal--->
    long long ans = 1;
    Power(n, y, ans);

    cout << ans;
    return 0;
}