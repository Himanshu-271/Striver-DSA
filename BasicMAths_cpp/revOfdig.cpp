#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "the val of n;";
    cin >> n;
    int rev = 0;
    while (n > 0)
    {
        int rem = n % 10;
        // if (rem > 0)
        //     cout << rem;

        // OR
        n = n / 10;

        if (rem > 0)
        {
            rev = rev * 10 + rem;
        }
    }
    cout << rev;
    return 0;
}