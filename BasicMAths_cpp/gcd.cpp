#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n1, n2;
    cout << "the val of n1:";
    cin >> n1;
    cout << "the val of n2:";
    cin >> n2;
    // int gcd = 1;
    //  for (int i = 1; i <= min(n1, n2); i++)
    //  {
    //      if (n1 % i == 0 && n2 % i == 0)
    //          gcd = i;
    //  }
    //  cout << gcd;
    //  other way-->
    while (n1 > 0 && n2 > 0)
    {
        if (n1 > n2)
            n1 = n1 % n2;
        else
            n2 = n2 % n1;
    }
    if (n1 == 0)
        cout << "the gcd is " << n2;
    else
        cout << "the gcd is :" << n1;

    return 0;
}