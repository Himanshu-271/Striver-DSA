#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "the value of n:";
    cin >> n;
    int count = 0;

    // brute -->

    /* for (int i = 1; i * i <= n; i++)
     {
         if (n % i == 0)
         {
             count++;
             if (n / i != i)
                 count++;
         }
     }
     if (count == 2)
         cout << "prime no";
     else
         cout << "not a prime no";
         */

    // optimal -->

    //  Sieve of Eratosthenes --->

    // no of primes <=n -->

    vector<int> prime(n + 1);

    for (int i = 2; i < n + 1; i++)
    {
        prime[i] = 1;
    }

    for (int i = 2; i * i <= n; i++)
    {
        if (prime[i] == 1)
        {
            for (int j = i * i; j <= n; j += i)
            {
                prime[j] = 0;
            }
        }
    }

    for (int i = 2; i < n + 1; i++)
    {
        if (prime[i] == 1)
            cout << i << " ";
    }

    return 0;
}