#include <bits/stdc++.h>
using namespace std;

vector<int> genrateRow(int row)
{
    long long ans = 1;
    vector<int> ansRow;
    ansRow.push_back(1);
    for (int i = 1; i < row; i++)
    {
        ans = ans * (row - i);
        ans = ans / i;
        ansRow.push_back(ans);
    }
    return ansRow;
}

long long int mul(int x, int y)
{
    long long ans = 1;
    for (int i = x; i > (x - y); i--)
    {
        ans = ans * i;
    }
    return ans;
}

long long int combinitorial(int n, int r)
{
    long long a = mul(n, r);
    long long b = mul(r, r);
    long long ncr = a / b;

    return ncr;
}
int main()
{
    int n, r;
    cout << "the val of n:";
    cin >> n;
    // cout << "the val of r:";
    // cin >> r;
    // int ans;
    // if (n > r)
    //     ans = combinitorial(n, r);
    // else
    //     cout << "not possible";

    //  cout << ans;

    // pascal tri --.

    // brute --->

    /*    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            cout << " ";
        }
        for (int k = 0; k <= i; k++)
        {
            cout << combinitorial(i, k) << " ";
        }
        cout << endl;
    }
        */

    // optimal soln -->

    vector<vector<int>> ans;
    for (int i = 1; i <= n; i++)
    {

        ans.push_back(genrateRow(i));
    }

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }

        cout << endl;
    }

    return 0;
}