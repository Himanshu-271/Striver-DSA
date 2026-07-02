#include <bits/stdc++.h>
using namespace std;
int fibo(int n)
{
    if (n == 0)
        return 0;
    if (n == 1 || n == 2)
        return 1;
    else
        return fibo(n - 2) + fibo(n - 1);
}
int main()
{
    int n;
    cout << "the val of n :";
    cin >> n;
    int ans = fibo(n);
    cout << ans;
    return 0;
}