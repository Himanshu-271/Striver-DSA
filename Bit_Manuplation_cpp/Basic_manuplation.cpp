#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "the vsl of n:";
    cin >> n;

    vector<int> ans;

    // bits conversion-->

    while (n > 0)
    {
        ans.push_back(n % 2);
        n /= 2;
    }

    reverse(ans.begin(), ans.end());

    // STL-->

    bitset<32> b(n);
    cout << b;

    // BInary to decimal
    int no = -1;
    int p2 = 1;

    for (int i = ans.size() - 1; i >= 0; i--)
    {
        if (ans[i] == 1)
            no += p2;
        p2 *= 2;
    }

    return 0;
}