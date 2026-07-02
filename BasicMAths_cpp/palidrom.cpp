#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "the val of n:";
    cin >> n;
    int count = 0;
    int rev = 0;
    int M = n;

    while (n > 0)
    {
        int rem = n % 10;
        n = n / 10;

        rev = rev * 10 + rem;
    }
    if (rev == M)
        cout << "Palidrom";
    else
        cout << "not a palidrom";

    return 0;
}