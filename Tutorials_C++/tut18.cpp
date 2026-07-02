#include <iostream>
using namespace std;
// int fact(int x)
// {
//     if (x <= 1)
//         return 1;
//     return fact(x - 1) * x;
// }
long long int fibo(int);
int main()
{
    int n; // n >= 0;
    cin >> n;
    // int ans = fact(n);
    // cout << "the factorial of " << n << " is:" << endl
    //      << ans;

    // fibonaci series

    long long int ans = fibo(n);
    cout << "the " << n << " fibo no is:" << ans;

    return 0;
}
long long int fibo(int x)
{
    if (x == 0)
        return 0;
    if (x == 1)
        return 1;

    return fibo(x - 1) + fibo(x - 2);
}
