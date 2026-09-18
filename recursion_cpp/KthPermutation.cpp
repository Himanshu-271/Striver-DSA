#include <bits/stdc++.h>
using namespace std;

int main()
{
    int k;
    cout << "the val of k:";
    cin >> k;

    int n;
    cout << "the val of n:";
    cin >> n;

    vector<int> arr;
    int fact = 1;

    for (int i = 1; i < n; i++)
    {
        arr.push_back(i);
        fact = fact * i;
    }

    arr.push_back(n);

    string ans = "";
    k -= 1;

    while (1)
    {

        ans = ans + to_string(arr[k / fact]);
        arr.erase(arr.begin() + k / fact);

        if (arr.empty())
            break;

        k = k % fact;
        fact /= arr.size();
    }

    cout << ans;

    return 0;
}