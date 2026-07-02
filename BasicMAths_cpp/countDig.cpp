#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "the value of n:";
    cin >> n;
    int count = 0;
    while (n > 0)
    {
        // int lastDig=n%10;
        n = n / 10;
        count++;
    }
    cout << count;

    return 0;
}