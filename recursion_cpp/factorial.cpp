#include <bits/stdc++.h>
using namespace std;
// parametrize-->
void factorial(int n, int fact)
{
    if (n == 0)
    {
        cout << fact;
        return;
    }
    else
        factorial(n - 1, n * fact);
}
int main()
{
    int n;
    cout << "the val of n:";
    cin >> n;
    factorial(n, 1);
    return 0;
}