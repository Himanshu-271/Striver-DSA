#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "the val of n;";
    cin >> n;
    int count = 0;
    vector<int> ls;
    // for (int i = 1; i <= n; i++)
    // {
    //     if (n % i == 0)
    //     {
    //         count++;
    //         cout << i << endl;
    //     }
    // }

    // better time complexicty--->
    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            ls.push_back(i);
            count++;
            if (n / i != i)
                ls.push_back(n / i);
            count++;
        }
    }
    sort(ls.begin(), ls.end());
    for (auto it : ls)
    {
        cout << it << endl;
    }

    cout << "the  no of divisor is:" << count;
    return 0;
}