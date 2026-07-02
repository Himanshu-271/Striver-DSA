#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << " the value of n:";
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        char ch = 'A';

        for (int j = 1; j <= n - i; j++)
        {
            cout << " ";
        }
        for (int k = 0; k < 2 * i - 1; k++)
        {
            cout << ch;
            if (k < i - 1)
            {
                ch++;
            }
            else
            {
                ch--;
            }
        }

        cout << endl;
    }
    return 0;
}