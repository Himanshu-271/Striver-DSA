#include <bits/stdc++.h>
using namespace std;

int XOR_range(int n)
{
    if (n % 4 == 1)
        return 1;
    else if (n % 4 == 2)
        return n + 1;
    else if (n % 4 == 3)
        return 0;
    else
        return n;
}

int main()
{
    int n;
    cout << "the val of n:";
    cin >> n;

    int m;
    cout << "the val of m:";
    cin >> m;

    // m<n

    //   brute -->

    /*int xr = 0;

    for (int i = 0; i <= n; i++)
    {
        xr ^= i;
    }

    cout << xr;*/

    // Pattern obs -->

    // find XOR in rnage 1 to N in TC O(1)

    // int ans = XOR_range(n);

    // cout << ans;

    // Find Xor in range [m,n] -->

    // idea use Xor fxn range 1 to n --.
    // xor(m-1)^xor(n) = xor([m,n]);

    int ans = XOR_range(m - 1) ^ XOR_range(n);

    cout << ans;
    return 0;
}