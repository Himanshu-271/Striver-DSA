#include <bits/stdc++.h>
using namespace std;

bool checkPrime(int x)
{
    int count = 0;
    for (int i = 1; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            count++;
            if (x / i != i)
                count++;
        }
    }

    if (count != 2)
        return false;
    else
        return true;
}

int main()
{
    int n;
    cout << "the no is :";
    cin >> n;

    // brute--->

    /* vector<int> ls;

     for (int i = 1; i <= sqrt(n); i++)
     {
         if (n % i == 0)
         {
             ls.push_back(i);

             if (n / i != i)
                 ls.push_back(n / i);
         }
     }

     vector<int> ans;

     for (int i = 0; i < ls.size(); i++)
     {
         if (checkPrime(ls[i]))
             ans.push_back(ls[i]);
     }

     for (auto it : ans)
     {
         cout << it << " ";
     }*/

    //  Better --->

    vector<int> ls;

    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            ls.push_back(i);
            // assign that only prime factor come -->
            while (n % i == 0)
            {
                n /= i;
            }
        }
    }

    // check prime no or not -->
    if (n != 1)
        ls.push_back(n);

    return 0;
}