#include <bits/stdc++.h>
using namespace std;
// fuctional-->
// int sum(int i, int n)
// {

//     if (i > n)
//         return 0;
//     else
//     {
//         return (i + sum(i + 1, n));
//     }
// }
// parametrize-->
void sum(int i, int total)
{
    if (i < 0)
    {
        cout << total;
        return;
    }
    else
        sum(i - 1, total + i);
}

int main()
{
    int n;
    cout << "the val of n:";
    cin >> n;
    // int total = sum(1, n);
    sum(n, 0);
    // cout << total;
    return 0;
}