#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    cout << " the value of n:";
    cin >> n;
    int space = 2 * (n - 1);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << j;
        }
        for (int k = 0; k < space; k++)
        {
            cout << " ";
        }
        for (int j = i; j > 0; j--)
        {
            cout << j;
        }
        space = space - 2;
        cout << endl;
    }

    return 0;
}