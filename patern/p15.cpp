#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    cout << " the value of n:";
    cin >> n;
    for (int i = n; i > 0; i--)
    {
        for (char ch = 'A'; ch <= 'A' + i; ch++)
        {
            cout << ch;
        }
        cout << endl;
    }
    return 0;
}